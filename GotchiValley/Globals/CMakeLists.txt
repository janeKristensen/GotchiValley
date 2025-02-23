﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

file(GLOB GLOBALS_SRC CMAKE_CONFIGURE_DEPENDS "*.cpp")

add_library (Globals ${GLOBALS_SRC})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Globals PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(Globals PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the SFML path
set(SFML_DIR ${CMAKE_SOURCE_DIR}/external/SFML-3.0.0)

# Add the include directory
include_directories(
    ${SFML_DIR}/include
)

# Link SFML libraries
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(Globals 
    Managers
    ${SFML_DIR}/lib/sfml-system-d.lib
    ${SFML_DIR}/lib/sfml-window-d.lib
    ${SFML_DIR}/lib/sfml-graphics-d.lib
    )
else()
    target_link_libraries(Globals
    Managers
    ${SFML_DIR}/lib/sfml-system.lib
    ${SFML_DIR}/lib/sfml-window.lib
    ${SFML_DIR}/lib/sfml-graphics.lib
)
endif()











