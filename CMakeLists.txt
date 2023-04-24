cmake_minimum_required(VERSION 3.2)

project("ogl_gen_reflection_code")

set(
    OGL_SOURCE

    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/input_args.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/input_args.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/debug.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/debug.hpp
)

add_executable(${CMAKE_PROJECT_NAME} ${OGL_SOURCE})

target_include_directories(
    ${CMAKE_PROJECT_NAME}

    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CMAKE_CXX_STANDARD 20)
