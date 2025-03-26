#define warp_key warp_ADV_ENT
#include "Adv/warp.h"
#include <KPP/FIL/Adv.h>
#include <KPP/Log.h>
#include <KPP/TokMgr.h>
#include <string.h>

ae2f_extern ae2f_SHAREDEXPORT
int FIL_AdvInit(
		FIL_Adv* adv
		, int argc
		, const char** argv
) {
	warp_tent();
	for(; i < argc; i++) {
		switch(warp) {
			warpcase(warp_ADV_ENT);
			case warp_ADV_INFO: 
			{
				i += FIL_AdvInfoInit(
						&adv->Info, argc - i
						, argv + i
						) - 1;
			} break;

			case warp_ADV_STAT: 
			{
				i += FIL_AdvStatInit(
						&adv->Stat, argc - i
						, argv + i
						) - 1;	
			} break;

			case warp_ADV_READ:
			{
				KPP_Str_t str;
				strncpy(str, argv[i], KPP_STRLEN);
				FILE* f = fopen(str, "r");

				KPP_TokMgr tokmgr;

				if(!f) break;
				KPP_TokMgrInit(&tokmgr, f);
				fclose(f);
				FIL_AdvInit(adv, tokmgr.tokc, tokmgr.tokv);
			} break;

			default: assert(0);
		}
		warp_loop():;
	}

	
	return i;

_warp_ADV_ENT: 
	{
		KPP_puts(
				"warp_ADV_ENT: \n\t> "
				"Getting flag among: \n\t "
				"- [I]nfo\n\t "
				"- [S]tat\n\t "
				"- [R]ead\n\t "
				"- [Q]uit"
				);
		
		switch(*argv[i]) {
			warp_switchonekey('I', warp, warp_ADV_INFO);
			warp_switchonekey('S', warp, warp_ADV_STAT);
			warp_switchonekey('R', warp, warp_ADV_READ);
			warp_quit(_warp_ADV_ENT);
		}
	} 

	goto warp_LOOP;
}

ae2f_SHAREDEXPORT
void FIL_AdvPrt(
		const FIL_Adv* adv
		, FILE* ostream
		) 
{
	fputs("Info\n", ostream);
	FIL_AdvInfoPrt(&adv->Info, ostream);
	fputs("Stat\n", ostream);
	FIL_AdvStatPrt(&adv->Stat, ostream);
	fputs("Quit::FIL_Adv\n", ostream);
}

/**
 * @brief
 *
 * # DISCLAIMER: it is a constant string builder.
 * */
#define JSON_STAT(lbl, val, max) "{\"label\":\"" lbl "\",\"value\":" val ",\"max\":" max "}"
#define JSON_PRM(lbl, val) "{\"label\": \"" lbl "\",\"value\":\"" val "\"}"

#define MOV_RANGE 5

ae2f_SHAREDEXPORT
void FIL_AdvJson(
		const FIL_Adv* adv
		, FILE* ostream
		, FIL_AdvJsonQuery* query
		)
{
	const FIL_AdvStat* stat = &adv->Stat;
	const size_t data_initiative = stat->AGI * stat->CON * 10 - 10;

	/* AGI - CON (1 ~ 5) */
	const size_t data_prm_MOV = ((stat->AGI - stat->CON - 1) % MOV_RANGE) + 1;
	const size_t data_prm_LINK = stat->LNK[query->LinkIndex % (sizeof(stat->LNK) / sizeof(stat->LNK[0]))];

	fprintf(
			ostream, 
			"{"
				"\"kind\":\"character\","
				"\"data\":{"
					"\"name\":\"%s\","
					"\"initiative\": %lu," // AGI * 10 * CON - 10
					"\"status\":["
						JSON_STAT("LP", "%u", "100") ","
						JSON_STAT("SP", "%u", "100") ","
						JSON_STAT("G", "%u", "0")
					"],"

					"\"params\": ["
						JSON_PRM("STR", "%u")	","
						JSON_PRM("AGI", "%u")	","
						JSON_PRM("CON", "%u")	","
						JSON_PRM("MOV", "%lu")	","
						JSON_PRM("ATK", "%u")	","
						JSON_PRM("DEF", "%u")	","
						JSON_PRM("LNK", "%lu")
					"]"
				"}"
			"}"


			, adv->Info.Glob.Name
			, data_initiative

			/* Status Section */
			, stat->LP, stat->SP
			, stat->G

			/* Prm Section */
			, stat->STR, stat->AGI
			, stat->CON, data_prm_MOV

			, query->ATK, query->DEF
			, data_prm_LINK


			);
}

#undef warp_key
#define warp_key warp_QUERY
#include <stdlib.h>
#include "./warp.h"

ae2f_SHAREDEXPORT
size_t FIL_AdvJsonQueryMk(
		FIL_AdvJsonQuery* query
		, int argc
		, const char** argv
		) 
{
	warp_tent();
	for(;i < argc; i++) {
		switch(warp) {
			warpcase(warp_QUERY);
			case warp_QUERY_LNK:
			query->LinkIndex = atoi(argv[i]);
			break;

			case warp_QUERY_ATK:
			query->ATK = atoi(argv[i]);
			break;

			case warp_QUERY_DEF:
			query->DEF = atoi(argv[i]);
			break;

			default: assert(0);
		}

		warp_loop():;
	}

	return i;

_warp_QUERY: 
	{
		KPP_puts(
				"warp_QUERY: \n\t> "
				"Getting flag among: \n\t "
				"- [L]INK_INDEX\n\t "
				"- [A]TK\n\t "
				"- [D]EF\n\t "
				"- [Q]uit\n\n"
				);

		switch(*argv[i])
		{
			warp_quit(_warp_QUERY);
warp_switchonekey('L', warp, warp_QUERY_LNK);
			warp_switchonekey('A', warp, warp_QUERY_ATK);
			warp_switchonekey('D', warp, warp_QUERY_DEF);
		}
	}
	goto warp_LOOP;
}


ae2f_SHAREDEXPORT
void FIL_AdvJsonQueryPrt(
		const FIL_AdvJsonQuery* query
		, FILE* ostream
		)
{
	fprintf(
			ostream,
			"ATK %u\n"
			"DEF %u\n"
			"LINK_INDEX %u\n"
			"Quit::JsonQuery\n"
			, query->ATK
			, query->DEF
			, query->LinkIndex
			);

	return;
}
