set(vec3_tests_src vec3_tests.cpp)
add_executable(vec3_tests ${vec3_tests_src})
add_test(NAME vec3_test COMMAND vec3_tests)

set(mat3_tests_src mat3_tests.cpp)
add_executable(mat3_tests ${mat3_tests_src})
add_test(NAME mat3_test COMMAND mat3_tests)