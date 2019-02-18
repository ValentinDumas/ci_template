cmake_minimum_required(VERSION 3.6)
project(ci_base C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(ExternalProject)
find_package(Git REQUIRED)

# ------------------------------------------------------------------------------
# Includes
# ------------------------------------------------------------------------------
include_directories(deps) # Incude all dependencies & external libraries
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
# Note: could do ${HEADER_FILES} ${SOURCE_FILES}
# OR a GLOB RECURSE to get all .h .c .cpp files in target folders
add_library(project_src_lib STATIC include/hello.h src/hello.cpp)

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
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------
include(CTest) # enable_tests()
add_subdirectory(test)
