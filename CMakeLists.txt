cmake_minimum_required(VERSION 3.20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(APP_NAME "vconfig")

project(${APP_NAME} VERSION 1.0 LANGUAGES CXX)

add_library(${APP_NAME} STATIC
    vconfig/vconfig.hpp
    vconfig/vconfig.cpp
)
target_include_directories(${APP_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# Only enable tests when this is the main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    enable_testing()
    add_subdirectory(tests)
endif()