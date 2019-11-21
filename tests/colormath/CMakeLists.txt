set(transfer_tests_src transfer_tests.cpp)
set(transfer_tests_libs colorvec colormath)
add_executable(transfer_tests ${transfer_tests_src})
target_link_libraries(transfer_tests ${transfer_tests_libs})

set(color_space_tests_src color_space_tests.cpp)
set(color_space_tests_libs colorvec colormath)
add_executable(color_space_tests ${color_space_tests_src})
target_link_libraries(color_space_tests ${color_space_tests_libs})

add_test(NAME transfer_test COMMAND transfer_tests)
add_test(NAME color_space_test COMMAND color_space_tests)