#CmakeListsPresentationLib

cmake_minimum_required(VERSION 3.26.0)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/PresentationLib)

set(PRESENTER_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/Presenter)
set(WRAPPER_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/Wrapper)
set(VIEW_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/View)

set(SERVICES_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/../ServicesLib)

set(SOURCES 
    ${PRESENTER_FOLDER}/CalculadoraPresenter.h
    ${PRESENTER_FOLDER}/CalculadoraPresenter.cpp
    ${WRAPPER_FOLDER}/CalculadoraWrapper.h
    ${WRAPPER_FOLDER}/CalculadoraWrapper.cpp
    ${VIEW_FOLDER}/mainwindow.h
    ${VIEW_FOLDER}/mainwindow.cpp
    ${VIEW_FOLDER}/mainwindow.ui
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${PRESENTER_FOLDER}"
    "${WRAPPER_FOLDER}"
    "${VIEW_FOLDER}"
    "${SERVICES_FOLDER}"
)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Charts REQUIRED)

add_library(PresentationLib STATIC ${SOURCES})

target_link_libraries(PresentationLib ServicesLib Qt5::Widgets Qt5::Charts Qt5::Core)