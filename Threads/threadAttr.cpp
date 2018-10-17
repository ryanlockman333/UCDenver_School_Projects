pthread_t thr;
pthread_attr_t attr;
int s;

if((s = pthread_attr_init(&attr)))
    errExitEN(s, "pthread_attr_init");

if((s = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED)))
    errExitEN(s, "pthread_attr_setdetachstate");

if((s = pthread_create(&thr, &attr, threadFunc, (void*)1)))
    errExitEN(s, "pthread_create");

if((s = pthread_attr_destroy(&attr))) // no longer needed
    errExitEN(s, "pthread_attr_destroy");

