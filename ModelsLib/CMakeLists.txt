#CmakeListsModelsLib

cmake_minimum_required(VERSION 3.26.0)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/ModelsLib)
set(MODELS_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/Models)

set(SOURCES 
    ${MODELS_FOLDER}/Participante.h
    ${MODELS_FOLDER}/Participante.cpp
    ${MODELS_FOLDER}/Produto.h
    ${MODELS_FOLDER}/Produto.cpp
)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${MODELS_FOLDER}"
)

add_library(ModelsLib STATIC ${SOURCES})