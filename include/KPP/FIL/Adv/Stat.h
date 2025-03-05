#ifndef FIL_Adv_Stat_h
#define FIL_Adv_Stat_h

#include <stdint.h>
#include <KPP/InitWithArgs.h>

typedef struct FIL_AdvStat {
	uint32_t 
		LP, SP, 
		STR, AGI, 
		CON, INT, 
		LNK[3], G;
} FIL_AdvStat;


KPP_InitFuncDef(FIL_AdvStat);

#endif
