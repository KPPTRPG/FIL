#include <KPP/FIL/Range.h>


ae2f_SHAREDEXPORT
uint8_t FIL_RangeDotCmp(
		const FIL_RangeDot a
		, const FIL_RangeDot b
		) 
{
	for(size_t i = 0; i < FIL_RANGE_DOT_COUNT; i++)
	{
		if(a[i] < b[i])
			return FIL_RangeDotCmp_A_LESSER;
		else
			return FIL_RangeDotCmp_A_GREATER;
	}

	return FIL_RangeDotCMP_EQUAL;
}



/**
 * The obj must be sorted so we could take advantage of that behaviour on sorting.
 *
 * Use insertion sort.
 * */
size_t FIL_RangeObjInit(
		FIL_RangeObj obj
		, int argc
		, const char** argv
		)
{
	return 0;
}

ae2f_SHAREDEXPORT
void FIL_RangeObjPrt(
		const FIL_RangeObj obj
		, FILE* ostream
		)
{
#include <KPP/todo_imp.auto.h> 
}

ae2f_SHAREDEXPORT
size_t FIL_RangeObjMatch(
		const FIL_RangeObj a
		, const FIL_RangeObj b
		)
{
#include <KPP/todo_imp.auto.h>
	for(size_t i = 0; i < FIL_RANGE_OBJ_COUNT; i++)
	{
		
	}

	return 0;
}
