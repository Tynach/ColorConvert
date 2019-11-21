find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(gui_tests_src gui_tests.cpp)
set(gui_tests_libs colorgui)
add_executable(gui_tests ${gui_tests_src})
target_link_libraries(gui_tests ${gui_tests_libs})

set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTORCC OFF)
set(CMAKE_AUTOUIC OFF)

add_test(NAME gui_test COMMAND gui_tests)