cmake_minimum_required(VERSION 3.14)
project(viewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR /bin)

find_package(Qt5Widgets REQUIRED)

file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

file(GLOB uis ${CMAKE_CURRENT_SOURCE_DIR}/uis/*.ui)
file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB resources ${CMAKE_CURRENT_SOURCE_DIR}/qrc/*.qrc)

qt5_wrap_ui(ui_headers ${uis})
qt5_wrap_cpp(moc_srcs ${headers})
qt5_add_resources(rcc ${resources})

add_executable(viewer main.cpp ${sources} ${uis} ${moc_srcs} ${rcc})
target_link_libraries(viewer Qt5::Widgets)

target_include_directories(viewer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(viewer PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

