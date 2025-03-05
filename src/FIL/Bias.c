#define warp_key warp_BIAS
#include "warp.h"
#include <KPP/FIL/Bias.h>
#include <KPP/Log.h>
#include <ae2f/BitVec.h>

KPP_InitImp(FIL_Bias_t, bias) {
	warp_tent();
	for(; i < argc; i++) {
		switch(warp) 
		{
			warpcase(warp_BIAS);
			case warp_BIAS_ORDER_CHAOS:
			{
				
				KPP_printf(
						"warp_BIAS_ORDER_CHAOS: \n\t> "
						"setting value: %p\n"

						, (*bias = 
							*bias & ~FIL_Bias_MASK_ORDER |
							FIL_Bias_CHAOS)
						);

				KPP_puts("Redirecting to warp_BIAS...");

			} break;

			case warp_BIAS_ORDER_LAWFUL:
			{
				KPP_printf(
						"WARP_BIAS_ORDER_LAWFUL: \n\t> "
						"setting value: %p\n"

						, (*bias = 
							*bias & ~FIL_Bias_MASK_ORDER |
							FIL_Bias_KHASSAR)
						);

				KPP_puts("Redirecting to warp_BIAS...");
			} break;

			case warp_BIAS_ORDER_NEUTRAL:
			{
				KPP_printf(
						"WARP_BIAS_ORDER_NEUTRAL: \n\t> "
						"setting value: %p\n"
						, (*bias &= ~FIL_Bias_MASK_ORDER)
						);

				KPP_puts("Redirecting to warp_BIAS...");
			}

			case warp_BIAS_ORDER: 
			{
				KPP_puts(
						"warp_BIAS_ORDER: \n\t> "
						"Getting flag among: \n\t "
						"- [L]awful \n\t "
						"- [N]eutral \n\t "
						"- [C]haos \n\t "
						"- [Q]uit"
						);

				switch(warp) 
				{
					warp_switchonekey(
							'L'
							, warp
							, warp_BIAS_ORDER_LAWFUL
							);

					warp_switchonekey(
							'N'
							, warp
							, warp_BIAS_ORDER_NEUTRAL
							);

					warp_switchonekey(
							'C'
							, warp
							, warp_BIAS_ORDER_CHAOS
							);

					default:
					{
						KPP_puts(
								"Matches none. "
								"Quitting KPP_BIAS_ORDER"
								);

						warp = warp_BIAS;
					} goto warp_LOOP;
				}

			} goto warp_LOOP;


			case warp_BIAS_GOOD_EVIL:
			{
				KPP_printf(
						"warp_BIAS_GOOD_EVIL: \n\t >"
						"setting value: %p\n"

						, (*bias = 
							*bias & ~FIL_Bias_MASK_GOOD |
							FIL_Bias_EVL)
						);

				KPP_puts("Redirecting to warp_BIAS...");
			} break;

			case warp_BIAS_GOOD_GOOD:
			{
				KPP_printf(
						"warp_BIAS_GOOD_GOOD: \n\t> "
						"setting value: %p\n"

						, (*bias = *bias & ~FIL_Bias_MASK_GOOD |
							FIL_Bias_TEMPLARI)
						);

				KPP_puts("Redirecting to warp_BIAS...");
			} break;

			case warp_BIAS_GOOD_NEUTRAL:
			{
				KPP_printf(
						"WARP_BIAS_GOOD_NEUTRAL: \n\t> "
						, (*bias &= ~FIL_Bias_MASK_GOOD)
						);

				KPP_puts("Redirecting to warp_BIAS...");
			} break;

			case warp_BIAS_GOOD: 
			{
				KPP_puts(
						"warp_BIAS_GOOD\n\t> "
						"Getting flag among: \n\t "
						"- [E]vil \n\t "
						"- [N]eutral \n\t "
						"- [G]ood \n\t "
						"- [Q]uit"
						);

				switch(*argv[i])
				{
					warp_switchonekey(
							'E'
							, warp
							, warp_BIAS_GOOD_EVIL
							);

					warp_switchonekey(
							'N'
							, warp
							, warp_BIAS_GOOD_NEUTRAL
							);

					warp_switchonekey(
							'G'
							, warp
							, warp_BIAS_GOOD_GOOD
							);

					default:
					{
						KPP_puts(
								"Matches none. "
								"Quitting warp_BIAS_ORDER"
								);

						warp = warp_BIAS;
					} goto warp_LOOP;

					goto warp_LOOP;
				}
			} break;
			warp_default();
		}
		warp_loop():;
	}

	KPP_puts(
			"index ran out. \n\t> "
			"Quitting warp_BIAS"
			);
	return i;

	_warp_BIAS: 
	{
		KPP_puts(
				"_warp_BIAS: \n\t> "
				"Getting flag among: \n\t "
				"- [O]rder\n\t "
				"- [G]ood\n\t "
				"= [Q]uit"
				);


		switch(*argv[i]) {
			warp_switchonekey('O', warp, warp_BIAS_ORDER);
			warp_switchonekey('G', warp, warp_BIAS_GOOD);
			warp_quit(_warp_BIAS);
		}
	} goto warp_LOOP;
}
