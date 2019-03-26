#include <vecmath/mat3.h>
using vecmath::mat3;

class mat3_test {
	const mat3 initial;
	const mat3 test_vector;
	const floatp test_float;

	// Hopefully 2^-17 is more than large enough for fair float equality
	constexpr static floatp tolerance = 0.00000762939453125;

	bool test_equals(const mat3& test, const mat3& expected)
	{
		// Manually generate a matrix with slightly lower values, and
		// one with slightly higher values (vector operator overloads
		// are assumed to work, though are tested in vec3_tests.cpp)
		mat3 lower = {expected.x - tolerance,
		              expected.y - tolerance,
		              expected.z - tolerance};

		mat3 upper = {expected.x + tolerance,
		              expected.y + tolerance,
		              expected.z + tolerance};

		// Perform the test via a sequence of boolean AND operations, so
		// that if any of them return 'false' the rest of them will too
		bool result = true;

		result &= test.x.x >= lower.x.x;
		result &= test.x.y >= lower.x.y;
		result &= test.x.z >= lower.x.z;
		result &= test.y.x >= lower.y.x;
		result &= test.y.y >= lower.y.y;
		result &= test.y.z >= lower.y.z;
		result &= test.z.x >= lower.z.x;
		result &= test.z.y >= lower.z.y;
		result &= test.z.z >= lower.z.z;

		result &= test.x.x <= upper.x.x;
		result &= test.x.y <= upper.x.y;
		result &= test.x.z <= upper.x.z;
		result &= test.y.x <= upper.y.x;
		result &= test.y.y <= upper.y.y;
		result &= test.y.z <= upper.y.z;
		result &= test.z.x <= upper.z.x;
		result &= test.z.y <= upper.z.y;
		result &= test.z.z <= upper.z.z;

		return result;
	}

public:
	mat3_test(mat3 init_mat, mat3 mat_value, floatp float_value):
		initial(init_mat),
		test_vector(mat_value),
		test_float(float_value)
	{}

	// Test operators where the right-hand side is a mat3
	bool test_matrix_addeq(const mat3& expected)
	{
		mat3 copy = initial;
		copy += test_vector;

		return test_equals(copy, expected);
	}

	bool test_matrix_subeq(const mat3& expected)
	{
		mat3 copy = initial;
		copy -= test_vector;

		return test_equals(copy, expected);
	}

	bool test_matrix_muleq(const mat3& expected)
	{
		mat3 copy = initial;
		copy *= test_vector;

		return test_equals(copy, expected);
	}

	bool test_matrix_diveq(const mat3& expected)
	{
		mat3 copy = initial;
		copy /= test_vector;

		return test_equals(copy, expected);
	}

	bool test_matrix_add(const mat3& expected)
	{return test_equals(initial + test_vector, expected);}

	bool test_matrix_sub(const mat3& expected)
	{return test_equals(initial - test_vector, expected);}

	bool test_matrix_mul(const mat3& expected)
	{return test_equals(initial*test_vector, expected);}

	bool test_matrix_div(const mat3& expected)
	{return test_equals(initial/test_vector, expected);}

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
		{0.1, 0.2, 0.3,
		 0.4, 0.5, 0.6,
		 0.7, 0.8, 0.9},

		{0.2, 0.4, 0.6,
		 0.8, 1.0, 1.2,
		 1.4, 1.6, 1.8},

		2.5
	);

	int test_num = 1;
	if (!case1.test_matrix_addeq({0.3, 0.6, 0.9,
	                              1.2, 1.5, 1.8,
	                              2.1, 2.4, 2.7})) {
		return test_num;
	}

	/*mat3 foo = {0.0, 0.1, 0.2,
	            0.3, 0.4, 0.5,
	            0.6, 0.7, 0.8};

	// float operator overload tests
	mat3 correct_af = {foo.x + 2.0, foo.y + 2.0, foo.z + 2.0};
	mat3 correct_sf = {foo.x - 2.0, foo.y - 2.0, foo.z - 2.0};
	mat3 correct_mf = {foo.x*2.0, foo.y*2.0, foo.z*2.0};
	mat3 correct_df = {foo.x/2.0, foo.y/2.0, foo.z/2.0};

	mat3 correct_afe = {foo.x + 2.0, foo.y + 2.0, foo.z + 2.0};
	mat3 correct_sfe = {foo.x - 2.0, foo.y - 2.0, foo.z - 2.0};
	mat3 correct_mfe = {foo.x*2.0, foo.y*2.0, foo.z*2.0};
	mat3 correct_dfe = {foo.x/2.0, foo.y/2.0, foo.z/2.0};

	mat3 test_afe = foo;
	mat3 test_sfe = foo;
	mat3 test_mfe = foo;
	mat3 test_dfe = foo;
	test_afe += 2.0;
	test_sfe -= 2.0;
	test_mfe *= 2.0;
	test_dfe /= 2.0;


	// mat3 operator overload tests
	mat3 right = {1.0, 2.0, 3.0,
	              4.0, 5.0, 6.0,
	              7.0, 8.0, 9.0};

	mat3 correct_am = {foo.x + right.x, foo.y + right.y, foo.z + right.z};
	mat3 correct_sm = {foo.x - right.x, foo.y - right.y, foo.z - right.z};
	//mat3 correct_mm = {foo.x*right.x, foo.y*right.y, foo.z*right.z};
	//mat3 correct_dm = {foo.x/right.x, foo.y/right.y, foo.z/right.z};

	mat3 correct_ame = {foo.x + right.x, foo.y + right.y, foo.z + right.z};
	mat3 correct_sme = {foo.x - right.x, foo.y - right.y, foo.z - right.z};
	//mat3 correct_mme = {foo.x*right.x, foo.y*right.y, foo.z*right.z};
	//mat3 correct_dme = {foo.x/right.x, foo.y/right.y, foo.z/right.z};

	mat3 test_ame = foo;
	mat3 test_sme = foo;
	//mat3 test_mme = foo;
	//mat3 test_dme = foo;
	test_ame += right;
	test_sme -= right;
	//test_mme *= right;
	//test_dme /= right;

	if (correct_af != foo + 2.0 || correct_af == foo + 2.1) {
		return 1;
	} else if (correct_sf != foo - 2.0 || correct_sf == foo - 2.1) {
		return 2;
	} else if (correct_mf != foo*2.0 || correct_mf == foo*2.1) {
		return 3;
	} else if (correct_df != foo/2.0 || correct_df == foo/2.1) {
		return 4;
	} else if (correct_afe != test_afe || correct_afe == test_afe + 0.1) {
		return 5;
	} else if (correct_sfe != test_sfe || correct_sfe == test_sfe - 0.1) {
		return 6;
	} else if (correct_mfe != test_mfe || correct_mfe == test_mfe*1.1) {
		return 7;
	} else if (correct_dfe != test_dfe || correct_dfe == test_dfe/1.1) {
		return 8;
	} else if (correct_am != foo + right || correct_am == foo + right + 0.1) {
		return 9;
	} else if (correct_sm != foo - right || correct_sm == foo - right - 0.1) {
		return 10;
	} *//*else if (correct_mm != foo*right || correct_mm == foo*right*1.1) {
		return 11;
	} else if (correct_dm != foo/right || correct_dm == foo/right/1.1) {
		return 12;
	} *//*else if (correct_ame != test_ame || correct_ame == test_ame + right + 0.1) {
		return 13;
	} else if (correct_sme != test_sme || correct_sme == test_sme + right - 0.1) {
		return 14;
	} *//*else if (correct_mme != test_mme || correct_mme == test_mfe*right*1.1) {
		return 15;
	} else if (correct_dme != test_dme || correct_dme == test_dfe/right/1.1) {
		return 16;
	}*/

	return 0;
}