add_subdirectory(${CMAKE_SOURCE_DIR}/googletest googletest)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(testPrintTree testPrintTree.cc)
target_link_libraries(testPrintTree print_tree gtest gtest_main)

add_test(NAME testPrintTree COMMAND testPrintTree)