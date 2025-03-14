#include <string.h>
#include <KPP/FIL/Bias.h>
#include <KPP/FIL/Adv/Brood.h>
#include <KPP/FIL/Adv/Info.h>

#define warp_key warp_ADV_INFO
#include "warp.h"
#include <stdlib.h>

ae2f_extern ae2f_SHAREDCALL
int FIL_AdvInfoInit(
		FIL_AdvInfo* info
		, int argc
		, const char** argv
		) 
{
	warp_tent();
	for(;i < argc; i++) 
	{
		switch(warp) 
		{
			warpcase(warp_ADV_INFO);
			case warp_ADV_INFO_AGE: 
			{
				KPP_printf(
						"warp_ADV_INFO_AGE: %d\n"
						, info->Age = atoi(argv[i])
						);	
			} break;

			case warp_ADV_INFO_BROOD: 
			{                
				i += FIL_AdvBroodInit(
						&info->Brood
						, argc - i
						, argv + i
						) - 1;
			} break;
			
			case warp_ADV_INFO_BIAS: 
			{
				i += FIL_Bias_tInit(
						&info->Bias 
						, argc - i, argv + i
						) - 1;
			} break;

			case warp_ADV_INFO_GENDER: 
			{
				strncpy(
						info->Gender
						, argv[i], KPP_STRLEN
						);

				KPP_printf(
						"warp_ADV_INFO_GENDER: %s\n"
						, info->Gender
						);
			} break;

			case warp_ADV_INFO_GLOB: 
			{                
				i += FIL_GlobInit(
						&info->Glob
						, argc - i, argv + i
						) - 1;	
			} break;
			case warp_ADV_INFO_HEIGHT: 
			{
				KPP_printf(
						"warp_ADV_INFO_HEIGHT: %d\n"
						, info->Height = atoi(argv[i])
						);
			} break;

			case warp_ADV_INFO_WEIGHT: 
			{
				KPP_printf(
						"warp_ADV_INFO_WEIGHT: %d\n"
						, info->Weight = atoi(argv[i])
						);
			} break;

			default: assert(0);
		}

		warp_loop():;
	}
	
	return i;
	
_warp_ADV_INFO: 
	{
		KPP_puts(
				"warp_ADV_INFO: \n\t> "
				"Getting flag among: \n\t "
				"- [A]ge\n\t "
				"- [Bi]as\n\t "
				"- [Br]ood\n\t "
				"- [Ge]nder\n\t "
				"- [Gl]ob\n\t "
				"- [H]eight\n\t "
				"- [W]eight\n\t "
				"- [Q]uit\n\n"
				);

		switch(*argv[i]) {
			warp_switchonekey('A', warp, warp_ADV_INFO_AGE);
			warp_switchonekey('H', warp, warp_ADV_INFO_HEIGHT);
			warp_switchonekey('W', warp, warp_ADV_INFO_WEIGHT);

			case 'B': 
			{        
				if(*argv[i] == 'i')
					warp = warp_ADV_INFO_BIAS;
				else if (*argv[i] == 'r')
					warp = warp_ADV_INFO_BIAS;
				else goto _warp_ADV_INFO_NFOUND;
			} break;
			
			case 'G': 
			{
				if(argv[i][1] == 'e')
					warp = warp_ADV_INFO_GENDER;
				if(argv[i][1] == 'l')
					warp = warp_ADV_INFO_GLOB;
				else goto _warp_ADV_INFO_NFOUND;
			} break;
			
			default: 
			{
_warp_ADV_INFO_NFOUND:
				KPP_puts("Matches none. Quitting _warp_ADV_INFO.\n");
				return i;
			} break;
		}
	} 

	goto warp_LOOP;
}

ae2f_SHAREDEXPORT
void FIL_AdvInfoPrt(
		const FIL_AdvInfo* adv
		, FILE* ostream
		)
{
	fputs("Glob:\n", ostream);
	FIL_GlobPrt(&adv->Glob, ostream);

	fprintf(ostream, "Weight: %u\n", adv->Weight);
	fprintf(ostream, "Height: %u\n", adv->Height);

	fprintf(ostream, "Age: %u\n", adv->Age);

	fputs("Bias:\n", ostream);
	FIL_Bias_tPrt(adv->Bias, ostream);

	fputs("Brood:\n", ostream);
	FIL_AdvBroodPrt(&adv->Brood, ostream);

	fprintf(
			ostream
			, "Gender: \"%s\"\n"
			, adv->Gender
			);

	fputs("Quit::ADV_INFO\n", ostream);	
}
