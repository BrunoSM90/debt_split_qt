#CmakeListsView

cmake_minimum_required(VERSION 3.26.0)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/View)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

file(GLOB SOURCES *.h *.cpp *.ui)
    
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Charts REQUIRED)

add_library(View STATIC ${SOURCES} )

target_link_libraries(View Qt5::Widgets Qt5::Charts Qt5::Core)