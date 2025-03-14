#ifndef warp_h
#define warp_h

enum ewarp_STRLINE {
	warp_STRLINE,

	/// @brief For indexing
	warp_STRLINE_APPEND,

	/// @brief For actually writing
	warp_STRLINE_WRITE
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
