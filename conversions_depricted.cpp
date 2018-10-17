int main() {
    char *dprctd1          =       "Hello1";
    char *dprctd2          =(char*)"Hello2";
    char const*const& s1   =       "Hello3";
    char const*const  s2   =       "Hello4";
    char const*       s3   =       "Hello5";
    char const        s4[] =       "Hello6";    // 1d-array, same as const *s4
    char const*       s5   =        s4+1;       // const * to base+1 
    char const        s6   =        *(s4+1);    // const to data at base+1
    char const*       s7   =        &(*(s4+1)); // const * to referenced data at base+1
    char const        s8   =        *s4;        // const to referenced data at base
    char const*       s9   =        &(*s4);
    char (*s10)[10];                            // 2d-array, same as s10[][], array of 10 *'s,
                                                //  not a * to an array of 10 ints (explicit)
    char *s11[10];                              // same as **s11, a * to an array of 10 ints (implicit)
    **s11       = 'H';
      s11[1][1] = 'E';
    
    char s12[10][10];                           // 2d-array (implicit)
    **s12 = **s11;

    char **s13;                                 // a * to an array of ints (explicit)
    
    char const*const*const s14 = &s1;           
    char const*const*const*const& s15 = 0;      // const * to a const * to a const * reference
    char const*const*const*const (*s17)[10];    // const * to a const * to a const * of a array of 10 *'s
}

