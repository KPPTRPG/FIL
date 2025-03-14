#include <stdio.h>
#include <string.h>
/** @brief Count limit for token vector. */
#define COUNT_TOK 64


/** @brief Byte-length limit for primitive memory. */
#define LEN_TOKMEM 1024


typedef struct TokMgr {
    /** @todo It must be string on initialised in every situation. */
    char mem[LEN_TOKMEM];

    /** @todo It must be a length for @ref tokv */
    int tokc;
    const char* tokv[COUNT_TOK];
} TokMgr;


void StringFlag(char* str, int flag, size_t size) {
    if (flag == 0) {
        int flag = 0;
        for (int i = 0; i < size; i++) {
            if (str[i] == '"' && flag == 0) {
                flag = 1;
            }
            else if (str[i] == '"' && flag == 1) {
                flag = 0;
            }
            if (flag == 1) {
                if (str[i] == ' ') {
                    str[i] = '_';
                }
            }
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            if (str[i] == '_') {
                str[i] = ' ';
            }
        }
    }
}

void TokMgrInit(TokMgr* mgr, const char* orig) {
    int i = 0;
    strcpy(mgr->mem, orig);
    int size = strlen(mgr->mem);
    StringFlag(mgr->mem, 0, size);
    for (char* p = strtok(mgr->mem, " "); p != NULL; p = strtok(NULL, " ")) {
        mgr->tokv[i] = p;
        if (mgr->tokv[i][0] == '"') {
            mgr->tokv[i]++;
        }
        i++;
    }
    StringFlag(mgr->mem, 1, size);
    mgr->tokc = i;
    {
        int flag = 0;
        for (int i = 0; i < sizeof(mgr->mem); i++) {
            if (mgr->mem[i] == '"' && !flag) {
                
                flag = 1;
            }
            else if (mgr->mem[i] == '"' && flag) {
                mgr->mem[i] = '\0';
                flag = 0;
            }
        }
    }
}

int main() {
    TokMgr mgr;
    TokMgrInit(&mgr, "Hello \"non_hello\" 3");
    printf("%d\n", mgr.tokc);

    for(int i = 0; i < mgr.tokc; i++)
    puts(mgr.tokv[i]);
    return 0;
}