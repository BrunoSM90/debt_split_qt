#CmakeListsServicesLib

cmake_minimum_required(VERSION 3.26.0)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/ServicesLib)

set(SERVICES_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/Services)
set(UTILS_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/Utils)

set(CURRENT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(SOURCE_ROOT "${CURRENT_SOURCE_DIR}/..")
set(MODELS_FOLDER ${SOURCE_ROOT}/ModelsLib)

MESSAGE(${MODELS_FOLDER})

set(SOURCES 
    ${SERVICES_FOLDER}/DividaService.h
    ${SERVICES_FOLDER}/DividaService.cpp
    ${SERVICES_FOLDER}/ParticipanteService.h
    ${SERVICES_FOLDER}/ParticipanteService.cpp
    ${SERVICES_FOLDER}/ProdutoService.h
    ${SERVICES_FOLDER}/ProdutoService.cpp
    ${UTILS_FOLDER}/InputValidator.h
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${SERVICES_FOLDER}"
    "${UTILS_FOLDER}"
    "${MODELS_FOLDER}"
)

add_library(ServicesLib STATIC ${SOURCES})

target_link_libraries(ServicesLib ModelsLib)