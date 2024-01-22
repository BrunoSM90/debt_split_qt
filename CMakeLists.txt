cmake_minimum_required(VERSION 3.26.0)

project(Main)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
   
set(src
    mainwindow.cpp;
    mainwindow.h
    mainwindow.ui;
)
    
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Charts REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(source STATIC ${src} )
target_link_libraries(source Qt5::Widgets Qt5::Charts Qt5::Core)

add_executable(Main main.cpp)

target_link_libraries(Main source)