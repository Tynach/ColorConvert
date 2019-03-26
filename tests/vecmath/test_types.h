#pragma once
#include <vecmath/conf.h>

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
};