cmake_minimum_required(VERSION 3.20)

include_guard()

project(ForceWrite)
add_library(ForceWrite STATIC "${PROJECT_SOURCE_DIR}/Source/ForceWrite.cpp")
target_include_directories(ForceWrite PUBLIC "${PROJECT_SOURCE_DIR}/Include")
target_compile_features(ForceWrite PRIVATE cxx_std_14)
target_compile_options(ForceWrite PRIVATE "-Ofast" "-Wno-unused-result")

if(PROJECT_IS_TOP_LEVEL)
	enable_testing()
	add_subdirectory("Example")
endif()

