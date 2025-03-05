#ifndef adv_warp_h
#define adv_warp_h

enum ewarp {
    	warp_ADV_ENT,
    	warp_ADV_INFO,
    	warp_ADV_STAT
};

enum ewarp_ADV_STAT {
	warp_ADV_STAT_AGI = warp_ADV_STAT + 1,
	warp_ADV_STAT_CON,
	warp_ADV_STAT_G,
	warp_ADV_STAT_INT,

	warp_ADV_STAT_LNK,
	warp_ADV_STAT_LNK0,
	warp_ADV_STAT_LNK1,
	warp_ADV_STAT_LNK2,
	warp_ADV_STAT_LNK_LEN,

	warp_ADV_STAT_LP,
	warp_ADV_STAT_SP,
	warp_ADV_STAT_STR
};

enum ewarp_ADV_INFO {
    	warp_ADV_INFO_AGE = warp_ADV_INFO + 1,
    	warp_ADV_INFO_BIAS,
    	warp_ADV_INFO_BROOD,
    	warp_ADV_INFO_GENDER,
    	warp_ADV_INFO_GLOB,
    	warp_ADV_INFO_HEIGHT,
    	warp_ADV_INFO_WEIGHT,
};

enum ewarp_ADV_BROOD {
    	warp_ADV_BROOD,
    	warp_ADV_BROOD_DESC,
    	warp_ADV_BROOD_STAT,
    	warp_ADV_BROOD_NAME
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
#define warp_quit(label) default: { KPP_puts("Matches none. Quitting " #label "."); return warp_index; }

#define warp_index i
#define warp_varname warp

#if !(defined(warp_index) && defined(warp_varname) && defined(warp_key))
#error Neither "warp_index" nor "warp_index" nor "warp_key" is detected.
#endif

#pragma endregion
