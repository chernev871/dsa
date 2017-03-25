cmake_minimum_required (VERSION 3.7.1 FATAL_ERROR)

project (dsa CXX)

# Enable C++14
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# Configurable variables
## Features
set (ENABLE_TESTING ON CACHE BOOL "Enable unit tests")

# Add self includes
include_directories ("ext")
include_directories ("include")

# Add unit tests
if (ENABLE_TESTING)
    enable_testing()
    add_subdirectory (tests)
    message (STATUS "Unit tests status: ENABLED")
else (ENABLE_TESTING)
    message (STATUS "Unit tests status: DISABLED")
endif (ENABLE_TESTING)
