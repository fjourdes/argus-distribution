cmake_minimum_required(VERSION 3.10)

include(GNUInstallDirs)

add_library(stb_image INTERFACE )
target_include_directories( stb_image INTERFACE
                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/stb_image>
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> )

set(STB_HEADERS 
    "stb_image.h"
    "stb_image_write.h")


install(FILES ${STB_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/stb_image)

add_subdirectory(glm)


