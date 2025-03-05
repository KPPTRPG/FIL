#define warp_key warp_ADV_BROOD

#include <string.h>
#include "warp.h"

#include <KPP/Log.h>
#include <KPP/FIL/Adv/Brood.h>
#include <KPP/FIL/Adv/Stat.h>

/*Imp Done*/
ae2f_SHAREDEXPORT
KPP_InitImp(
		FIL_AdvBrood
		, brood) 
{
	warp_tent();

	for(; i < argc; i++) {
		switch (warp) {
			warpcase(warp_ADV_BROOD);
			warp_default();
			case warp_ADV_BROOD_STAT: 
			{
				i += FIL_AdvStatInit(
						&brood->Status 
						, argc - i, argv + i
						) - 1;
			} break;

			case warp_ADV_BROOD_NAME: 
			{
				strncpy(
						brood->Name
						, argv[i]
						, FIL_STRLEN
						);

				
			}

			case warp_ADV_BROOD_DESC: 
			{
				i += FIL_StrLine_tInit(
						brood->Description
						, argc - i, argv + i
						) - 1;
			}
		}

		warp_loop():;
	}

	return i;
_warp_ADV_BROOD:
	{
		KPP_puts(
				"warp_ADV_BROOD: \n\t> "
				"Getting flag among: \n\t "
				"- [N]ame\n\t "
				"- [S]tatus\n\t "
				"- [D]escription\n\t "
				"- [Q]uit"
				);

		switch (*argv[i])
		{
			;
			case 'N': 
			{
				warp = warp_ADV_BROOD_NAME;
			} break;

			case 'S': 
			{
				warp = warp_ADV_BROOD_STAT;
			} break;

			
			case 'D': 
			{
				warp = warp_ADV_BROOD_DESC;
			} break;

			
			default:
			KPP_puts("Matches none. Quitting _warp_ADV_BROOD.");
			return i;
		}
	} 

	goto warp_LOOP;
}
