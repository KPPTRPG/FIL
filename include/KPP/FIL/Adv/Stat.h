#ifndef FIL_Adv_Stat_h
#define FIL_Adv_Stat_h

#include <stdint.h>
#include <KPP/InitWithArgs.h>
#include <stdio.h>

typedef struct FIL_AdvStat {
	uint32_t 
		LP, SP, 
		STR, AGI, 
		CON, INT, 
		LNK[3], G;
} FIL_AdvStat;


KPP_InitFuncDef(FIL_AdvStat);

ae2f_extern ae2f_SHAREDCALL
void FIL_AdvStatPrt(
	const FIL_AdvStat* adv
	,FILE* ostream
);

#endif
