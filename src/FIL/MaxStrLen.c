#include <string.h>
#include <KPP/FIL/MaxStrLen.h>
#include <KPP/InitWithArgs.h>
#include <KPP/Log.h>

#define warp_key warp_STRLINE
#include "warp.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

ae2f_extern ae2f_SHAREDEXPORT
int FIL_StrLine_tInit(
		FIL_StrLine_t strline
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
				lineidx %= FIL_STRLINE;
				warp = warp_STRLINE_WRITE;

				KPP_printf(
						"warp_STRLINE_APPEND, "
						"Indexing into %u\n"
						, lineidx
						);
			} goto warp_LOOP;

			case warp_STRLINE_WRITE:
			{
				strncpy(
						strline[lineidx]
						, argv[i]
						, FIL_STRLEN
						);

				KPP_printf(
						"warp_STRLINE_WRITE, "
						"Wrote %u\n%s\n\n"
						, strline[lineidx]
						);

				KPP_puts(
						"Migrating into "
						"_warp_STRLINE..."
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
				"- [Q]uit"
				);

		switch(warp)
		{
			warp_quit(_warp_STRLINE);
			warp_switchonekey('A', warp, warp_STRLINE_APPEND);
		}
	} goto warp_LOOP;
}
