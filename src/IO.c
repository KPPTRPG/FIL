#include <FIL/IO.h>

ae2f_SHAREDEXPORT char* fgets_space(char* buff, int num, FILE* stream) {
    int ch, i = 0;

    while(1) {
        switch((ch = fgetc(stream))) {
            case EOF: return 0;
            default: goto beg;
            case ' ': case '\n':
        }
    }
    beg:

    if(i < num - 1)
    buff[i++] = ch;

    while(i < num - 1 && (ch = fgetc(stream)) != EOF) {
        
        switch(ch) {
            case ' ': case '\n':
            goto out;
            default: break;    
        }

        buff[i++] = ch;
    }

    out:
    buff[i] = '\0';
    if(i == 0 && ch == EOF)
    return 0;


    return buff;
}