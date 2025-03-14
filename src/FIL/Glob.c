#include <KPP/FIL/Glob.h>
#include <KPP/Log.h>

#define warp_key warp_GLOB
#include "warp.h"
#include <string.h>

ae2f_SHAREDEXPORT 
int FIL_GlobInit(
		FIL_Glob* glob, 
		int argc, 
		const char** argv
		)
{
	warp_tent();

	for(; i < argc; i++)
	{
		switch(warp)
		{
			;
			warpcase(warp_GLOB);
			case warp_GLOB_BG:
			{
				i += KPP_StrLine_tInit(
						glob->Background
						, argc - i
						, argv + i
						) - 1;
			} break;
			case warp_GLOB_ETC:
			{
				i += KPP_StrLine_tInit(
						glob->Etc
						, argc - i 
						, argv + i
						) - 1;
			} break;
			case warp_GLOB_NAME:
			{
				strncpy(
						glob->Name
						, argv[i]
						, KPP_STRLEN
						);
			} break;

			case warp_GLOB_PRINT:
			{
				FIL_GlobPrt(
						glob
						, stdout
						);
			} break;

			case warp_GLOB_PLNAME:
			{
				strncpy(
						glob->PLName
						, argv[i]
						, KPP_STRLEN
						);
			} break;
			case warp_GLOB_PROFILE:
			{
				strncpy(
					glob->Profile
					, argv[i]
					, KPP_STRLEN
					);
			} break;
			default: assert(0);
		}
		warp_loop():;
	}

	return 0;

_warp_GLOB:
	{
		KPP_puts(
				"_warp_GLOB:\n\t> "
				"Getting key among\n\t "
				"- [N]ame\n\t "
				"- [PL]Name\n\t "
				"- [Pro]file\n\t "
				"- [B]ackground\n\t "
				"- [E]tc\n\t "
				"- [Pri]nt\n\t "
				"- [Q]uit\n\n"
				);

		switch(*argv[i])
		{
_QUIT:
			warp_quit(_warp_GLOB);
			warp_switchonekey('N', warp, warp_GLOB_NAME);
			warp_switchonekey('B', warp, warp_GLOB_BG);
			warp_switchonekey('E', warp, warp_GLOB_ETC);
			case 'P': 
			switch(argv[i][1])
			{
				warp_switchonekey(
						'L', 
						warp, 
						warp_GLOB_PLNAME
						);

				default:
				goto _QUIT;
				
				case 'r':
				switch(argv[i][2])
				{
					warp_switchonekey(
							'o' 
							, warp
							, warp_GLOB_PROFILE
							);
					warp_switchonekey(
							'i'
							, warp
							, warp_GLOB_PRINT
							);
					default:
					goto _QUIT;
				}
			}
		}
	} goto warp_LOOP;
}



ae2f_SHAREDEXPORT
void FIL_GlobPrt(
		const FIL_Glob* adv,
		FILE* ostream
		)
{
	fprintf(ostream, "Name: \"%s\"\n", adv->Name);
	fprintf(ostream, "PLName: \"%s\"\n", adv->PLName);
	fprintf(ostream, "Profile: \"%s\"\n", adv->Profile);

	fputs("Background:\n", ostream);
	KPP_StrLine_tPrt(adv->Background, ostream);

	fputs("Etc:\n", ostream);
	KPP_StrLine_tPrt(adv->Etc, ostream);

	fputs("Quit::GLOB\n", ostream);
	return;
}

