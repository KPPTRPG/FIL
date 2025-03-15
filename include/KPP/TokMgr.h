#ifndef KPP_TokMgr_h
#define KPP_TokMgr_h

#include <ae2f/Call.h>
#include <ae2f/Cast.h>
#include "./TokMgr.auto.h"

/** String */
typedef char KPP_Tok[KPP_TOKL];

/** Big string for token */
typedef char KPP_TokMem[KPP_TOKML];

typedef struct KPP_TokMgr {
	int tokc;
	KPP_TokMem mem;
	const char* tokv[KPP_TOKC];
} KPP_TokMgr;

#include <stdio.h>

ae2f_extern ae2f_SHAREDCALL
int KPP_TokMgrInit(
		KPP_TokMgr* mgr,
		FILE* istream
		);

#endif
