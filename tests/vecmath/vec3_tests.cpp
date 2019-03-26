#include <vecmath/vec3.h>
using vecmath::vec3;

class vec3_test {
	const vec3 initial;
	const vec3 test_vector;
	const floatp test_float;

	// Hopefully 2^-17 is more than large enough for fair float equality
	constexpr static floatp tolerance = 0.00000762939453125;

	bool test_equals(const vec3& test, const vec3& expected)
	{
		// Manually generate a vector with slightly lower values, and
		// one with slightly higher values
		vec3 lower = {expected.x - tolerance,
		              expected.y - tolerance,
		              expected.z - tolerance};

		vec3 upper = {expected.x + tolerance,
		              expected.y + tolerance,
		              expected.z + tolerance};

		// Perform the test via a sequence of boolean AND operations, so
		// that if any of them return 'false' the rest of them will too
		bool result = true;

		result &= test.x >= lower.x;
		result &= test.y >= lower.y;
		result &= test.z >= lower.z;

		result &= test.x <= upper.x;
		result &= test.y <= upper.y;
		result &= test.z <= upper.z;

		return result;
	}

public:
	vec3_test(vec3 init_vec, vec3 vec_value, floatp float_value):
		initial(init_vec),
		test_vector(vec_value),
		test_float(float_value)
	{}

	// Test operators where the right-hand side is a vec3
	bool test_vector_addeq(const vec3& expected)
	{
		vec3 copy = initial;
		copy += test_vector;

		return test_equals(copy, expected);
	}

	bool test_vector_subeq(const vec3& expected)
	{
		vec3 copy = initial;
		copy -= test_vector;

		return test_equals(copy, expected);
	}

	bool test_vector_muleq(const vec3& expected)
	{
		vec3 copy = initial;
		copy *= test_vector;

		return test_equals(copy, expected);
	}

	bool test_vector_diveq(const vec3& expected)
	{
		vec3 copy = initial;
		copy /= test_vector;

		return test_equals(copy, expected);
	}

	bool test_vector_add(const vec3& expected)
	{
		return test_equals(initial + test_vector, expected);
	}

	bool test_vector_sub(const vec3& expected)
	{
		return test_equals(initial - test_vector, expected);
	}

	bool test_vector_mul(const vec3& expected)
	{
		return test_equals(initial*test_vector, expected);
	}

	bool test_vector_div(const vec3& expected)
	{
		return test_equals(initial/test_vector, expected);
	}

	// Test operators where the right-hand side is a floatp
	bool test_float_addeq(const vec3& expected)
	{
		vec3 copy = initial;
		copy += test_float;

		return test_equals(copy, expected);
	}

	bool test_float_subeq(const vec3& expected)
	{
		vec3 copy = initial;
		copy -= test_float;

		return test_equals(copy, expected);
	}

	bool test_float_muleq(const vec3& expected)
	{
		vec3 copy = initial;
		copy *= test_float;

		return test_equals(copy, expected);
	}

	bool test_float_diveq(const vec3& expected)
	{
		vec3 copy = initial;
		copy /= test_float;

		return test_equals(copy, expected);
	}

	bool test_float_add(const vec3& expected)
	{
		return test_equals(initial + test_float, expected);
	}

	bool test_float_sub(const vec3& expected)
	{
		return test_equals(initial - test_float, expected);
	}

	bool test_float_mul(const vec3& expected)
	{
		return test_equals(initial*test_float, expected);
	}

	bool test_float_div(const vec3& expected)
	{
		return test_equals(initial/test_float, expected);
	}

	// Test the logical (in)equality operators
	bool test_equality(const vec3& expected)
	{
		// Test absolute equality, without tolerance
		bool result = true;

		result &= initial.x == expected.x;
		result &= initial.y == expected.y;
		result &= initial.z == expected.z;

		return result;
	}

	bool test_inequality(const vec3& expected)
	{
		bool result = true;

		result &= initial.x != expected.x;
		result &= initial.y != expected.y;
		result &= initial.z != expected.z;

		return result;
	}
};

int main()
{
	vec3_test case1 = vec3_test({0.0, 0.1, 0.2}, {1.0, 2.0, 3.0}, 2.0);

	int test_num = 1;
	if (!case1.test_vector_addeq({1.0, 2.1, 3.2})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_vector_subeq({-1.0, -1.9, -2.8})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_vector_muleq({0.0, 0.2, 0.6})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_vector_diveq({0.0, 0.05, 0.2/3.0})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_vector_add({1.0, 2.1, 3.2})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_vector_sub({-1.0, -1.9, -2.8})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_vector_mul({0.0, 0.2, 0.6})) {
		return test_num;
	}

	test_num++;
	if (!case1.test_vector_div({0.0, 0.05, 0.2/3.0})) {
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
	if (case1.test_vector_addeq({1.01, 2.11, 3.21})) {
		return test_num;
	}

	test_num++;
	if (case1.test_vector_subeq({-1.01, -1.91, -2.81})) {
		return test_num;
	}

	test_num++;
	if (case1.test_vector_muleq({0.01, 0.21, 0.61})) {
		return test_num;
	}

	test_num++;
	if (case1.test_vector_diveq({0.01, 0.051, 0.2/3.0 + 0.01})) {
		return test_num;
	}

	test_num++;
	if (case1.test_vector_add({1.01, 2.11, 3.21})) {
		return test_num;
	}

	test_num++;
	if (case1.test_vector_sub({-1.01, -1.91, -2.81})) {
		return test_num;
	}

	test_num++;
	if (case1.test_vector_mul({0.01, 0.21, 0.61})) {
		return test_num;
	}

	test_num++;
	if (case1.test_vector_div({0.01, 0.051, 0.2/3.0 + 0.01})) {
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