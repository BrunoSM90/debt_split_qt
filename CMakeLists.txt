#CmakeListsRoot

cmake_minimum_required(VERSION 3.26.0)

project(Calculadora)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(View)

add_executable(Calculadora main.cpp)

target_link_libraries(Calculadora View)