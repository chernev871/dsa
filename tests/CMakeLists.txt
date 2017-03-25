cmake_minimum_required (VERSION 3.7.1 FATAL_ERROR)

# Define variables
set (TEST_RUNNER test_runner)

file (GLOB_RECURSE TEST_SRC_LIST "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Configure test target
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/../include/")
add_executable (${TEST_RUNNER} ${TEST_SRC_LIST} ${SRC_LIST})

# Add desired warnings
if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
    target_compile_options( ${TEST_RUNNER} PRIVATE -Wall -Wextra )
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
    target_compile_options( ${TEST_RUNNER} PRIVATE /W4 /w44265 /WX )
endif()

# Run tests
add_test (
    NAME ${TEST_RUNNER}
    COMMAND ./${TEST_RUNNER}
)
