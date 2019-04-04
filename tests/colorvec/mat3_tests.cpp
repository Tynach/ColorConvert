#include <colorvec/mat3.h>
#include "test_types.h"
using colorvec::mat3;

class mat3_test: public test_base<mat3> {
public:
	mat3_test(mat3 init_mat, mat3 mat_value, floatp float_value):
		test_base(init_mat, mat_value, float_value)
	{}
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
	if (!case1.test_same_addeq({0.1, 0.4, 0.1,
	                              0.0, 0.4, 0.0,
	                              0.3, 0.4, 0.3})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_subeq({0.1, 0.0, -0.1,
	                              0.0, 0.0,  0.0,
	                             -0.3, 0.0,  0.3})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_muleq({0.00, 0.06, 0.03,
	                              0.00, 0.04, 0.00,
	                              0.03, 0.10, 0.00})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_diveq({0, 0, 1,
	                              0, 1, 0,
	                              1, 0, 0})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_add({0.1, 0.4, 0.1,
	                            0.0, 0.4, 0.0,
	                            0.3, 0.4, 0.3})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_sub({0.1, 0.0, -0.1,
	                            0.0, 0.0,  0.0,
	                           -0.3, 0.0,  0.3})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_mul({0.00, 0.06, 0.03,
	                            0.00, 0.04, 0.00,
	                            0.03, 0.10, 0.00})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_div({0, 0, 1,
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
	if (case1.test_same_addeq({0.1, 0.4, 0.1,
	                             0.0, 0.0, 0.0,
	                             0.3, 0.4, 0.3})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_subeq({0.1, 0.0, -0.1,
	                             0.0, 1.0,  0.0,
	                            -0.3, 0.0,  0.3})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_muleq({0.00, 0.06, 0.03,
	                             0.00, 0.00, 0.00,
	                             0.03, 0.10, 0.00})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_diveq({0, 0, 1,
	                             0, 0, 0,
	                             1, 0, 0})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_add({0.1, 0.4, 0.1,
	                           0.0, 0.0, 0.0,
	                           0.3, 0.4, 0.3})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_sub({0.1, 0.0, -0.1,
	                           0.0, 1.0,  0.0,
	                          -0.3, 0.0,  0.3})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_mul({0.00, 0.06, 0.03,
	                           0.00, 0.00, 0.00,
	                           0.03, 0.10, 0.00})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_div({0, 0, 1,
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