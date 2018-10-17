// Static Functions
static char* currTime(const char *format) { // non-reentrant
    // Get Time
    std::time_t t = std::time(NULL);
    tm *tm        = std::localtime(&t);
    if(!tm)
        return NULL;
    
    // Format Time
    static char buf[BUF_SIZE];
    std::size_t s = std::strftime(buf, BUF_SIZE, format ? format : "%c", tm);

    return !s ? NULL : buf;
}

/* std::cout is non-reentrant, so this function is alos non-reentrant,
 * should not be used in a signal handler (non-async-signal-safe) */
static void printWaitStatus(const std::string *const msg, const int status) {
    // Print Optional Message
    if(msg)
        std::cout << msg;

    // Child Exited Normally, Probe Exit Status(lower 8 byts(0-255))
    if(WIFEXITED(status))
        std::cout << "\nChild Exited: Status: " << WEXITSTATUS(status);
    // Child Killed By A Signal, Probe Exit Signal Number And Core Dump
    else if(WIFSIGNALED(status)) {
        std::cout << "\nChild Killed: Signal: " << WTERMSIG(status)
                  << " (" << strsignal(WTERMSIG(status)) << ')';
        
        /* Not in SUSv3, may be absent on some systems */
        #ifdef WCOREDUMP
        if(WCOREDUMP(status))
            std::cout << " (core dumped)";
        #endif
    }
    // Child Stopped By A Signal, Probe Stop Signal Number
    else if(WIFSTOPPED(status))
        std::cout << "\nChild Stopped: Signal: " << WSTOPSIG(status)
                  << " (" <<  strsignal(WSTOPSIG(status)) << ')';
    // Child Continued By A Signal
    /* SUSv3 has this, but older Linux versions and some other UNIX implementations don't */   
    #ifdef WIFCONTINUED 
    else if(WIFCONTINUED(status))
        std::cout << "\nChild Continued: Signal: (" << strsignal(SIGCONT) << ')';
    #endif
    // Shouldn't Get Here
    else
        std::cout << "\nChild Is Missing? (status: " << (unsigned)status << ')';
}
