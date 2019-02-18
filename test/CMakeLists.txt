# ------------------------
# Unit Tests
# ------------------------
if(WINDOWS)
    message("Running on windows.. do not launch tests")
else()
    set(PROJECT_TEST_FILES test_hello.cpp)

    add_executable(tests ${PROJECT_TEST_FILES})

    # Standard linking to gtest stuff.
    #set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads)
    target_link_libraries(tests PRIVATE project_src_lib gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})

    # This is so you can do 'make test' to see all your tests run, instead of
    # manually running the executable runUnitTests to see those specific tests.
    add_test(tests tests)
endif()