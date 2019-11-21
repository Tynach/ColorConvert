set(vec3_tests_src vec3_tests.cpp)
set(vec3_tests_libs colorvec)
add_executable(vec3_tests ${vec3_tests_src})
target_link_libraries(vec3_tests ${vec3_tests_libs})

set(mat3_tests_src mat3_tests.cpp)
set(mat3_tests_libs colorvec)
add_executable(mat3_tests ${mat3_tests_src})
target_link_libraries(mat3_tests ${mat3_tests_libs})

add_test(NAME vec3_test COMMAND vec3_tests)
add_test(NAME mat3_test COMMAND mat3_tests)