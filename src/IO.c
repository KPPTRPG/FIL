#include <FIL/IO.h>

static bool fgets_termedcapture(int v, const char* t, size_t termc) {
    for(size_t i = 0; i < termc; i++) {
        if (t[i] == v) return 1;
    } return 0;
}

ae2f_SHAREDEXPORT char* fgets_termed(char* buff, int num, const char* _term, size_t _termc, FILE* stream) {
    int ch, i = 0;

    while(1) {
        switch((ch = fgetc(stream))) {
            case EOF: return 0;
            default:
            if(!fgets_termedcapture(ch, _term, _termc))
            goto beg;
            break;
        }
    }

    beg:

    if(i < num - 1)
    buff[i++] = ch;

    while(i < num - 1 && (ch = fgetc(stream)) != EOF) {
        if(ch == fgets_termedcapture(ch, _term, _termc))
        goto out;
        buff[i++] = ch;
    }

    out:
    buff[i] = '\0';
    if(i == 0 && ch == EOF)
    return 0;

    return buff;
}

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