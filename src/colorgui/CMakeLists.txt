find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(colorgui_src transfer_gradient.cpp rgb_gradient.cpp)
set(colorgui_libs colormath Qt5::Widgets)
add_library(colorgui ${colorgui_src})
target_link_libraries(colorgui ${colorgui_libs})

set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTORCC OFF)
set(CMAKE_AUTOUIC OFF)