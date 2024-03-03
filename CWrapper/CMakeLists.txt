cmake_minimum_required(VERSION 3.20)

include_guard()

project(ForceWriteCWrapper)

add_library(ForceWriteCWrapper STATIC "${PROJECT_SOURCE_DIR}/Source/ForceWriteWrapper.cpp")
target_include_directories(ForceWriteCWrapper PUBLIC "${PROJECT_SOURCE_DIR}/Include")
target_compile_options(ForceWriteCWrapper PRIVATE "-Ofast" "-Wno-conversion-null")
target_compile_features(ForceWriteCWrapper PRIVATE cxx_std_17)

target_link_libraries(ForceWriteCWrapper PUBLIC ForceWrite)
