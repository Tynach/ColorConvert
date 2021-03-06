#pragma once

#define FLOATP_FLOAT 0
#define FLOATP_DOUBLE 1
#define FLOATP_LONG_DOUBLE 2
#define FLOATP_QUAD_DOUBLE 3

#ifndef FLOAT_TYPE
	#define FLOAT_TYPE FLOATP_DOUBLE
#endif

#if FLOAT_TYPE == FLOATP_FLOAT
	#define pow(...) powf(__VA_ARGS__)
	#define round(...) roundf(__VA_ARGS__)
	#define lround(...) lroundf(__VA_ARGS__)
	#define llround(...) llroundf(__VA_ARGS__)
	typedef float floatp;
#elif FLOAT_TYPE == FLOATP_DOUBLE
	typedef double floatp;
#elif FLOAT_TYPE == FLOATP_LONG_DOUBLE
	#define pow(...) powl(__VA_ARGS__)
	#define round(...) roundl(__VA_ARGS__)
	#define lround(...) lroundl(__VA_ARGS__)
	#define llround(...) llroundl(__VA_ARGS__)
	typedef long double floatp;
#elif FLOAT_TYPE == FLOATP_QUAD_DOUBLE
	#define pow(...) powq(__VA_ARGS__)
	#define round(...) roundq(__VA_ARGS__)
	#define lround(...) lroundq(__VA_ARGS__)
	#define llround(...) llroundq(__VA_ARGS__)
	typedef __float128 floatp;
#endif