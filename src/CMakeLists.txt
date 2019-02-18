# ------------------------------------------------------------------------------
# Main Executable
# ------------------------------------------------------------------------------
set(PROJECT_SOURCE_FILES hello.cpp)

add_executable(ci_base main.cpp)

target_link_libraries(ci_base project_src_lib)