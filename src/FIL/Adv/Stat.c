#define warp_key warp_ADV_STAT

#include <KPP/FIL/Adv/Stat.h>
#include <KPP/InitWithArgs.h>
#include "warp.h"
#include <stdlib.h>

#define KPP_AdvStatXPMax 100

ae2f_SHAREDEXPORT
void FIL_AdvStatPrt(
	const FIL_AdvStat* adv
	,FILE* ostream
)
{
	fprintf(
		ostream
		
		, "AGI:	%u\n"
		"CON:	%u\n"
		"G:		%u\n"
		"INT:	%u\n"
		"LNK 0	%u\n"
		"LNK 1	%u\n"
		"LNK 2	%u\n"
		"LP:	%u\n"
		"SP:	%u\n"
		"STR:	%u\n"
		"Quit::FIL_AdvStat\n"

		, adv->AGI
		, adv->CON
		, adv->G
		, adv->INT
		, adv->LNK[0]
		, adv->LNK[1]
		, adv->LNK[2]
		, adv->LP
		, adv->SP
		, adv->STR
	);
}

ae2f_extern ae2f_SHAREDEXPORT
KPP_InitImp(FIL_AdvStat, stat) {
	warp_tent();

	for(;i < argc; i++) 
	{
		switch(warp)
		{
			warpcase(warp_ADV_STAT);
			case warp_ADV_STAT_AGI:
			{

				size_t 
					_V = atoi(argv[i])
					, V = V % KPP_AdvStatXPMax;

				KPP_printf(
						"warp_ADV_STAT_AGI, "
						"setting value: %d[%d]\n"
						, _V, V
						);

				stat->AGI = V;
			} break;

			case warp_ADV_STAT_CON:
			{

				size_t 
					_V = atoi(argv[i])
					, V = V % KPP_AdvStatXPMax;

				KPP_printf(
						"warp_ADV_STAT_CON, "
						"setting value: %d[%d]\n"
						, _V, V
						);

				stat->CON = V;
			} break;

			case warp_ADV_STAT_G:
			{

				size_t 
					_V = atoi(argv[i])
					, V = V % KPP_AdvStatXPMax;

				KPP_printf(
						"warp_ADV_STAT_G, "
						"setting value: %d[%d]\n"
						, _V, V
						);

				stat->G = V;

			} break;

			case warp_ADV_STAT_INT:
			{
				size_t 
					_V = atoi(argv[i])
					, V = V % KPP_AdvStatXPMax;

				KPP_printf(
						"warp_ADV_STAT_INT, "
						"setting value: %d[%d]\n"
						, _V, V
						);

				stat->INT = V;

			} break;

			case warp_ADV_STAT_LNK:
			{
				size_t 
					_I = atoi(argv[i])
					, I = _I % (warp_ADV_STAT_LNK_LEN - warp_ADV_STAT_LNK0);
				KPP_printf(
						"warp_ADV_STAT_LNK, "
						"getting index %d[%d]\n"

						, _I
						, I
						);

				warp += I;
			} goto warp_LOOP;

			case warp_ADV_STAT_LNK0:
			{
				size_t 
					_V = atoi(argv[i])
					, V = V % KPP_AdvStatXPMax;

				KPP_printf(
						"warp_ADV_STAT_LNK0, "
						"setting value: %d[%d]\n"
						, _V, V
						);

				stat->LNK[0] = V;
			} break;


			case warp_ADV_STAT_LNK1:
			{

				size_t 
					_V = atoi(argv[i])
					, V = V % KPP_AdvStatXPMax;

				KPP_printf(
						"warp_ADV_STAT_LNK1, "
						"setting value: %d[%d]\n"
						, _V, V
						);

				stat->LNK[1] = V;

			} break;


			case warp_ADV_STAT_LNK2:
			{
				size_t 
					_V = atoi(argv[i])
					, V = V % KPP_AdvStatXPMax;

				KPP_printf(
						"warp_ADV_STAT_LNK2, "
						"setting value: %d[%d]\n"
						, _V, V
						);

				stat->LNK[2] = V;
			} break;

			case warp_ADV_STAT_LP:
			{
				size_t 
					_V = atoi(argv[i])
					, V = V % KPP_AdvStatXPMax;

				KPP_printf(
						"warp_ADV_STAT_LP, "
						"setting value: %d[%d]\n"
						, _V, V
						);

				stat->LP = V;

			} break;

			case warp_ADV_STAT_SP:
			{
				size_t 
					_V = atoi(argv[i])
					, V = V % KPP_AdvStatXPMax;

				KPP_printf(
						"warp_ADV_STAT_SP, "
						"setting value: %d[%d]\n"
						, _V, V
						);

				stat->SP = V;

			} break;

			case warp_ADV_STAT_STR:
			{
				size_t 
					_V = atoi(argv[i])
					, V = V % KPP_AdvStatXPMax;

				KPP_printf(
						"warp_ADV_STAT_STR, "
						"setting value: %d[%d]\n",
						_V, V
						);

				stat->STR = V;
			} break;

			warp_default();
		}

		warp_loop():;
	}

	KPP_puts(
			"index ran out \n\t> "
			"Quitting warp_ADV_STAT\n\n"
			);
	return i;

_warp_ADV_STAT:
	{
		KPP_puts(
				"_warp_ADV_STAT: \n\t> "
				"Getting flag among: \n\t "
				"- [A]GI \n\t "
				"- [C]ON \n\t "
				"- [G] \n\t "
				"- [LN]K \n\t "
				"- [LP] \n\t "
				"- [SP] \n\t "
				"- [ST]R \n\t "
				"- [I]NT \n\t "
				"- [Q]uit\n\n"
				);

		switch(*argv[i])
		{
			warp_switchonekey(
					'A'
					, warp
					, warp_ADV_STAT_AGI
					);

			warp_switchonekey(
					'C'
					, warp
					, warp_ADV_STAT_CON
					);

			warp_switchonekey(
					'G'
					, warp
					, warp_ADV_STAT_G
					);

			warp_switchonekey(
					'I'
					, warp
					, warp_ADV_STAT_INT
					);

__QUIT_GLOBAL:
			warp_quit(_warp_ADV_STAT);

			case 'S':
			{
				KPP_puts(
						"Got [S]. switching among... \n\t "
						"- S[P] \n\t "
						"- S[T]R\n\n"
						);

				switch(argv[i][1])
				{
					warp_switchonekey(
							'P'
							, warp
							, warp_ADV_STAT_SP
							);

					warp_switchonekey(
							'T'
							, warp
							, warp_ADV_STAT_STR
							);

					default:
					goto __QUIT_GLOBAL;
				}
			}

			case 'L': 
			{
				KPP_puts(
						"Got [L]. switching among... \n\t "
						"- L[N]K \n\t "
						"- L[P] \n\n"
						);

				switch(argv[i][1]) 
				{
					warp_switchonekey(
							'P'
							, warp
							, warp_ADV_STAT_LP
							);

					warp_switchonekey(
							'N'
							, warp
							, warp_ADV_STAT_LNK
							);
					default: 
					goto __QUIT_GLOBAL;
				}
			}
		}
	} goto warp_LOOP;
}
