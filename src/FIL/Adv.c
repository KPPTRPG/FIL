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
) {
	fputs("Info\n", ostream);
	FIL_AdvInfoPrt(&adv->Info, ostream);
	fputs("Stat\n", ostream);
	FIL_AdvStatPrt(&adv->Stat, ostream);
	fputs("Quit::FIL_Adv\n", ostream);
}
