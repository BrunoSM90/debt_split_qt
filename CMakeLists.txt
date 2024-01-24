#CmakeListsRoot

cmake_minimum_required(VERSION 3.26.0)

project(Calculadora)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(ModelsLib)
add_subdirectory(PresentationLib)
add_subdirectory(ServicesLib)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/PresentationLib"
)

add_executable(Main main.cpp)

target_link_libraries(Main PresentationLib)