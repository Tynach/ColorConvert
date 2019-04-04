#pragma once
#include <colorvec/conf.h>

template <class T> class test_base {
	// Hopefully 2^-17 is more than large enough for fair float equality
	constexpr static floatp tolerance = 0.00000762939453125;

protected:
	const T initial;
	const T test_t;
	const floatp test_float;

	bool test_equals(const T& test, const T& expected)
	{
		// Manually generate a vector with slightly lower values, and
		// one with slightly higher values
		T lower, upper;

		for (int i = 0; i < sizeof(T)/sizeof(floatp); ++i) {
			((floatp*)&lower)[i] = ((floatp*)&expected)[i] - tolerance;
			((floatp*)&upper)[i] = ((floatp*)&expected)[i] + tolerance;
		}

		// Perform the test via a sequence of boolean AND operations, so
		// that if any of them return 'false' the rest of them will too
		bool result = true;

		for (int i = 0; i < sizeof(T)/sizeof(floatp); ++i) {
			result &= ((floatp*)&test)[i] >= ((floatp*)&lower)[i];
			result &= ((floatp*)&test)[i] <= ((floatp*)&upper)[i];
		}

		return result;
	}

public:
	test_base(T init_t, T t_value, floatp float_value):
		initial(init_t),
		test_t(t_value),
		test_float(float_value)
	{}

	// Test operators where the right-hand side is a T
	bool test_same_addeq(const T& expected)
	{
		T copy = initial;
		copy += test_t;

		return test_equals(copy, expected);
	}

	bool test_same_subeq(const T& expected)
	{
		T copy = initial;
		copy -= test_t;

		return test_equals(copy, expected);
	}

	bool test_same_muleq(const T& expected)
	{
		T copy = initial;
		copy *= test_t;

		return test_equals(copy, expected);
	}

	bool test_same_diveq(const T& expected)
	{
		T copy = initial;
		copy /= test_t;

		return test_equals(copy, expected);
	}

	bool test_same_add(const T& expected)
	{return test_equals(initial + test_t, expected);}

	bool test_same_sub(const T& expected)
	{return test_equals(initial - test_t, expected);}

	bool test_same_mul(const T& expected)
	{return test_equals(initial*test_t, expected);}

	bool test_same_div(const T& expected)
	{return test_equals(initial/test_t, expected);}

	// Test operators where the right-hand side is a floatp
	bool test_float_addeq(const T& expected)
	{
		T copy = initial;
		copy += test_float;

		return test_equals(copy, expected);
	}

	bool test_float_subeq(const T& expected)
	{
		T copy = initial;
		copy -= test_float;

		return test_equals(copy, expected);
	}

	bool test_float_muleq(const T& expected)
	{
		T copy = initial;
		copy *= test_float;

		return test_equals(copy, expected);
	}

	bool test_float_diveq(const T& expected)
	{
		T copy = initial;
		copy /= test_float;

		return test_equals(copy, expected);
	}

	bool test_float_add(const T& expected)
	{return test_equals(initial + test_float, expected);}

	bool test_float_sub(const T& expected)
	{return test_equals(initial - test_float, expected);}

	bool test_float_mul(const T& expected)
	{return test_equals(initial*test_float, expected);}

	bool test_float_div(const T& expected)
	{return test_equals(initial/test_float, expected);}

	// Test the logical (in)equality operators
	bool test_equality(const T& expected)
	{
		bool result = true;

		// Test absolute equality of all members, without tolerance
		for (int i = 0; i < sizeof(T)/sizeof(floatp); ++i) {
			result &= ((floatp*)&initial)[i] == ((floatp*)&expected)[i];
		}

		return result;
	}

	bool test_inequality(const T& expected)
	{
		bool result = true;

		// Test absolute equality of all members, without tolerance
		for (int i = 0; i < sizeof(T)/sizeof(floatp); ++i) {
			result &= ((floatp*)&initial)[i] != ((floatp*)&expected)[i];
		}

		return result;
	}
};