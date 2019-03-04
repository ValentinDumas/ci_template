set(PROJECT_SOURCE_FILES complex.cpp)

add_library(project_src_lib ${PROJECT_SOURCE_FILES})

target_include_directories(project_src_lib PUBLIC ${PROJECT_SOURCE_DIR}/include) # Note: see if it includes .hpp && .cpp OR only .cpp files

target_link_libraries(project_src_lib PUBLIC coverage_config warnings_config) # Include code-coverage & warnings settings

# ------------------------------------------------------------------------------
# Main Executable
# ------------------------------------------------------------------------------
add_executable(ci_template main.cpp)

# pthread not needed !
target_link_libraries(ci_template project_src_lib)

target_compile_definitions(ci_template PRIVATE main=main)