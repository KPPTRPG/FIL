#include <stdio.h>
#include <KPP/FIL/Adv.h>
#include <KPP/TokMgr.h>
#include <KPP/Log.h>

int main(int argc, const char** argv) {
	for(int i = 1; i < argc; i++) {
		KPP_printf("%s\n", argv[i]);
	}

	FIL_Adv adv[1] = {0, };

	if(argc > 1) {
		FIL_AdvInit(adv, argc - 1, argv + 1);
	} else {
		KPP_TokMgr toks[1];
		KPP_TokMgrInit(toks, stdin);

		KPP_puts("Test TOKS\n");
		for(int i = 0; i < toks->tokc; i++) {
			KPP_printf("Token %d: %s\n", i, toks->tokv[i]);
		}

		FIL_AdvInit(adv, toks->tokc, toks->tokv);
	}

	FIL_AdvPrt(adv, stdout);
	return 0;
}