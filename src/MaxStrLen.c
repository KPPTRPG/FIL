#include <string.h>
#include <KPP/MaxStrLen.h>
#include <KPP/InitWithArgs.h>
#include <KPP/Log.h>

#define warp_key warp_STRLINE
#include "warp.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

ae2f_extern ae2f_SHAREDEXPORT
int KPP_StrLine_tInit(
		KPP_StrLine_t strline
		, int argc
		, const char** argv
		)
{
	warp_tent();
	size_t lineidx = 0;

	for(; i < argc; i++) 
	{
		switch(warp)
		{
			warp_default();
			warpcase(warp_STRLINE);
			case warp_STRLINE_APPEND:
			{
				lineidx = atoi(argv[i]);
				lineidx %= KPP_STRLINE;
				warp = warp_STRLINE_WRITE;

				KPP_printf(
						"warp_STRLINE_APPEND, "
						"Indexing into %lu\n"
						, lineidx
						);

			} goto warp_LOOP;

			case warp_STRLINE_WRITE:
			{
				strncpy(
						strline[lineidx]
						, argv[i]
						, KPP_STRLEN
						);

				KPP_printf(
						"warp_STRLINE_WRITE, "
						"Wrote %s\n\n"
						, strline[lineidx]
						);

				KPP_puts(
						"Migrating into "
						"_warp_STRLINE...\n"
						);
			} break;
		}
		warp_loop():;
	}

	return i;

_warp_STRLINE:
	{
		KPP_puts(
				"_warp_STRLINE: \n\t> "
				"Getting token among: \n\t "
				"- [A]ppend\n\t "
				"- [Q]uit\n\n"
				);

		switch(*argv[i])
		{
			warp_quit(_warp_STRLINE);
			warp_switchonekey('A', warp, warp_STRLINE_APPEND);
		}
	} goto warp_LOOP;
}

ae2f_SHAREDEXPORT
void KPP_StrLine_tPrt(
	const KPP_StrLine_t adv
	,FILE* ostream
) 
{
	for(size_t i = 0; i < KPP_STRLINE; i++) 
	{
		if(adv[i]) 
		fprintf(
				ostream
				, "Append %lu \"%s\"\n"
				, i
				, adv[i]
				);
	}
	fputs("Quit::StrLine\n", ostream);
}
