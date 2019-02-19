cmake_minimum_required(VERSION 3.6)
project(ci_template C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

# ------------------------------------------------------------------------------
# Includes
# ------------------------------------------------------------------------------
#include_directories(deps) # Incude all dependencies & external libraries
include_directories(${PROJECT_SOURCE_DIR}/include) # current project includes
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}) # Gtest includes

# --------------
# Call Others CMakeLists
# --------------
add_subdirectory(deps)
#add_subdirectory(include)
add_subdirectory(src)

# ------------------------------------------------------------------------------
# Custom Libraries
# ------------------------------------------------------------------------------
# Note: "glob recurse" to get all .h .c .cpp files in target folders ?
add_library(project_src_lib STATIC src/hello.cpp)

# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------
include(CTest) # enable_tests()

# ------------------------------------------------------------------------------
# OS Specific Options
# ------------------------------------------------------------------------------
if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

#option(CMAKE_USE_WIN32_THREADS_INIT "using WIN32 threads" ON)
#option(gtest_disable_pthreads "Disable uses of pthreads in gtest." ON)

# ------------------------------------------------------------------------------
# Coverage
# ------------------------------------------------------------------------------
if(ENABLE_COVERAGE)
    set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# ------------------------
# Unit Tests
# ------------------------
set(PROJECT_TEST_FILES test/test_hello.cpp)

add_executable(tests ${PROJECT_TEST_FILES})

# Standard linking to gtest stuff.
#set(THREADS_PREFER_PTHREAD_FLAG ON)
target_link_libraries(tests gtest gtest_main)
target_link_libraries(tests project_src_lib)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(tests tests)

#add_subdirectory(test)
