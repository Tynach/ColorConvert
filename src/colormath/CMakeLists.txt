set(colormath_src color_space.cpp transfer.cpp)
add_library(colormath ${colormath_src})
target_link_libraries(colormath colorvec)