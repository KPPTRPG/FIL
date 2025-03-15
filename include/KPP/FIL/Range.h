/*
 * @file Range.h
 *
 * @brief
 * One dot will be a sequence of numbers.
 * 
 *
 * */


#ifndef KPP_FIL_Range_h
#define KPP_FIL_Range_h

#include <stdio.h>
#include <stdint.h>

#include "./Range.auto.h"

#include <ae2f/Call.h>
#include <ae2f/Cast.h>

/**
 * @warning
 * It expects the instance will be initiated with 0.
 *
 * @code
 * FIL_Range_Dot dot = {0, };
 *
 * @brief
 * A dot, representing the "relational" position.
 *
 * */
typedef int32_t FIL_RangeDot[FIL_RANGE_DOT_COUNT];


#define FIL_RangeDotCmp_A_GREATER	-1
#define FIL_RangeDotCmp_A_LESSER	1
#define FIL_RangeDotCMP_EQUAL		0

/** 
 * @brief
 * Compare two dots.
 *
 * */
ae2f_extern ae2f_SHAREDCALL
uint8_t FIL_RangeDotCmp(
		const FIL_RangeDot a
		, const FIL_RangeDot b
		);

/**
 * @warning 
 * It expects the instance will be initiated with 0.
 *
 * @code 
 * FIL_Range_Obj obj = {0, };
 *
 * @brief
 * Represents the object's shape.
 * 
 * Dot, with all zero is the core of the object.
 * */
typedef FIL_RangeDot FIL_RangeObj[FIL_RANGE_OBJ_COUNT];

ae2f_extern ae2f_SHAREDCALL
size_t FIL_RangeObjInit(
		FIL_RangeObj obj
		, int argc
		, const char** argv
		);

ae2f_extern ae2f_SHAREDCALL
void FIL_RangeObjPrt(
		const FIL_RangeObj obj
		, FILE* ostream
		);

ae2f_extern ae2f_SHAREDCALL
size_t FIL_RangeObjMatch(
		const FIL_RangeObj a
		, const FIL_RangeObj b
		);

#endif
