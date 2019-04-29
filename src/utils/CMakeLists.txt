project(utils)

# TODO: it may be nice to separate some of the headers into "independant libraries"

# ------------------------------------------------------------------------------
# Mathematics Target Details
# ------------------------------------------------------------------------------
set(${PROJECT_NAME}_SOURCE_FILES types.cpp)

# ------------------------------------------------------------------------------
# Mathematics Target Library
# ------------------------------------------------------------------------------
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}) # Note: see if it includes .hpp && .cpp OR only .cpp files

target_link_libraries(${PROJECT_NAME} INTERFACE coverage_config) # Include code-coverage & warnings settings

add_data_to_property(P_PROJECT_SOURCE_MODULES ${PROJECT_NAME})
AddLibraryToProject(${PROJECT_NAME})