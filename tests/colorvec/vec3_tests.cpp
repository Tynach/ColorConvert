#include <colorvec/vec3.h>
#include "test_types.h"
using colorvec::vec3;

class vec3_test: public test_base<vec3> {
public:
	vec3_test(vec3 init_vec, vec3 vec_value, floatp float_value):
		test_base(init_vec, vec_value, float_value)
	{}
};

int main()
{
	vec3_test case1 = vec3_test({0.0, 0.1, 0.2}, {1.0, 2.0, 3.0}, 2.0);

	int test_num = 1;
	if (!case1.test_same_addeq({1.0, 2.1, 3.2})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_subeq({-1.0, -1.9, -2.8})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_muleq({0.0, 0.2, 0.6})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_diveq({0.0, 0.05, 0.2/3.0})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_add({1.0, 2.1, 3.2})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_sub({-1.0, -1.9, -2.8})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_mul({0.0, 0.2, 0.6})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_same_div({0.0, 0.05, 0.2/3.0})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_addeq({2.0, 2.1, 2.2})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_subeq({-2.0, -1.9, -1.8})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_muleq({0.0, 0.2, 0.4})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_diveq({0.0, 0.05, 0.1})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_add({2.0, 2.1, 2.2})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_sub({-2.0, -1.9, -1.8})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_mul({0.0, 0.2, 0.4})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_float_div({0.0, 0.05, 0.1})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_equality({0.0, 0.1, 0.2})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_inequality({0.000001, 0.100001, 0.200001})) {
		return test_num;
	}


	test_num++;
	if (case1.test_same_addeq({1.01, 2.11, 3.21})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_subeq({-1.01, -1.91, -2.81})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_muleq({0.01, 0.21, 0.61})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_diveq({0.01, 0.051, 0.2/3.0 + 0.01})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_add({1.01, 2.11, 3.21})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_sub({-1.01, -1.91, -2.81})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_mul({0.01, 0.21, 0.61})) {
		return test_num;
	}

	test_num++;
	if (case1.test_same_div({0.01, 0.051, 0.2/3.0 + 0.01})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_addeq({2.01, 2.11, 2.21})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_subeq({-2.01, -1.91, -1.81})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_muleq({0.01, 0.21, 0.41})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_diveq({0.01, 0.051, 0.11})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_add({2.01, 2.11, 2.21})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_sub({-2.01, -1.91, -1.81})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_mul({0.01, 0.21, 0.41})) {
		return test_num;
	}

	test_num++;
	if (case1.test_float_div({0.01, 0.06, 0.11})) {
		return test_num;
	}

	test_num++;
	if (case1.test_equality({0.01, 0.11, 0.21})) {
		return test_num;
	}

	test_num++;
	if (case1.test_inequality({0.0, 0.1, 0.2})) {
		return test_num;
	}

	return 0;
}