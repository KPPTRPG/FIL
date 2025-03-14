#ifndef FIL_Adv_h
#define FIL_Adv_h

#include "Glob.h"
#include "Bias.h"
#include "Adv/Brood.h"
#include "Adv/Info.h"
#include "Adv/Stat.h"

typedef struct FIL_Adv {
	FIL_AdvInfo Info;
	FIL_AdvStat Stat;
} FIL_Adv;

#include <KPP/InitWithArgs.h>

KPP_InitFuncDef(FIL_Adv);

#include <ae2f/errGlob.h>
#include <stdio.h>

/**
 * 
 * Imp Done.
 * */
ae2f_extern ae2f_SHAREDCALL
void FIL_AdvPrt(
		const FIL_Adv* adv
		, FILE* ostream
		);

typedef struct FIL_AdvJsonQuery {
	/** @brief The index to chose a LNK for vector */
	uint8_t LinkIndex;

	/** @brief The ATK, DEF */
	uint8_t ATK, DEF;
} FIL_AdvJsonQuery;


ae2f_extern ae2f_SHAREDCALL
size_t FIL_AdvJsonQueryMk(
		FIL_AdvJsonQuery* query
		, int argc
		, const char** argv
		);

ae2f_extern ae2f_SHAREDCALL
void FIL_AdvJson(
		const FIL_Adv* adv
		, FILE* ostream
		, FIL_AdvJsonQuery* q
		);

ae2f_extern ae2f_SHAREDCALL
void FIL_AdvJsonQueryPrt(
		const FIL_AdvJsonQuery* query
		, FILE* ostream
		);

#endif
