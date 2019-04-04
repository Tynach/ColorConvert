#include <vecmath/mat3.h>
#include "test_types.h"
using vecmath::mat3;

class mat3_test: test_base<mat3> {
public:
	mat3_test(mat3 init_mat, mat3 mat_value, floatp float_value):
		test_base(init_mat, mat_value, float_value)
	{}

	// Test operators where the right-hand side is a mat3
	bool test_matrix_addeq(const mat3& expected)
	{
		mat3 copy = initial;
		copy += test_t;

		return test_equals(copy, expected);
	}

	bool test_matrix_subeq(const mat3& expected)
	{
		mat3 copy = initial;
		copy -= test_t;

		return test_equals(copy, expected);
	}

	bool test_matrix_muleq(const mat3& expected)
	{
		mat3 copy = initial;
		copy *= test_t;

		return test_equals(copy, expected);
	}

	bool test_matrix_diveq(const mat3& expected)
	{
		mat3 copy = initial;
		copy /= test_t;

		return test_equals(copy, expected);
	}

	bool test_matrix_add(const mat3& expected)
	{return test_equals(initial + test_t, expected);}

	bool test_matrix_sub(const mat3& expected)
	{return test_equals(initial - test_t, expected);}

	bool test_matrix_mul(const mat3& expected)
	{return test_equals(initial* test_t, expected);}

	bool test_matrix_div(const mat3& expected)
	{return test_equals(initial/ test_t, expected);}

	// Test operators where the right-hand side is a floatp
	bool test_float_addeq(const mat3& expected)
	{
		mat3 copy = initial;
		copy += test_float;

		return test_equals(copy, expected);
	}

	bool test_float_subeq(const mat3& expected)
	{
		mat3 copy = initial;
		copy -= test_float;

		return test_equals(copy, expected);
	}

	bool test_float_muleq(const mat3& expected)
	{
		mat3 copy = initial;
		copy *= test_float;

		return test_equals(copy, expected);
	}

	bool test_float_diveq(const mat3& expected)
	{
		mat3 copy = initial;
		copy /= test_float;

		return test_equals(copy, expected);
	}

	bool test_float_add(const mat3& expected)
	{return test_equals(initial + test_float, expected);}

	bool test_float_sub(const mat3& expected)
	{return test_equals(initial - test_float, expected);}

	bool test_float_mul(const mat3& expected)
	{return test_equals(initial*test_float, expected);}

	bool test_float_div(const mat3& expected)
	{return test_equals(initial/test_float, expected);}
};

int main()
{
	mat3_test case1 = mat3_test(
		{0.1, 0.2, 0.0,
		 0.0, 0.2, 0.0,
		 0.0, 0.2, 0.3},

		{0.0, 0.2, 0.1,
		 0.0, 0.2, 0.0,
		 0.3, 0.2, 0.0},

		2.5
	);

	int test_num = 1;
	if (!case1.test_matrix_addeq({0.1, 0.4, 0.1,
	                              0.0, 0.4, 0.0,
	                              0.3, 0.4, 0.3})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_matrix_subeq({0.1, 0.0, -0.1,
	                              0.0, 0.0,  0.0,
	                             -0.3, 0.0,  0.3})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_matrix_muleq({0.00, 0.06, 0.03,
	                              0.00, 0.04, 0.00,
	                              0.03, 0.10, 0.00})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_matrix_diveq({0, 0, 1,
	                              0, 1, 0,
	                              1, 0, 0})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_matrix_add({0.1, 0.4, 0.1,
	                            0.0, 0.4, 0.0,
	                            0.3, 0.4, 0.3})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_matrix_sub({0.1, 0.0, -0.1,
	                            0.0, 0.0,  0.0,
	                           -0.3, 0.0,  0.3})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_matrix_mul({0.00, 0.06, 0.03,
	                            0.00, 0.04, 0.00,
	                            0.03, 0.10, 0.00})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_matrix_div({0, 0, 1,
	                            0, 1, 0,
	                            1, 0, 0})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_addeq({2.6, 2.7, 2.5,
	                             2.5, 2.7, 2.5,
	                             2.5, 2.7, 2.8})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_subeq({-2.4, -2.3, -2.5,
	                             -2.5, -2.3, -2.5,
	                             -2.5, -2.3, -2.2})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_muleq({0.25, 0.5, 0.00,
	                             0.00, 0.5, 0.00,
	                             0.00, 0.5, 0.75})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_diveq({0.04, 0.08, 0.00,
	                             0.00, 0.08, 0.00,
	                             0.00, 0.08, 0.12})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_add({2.6, 2.7, 2.5,
	                           2.5, 2.7, 2.5,
	                           2.5, 2.7, 2.8})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_sub({-2.4, -2.3, -2.5,
	                           -2.5, -2.3, -2.5,
	                           -2.5, -2.3, -2.2})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_mul({0.25, 0.5, 0.00,
	                           0.00, 0.5, 0.00,
	                           0.00, 0.5, 0.75})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_div({0.04, 0.08, 0.00,
	                           0.00, 0.08, 0.00,
	                           0.00, 0.08, 0.12})) {
		return test_num;
	}


	test_num++;
	if (case1.test_matrix_addeq({0.1, 0.4, 0.1,
	                             0.0, 0.0, 0.0,
	                             0.3, 0.4, 0.3})) {
		return test_num;
	}

	test_num++;
	if (case1.test_matrix_subeq({0.1, 0.0, -0.1,
	                             0.0, 1.0,  0.0,
	                            -0.3, 0.0,  0.3})) {
		return test_num;
	}

	test_num++;
	if (case1.test_matrix_muleq({0.00, 0.06, 0.03,
	                             0.00, 0.00, 0.00,
	                             0.03, 0.10, 0.00})) {
		return test_num;
	}

	test_num++;
	if (case1.test_matrix_diveq({0, 0, 1,
	                             0, 0, 0,
	                             1, 0, 0})) {
		return test_num;
	}

	test_num++;
	if (case1.test_matrix_add({0.1, 0.4, 0.1,
	                           0.0, 0.0, 0.0,
	                           0.3, 0.4, 0.3})) {
		return test_num;
	}

	test_num++;
	if (case1.test_matrix_sub({0.1, 0.0, -0.1,
	                           0.0, 1.0,  0.0,
	                          -0.3, 0.0,  0.3})) {
		return test_num;
	}

	test_num++;
	if (case1.test_matrix_mul({0.00, 0.06, 0.03,
	                           0.00, 0.00, 0.00,
	                           0.03, 0.10, 0.00})) {
		return test_num;
	}

	test_num++;
	if (case1.test_matrix_div({0, 0, 1,
	                           0, 0, 0,
	                           1, 0, 0})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_addeq({2.6, 2.7, 2.5,
	                            2.5, 0.0, 2.5,
	                            2.5, 2.7, 2.8})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_subeq({-2.4, -2.3, -2.5,
	                            -2.5,  0.0, -2.5,
	                            -2.5, -2.3, -2.2})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_muleq({0.25, 0.5, 0.00,
	                            0.00, 0.0, 0.00,
	                            0.00, 0.5, 0.75})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_diveq({0.04, 0.08, 0.00,
	                            0.00, 0.00, 0.00,
	                            0.00, 0.08, 0.12})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_add({2.6, 2.7, 2.5,
	                          2.5, 0.0, 2.5,
	                          2.5, 2.7, 2.8})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_sub({-2.4, -2.3, -2.5,
	                          -2.5,  0.0, -2.5,
	                          -2.5, -2.3, -2.2})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_mul({0.25, 0.5, 0.00,
	                          0.00, 0.0, 0.00,
	                          0.00, 0.5, 0.75})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_div({0.04, 0.08, 0.00,
	                          0.00, 0.00, 0.00,
	                          0.00, 0.08, 0.12})) {
		return test_num;
	}

	return 0;
}