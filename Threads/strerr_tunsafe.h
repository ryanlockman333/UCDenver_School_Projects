#ifndef STRERR_TUNSAFE_H
#define STRERR_TUNSAFE_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE //for _sys_nerr and _sys_errlist
#endif

#include <cstdlib>
#include <cstdio>
#include <cstring>

const unsigned MAX_ERROR_LEN = 256; //  maximum len of str returned by strerror()

static char buf[MAX_ERROR_LEN];     // statically allocated return buffer

char *strerror(const int err) {
    if(err < 0 || err >= _sys_nerr || !_sys_errlist[err])
        std::snprintf(buf, MAX_ERROR_LEN, "Unknown Error %d", err);
    else {
        std::strncpy(buf, _sys_errlist[err], MAX_ERROR_LEN-1);
        buf[MAX_ERROR_LEN-1] = '\0'; // ensure null terminated
    }
    return buf;
}
#endif

