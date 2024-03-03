add_executable(ExampleCXX "CXX/Main.cpp")
target_link_libraries(ExampleCXX PRIVATE ForceWrite)

# Include C Support
add_subdirectory("../CWrapper" "CWrapper")

add_executable(ExampleCHeap "C/Heap.c")
target_link_libraries(ExampleCHeap PRIVATE ForceWriteCWrapper)
target_compile_options(ExampleCHeap PRIVATE "-Wno-int-conversion" "-Wno-pointer-integer-compare")

add_executable(ExampleCStack "C/Stack.c")
target_link_libraries(ExampleCStack PRIVATE ForceWriteCWrapper)
target_compile_options(ExampleCStack PRIVATE "-Wno-int-conversion" "-Wno-pointer-integer-compare")

add_test(NAME TestExampleCXX COMMAND $<TARGET_FILE:ExampleCXX>)
add_test(NAME TestExampleCHeap COMMAND $<TARGET_FILE:ExampleCHeap>)
add_test(NAME TestExampleCStack COMMAND $<TARGET_FILE:ExampleCStack>)