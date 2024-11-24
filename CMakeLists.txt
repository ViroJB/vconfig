cmake_minimum_required(VERSION 3.14)

project(vconfig)

add_library(vconfig
    vconfig/vconfig.hpp
    vconfig/vconfig.cpp
)

target_include_directories(vconfig PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})