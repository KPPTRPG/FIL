#include <KPP/FIL/Range.h>


int main() {
	const char* argv[] = {
		"60"/*objcount*/, 
		"2"/*dotcount*/,

		"1", "2",
		"3", "4",

		"2", "1"
	};

	const int argc = 
		sizeof(argv) / sizeof(argv[0]);

	FIL_RangeObj obj = {0, };

	FIL_RangeObjInit(
			obj
			, argc
			, argv
			);

	FIL_RangeObjPrt(
			obj
			, stdout
			);

	
	return 0;
}
