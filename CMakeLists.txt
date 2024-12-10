cmake_minimum_required(VERSION 3.14)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_BINARY_DIR}/Debug/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_BINARY_DIR}/Debug/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_BINARY_DIR}/Debug/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release/bin)

# Ensure proper output directories for each build type (Debug/Release)
# set(CMAKE_BUILD_TYPE Debug)  # Default to Debug, can be overridden by the command line

if (NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()
# set(VCPKG_TARGET_TRIPLET=x64-windows)
set(VCPKG_TARGET_TRIPLET x64-mingw-dynamic CACHE STRING "")

project(vconfig)

add_library(vconfig STATIC
    vconfig/vconfig.hpp
    vconfig/vconfig.cpp
)

target_include_directories(vconfig PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})