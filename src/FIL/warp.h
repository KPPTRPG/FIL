#ifndef warp_h
#define warp_h

enum ewarp_BIAS {
	warp_BIAS,

	warp_BIAS_ORDER,
	warp_BIAS_ORDER_LAWFUL,
	warp_BIAS_ORDER_NEUTRAL,
	warp_BIAS_ORDER_CHAOS,

	warp_BIAS_GOOD,
	warp_BIAS_GOOD_EVIL,
	warp_BIAS_GOOD_NEUTRAL,
	warp_BIAS_GOOD_GOOD
};

enum ewarp_GLOB {
	warp_GLOB,
	warp_GLOB_NAME,
	warp_GLOB_PLNAME,
	warp_GLOB_PROFILE,
	warp_GLOB_PRINT,
	warp_GLOB_BG,
	warp_GLOB_ETC
};

enum ewarp_QUERY {
	warp_QUERY,
	warp_QUERY_LNK,
	warp_QUERY_ATK,
	warp_QUERY_DEF
};

#endif

#pragma region Pure Macro

#include <assert.h>
#include <KPP/Log.h>

#define warpcase(key) case key: goto _##key
#define warp_default() default: assert(0)

#define warp_loop() (warp_varname) = (warp_key); warp_LOOP
#define warp_tent() int warp_index = 0, warp_varname = (warp_key)
#define warp_switchonekey(ch, warp, _val) case ch: warp = _val; break
#define warp_quit(label) default: { KPP_puts("Matches none. Quitting " #label ".\n"); return warp_index; }

#define warp_index i
#define warp_varname warp

#if !(defined(warp_index) && defined(warp_varname) && defined(warp_key))
#error Neither "warp_index" nor "warp_index" nor "warp_key" is detected.
#endif

#pragma endregion
