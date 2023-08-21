cmake_minimum_required(VERSION 3.20)

if(TARGET ForceWrite)
	return()
endif()

project(ForceWrite)
add_library(ForceWrite STATIC "${PROJECT_SOURCE_DIR}/Source/ForceWrite.cpp")
target_include_directories(ForceWrite PUBLIC "${PROJECT_SOURCE_DIR}/Include")
target_compile_features(ForceWrite PRIVATE cxx_std_98)
target_compile_options(ForceWrite PRIVATE "-Ofast" "-Wno-unused-result")

if(PROJECT_IS_TOP_LEVEL)
	add_executable(ForceWriteExample "${PROJECT_SOURCE_DIR}/Example/Main.cpp")
	target_link_libraries(ForceWriteExample PRIVATE ForceWrite)

	enable_testing()
	add_test(NAME ForceWriteExample COMMAND $<TARGET_FILE:ForceWriteExample>)
endif()

