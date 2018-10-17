// Macro
#ifndef STRERR_SAFE_H
#define STRERR_SAFE_H

// Feature Test Macro
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

// Headers
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <pthread.h>

// Static Globals
static pthread_once_t once = PTHREAD_ONCE_INIT; // conditon variable
static pthread_key_t strerrorKey;               // thread specific key allocated by pthread_key_create

#define MAX_ERROR_LEN 256                       // max error len

// Destructor for Per Thread Dynamic Buffer
static void destructor(void *buf) { std::free(buf); }

// Key Creation Function to Associate Thread to Unique Key
static void createKey() {
    // Update Global Array With In-Use Flag and Destructor
    int s = pthread_key_create(&strerrorKey, destructor);
    if(s) {
        errno = s;
        std::perror("pthread_key_create");
        exit(EXIT_FAILURE);
    }
}

// Function Prototype/Implementation sterror
char* strerror(const int err) {
    // Create Function Once Per Thread, Associating Key and Condition
    int s = pthread_once(&once, createKey);
    if(s) {
        errno = s;
        std::perror("pthread_once");
        return NULL;
    }

    // Get thread-specific Buffer, if NULL(first time thread call) Set Key
    char *buf = (char*)pthread_getspecific(strerrorKey);
    if(!buf) { // First Time
        // Dynamically Allocate thread-specific-data Buffer
        if(!(buf = (char*)std::malloc(MAX_ERROR_LEN))) {
            std::perror("malloc");
            return NULL;
        }
        
        // Add Buffer to thread-specific Array of Pointers to Buffer
        if((s = pthread_setspecific(strerrorKey, buf))) {
            errno = s;
            std::perror("pthread_setspecific");
            return NULL;
        }
    }
      
    // Check Args and Fill Return Buffer With Error String
    if(err < 0 || err >= _sys_nerr || !_sys_errlist[err])
        std::snprintf(buf, MAX_ERROR_LEN, "Unknown error %d", err);
    else {
        std::strncpy(buf, _sys_errlist[err], MAX_ERROR_LEN-1);
        buf[MAX_ERROR_LEN-1] = '\0';
    }
   
    // Return Buffer
    return buf;
}
#endif

