cmake_minimum_required(VERSION 3.10)
project(StudyDataStructuresAlgorithms)

set(CMAKE_CXX_STANDARD 11)

# 检查MSVC版本
if (MSVC)
    message(WARNING "Leave windows please!")
    if (${MSVC_VERSION} LESS_EQUAL 1900)
        message(FATAL_ERROR "GO TO HELL!")
    endif ()
endif ()

# MSVC启用/utf-8
if (MSVC)
    add_compile_options(/utf-8)
endif ()

add_subdirectory(src)