#include <stdio.h>
#include <KPP/TokMgr.h>

#define _testfname "TOKMGRTEST"
#define _okval 8

int main() {
    #if KPP_TOKC >= _okval
    KPP_TokMgr tok;
    FILE* a = fopen(_testfname, "r");
    if(!a) return 1;

    int c = KPP_TokMgrInit(&tok, a);
    if(c) {
        printf("KPP_TokMgrInit failed %d\n", c);
        return 2;
    }

    for(size_t i = 0; i < _okval; i++) {
        puts(tok.tokv[i]);
    }

    if(tok.tokc != _okval) {
        printf("tok.tokc is not okay %d\n", tok.tokc);
        return 3;
    }

    fclose(a);
    #else
    /** This test went to be ridiculous */
    int c = 0;
    #endif
    return c;
}