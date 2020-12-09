cmake_minimum_required(VERSION 3.12)

project(Argus-distribution)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

# Visual studio solution directories.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


include(GNUInstallDirs)

if((CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT))
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/build/apps" CACHE PATH "Prefix prepended to install directories" FORCE)
    message(STATUS "Setting default CMAKE_INSTALL_PREFIX to: ${CMAKE_INSTALL_PREFIX}")
endif()

# Set the output directories globally
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

####
# Compiler flags
####

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE "Release")
endif()


# Maybe dangerous to set -O3 globally...
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

set(ARCSIM_WITH_BOOST  ON CACHE INTERNAL "")
# set(ARCSIM_WITH_BOOST TRUE CACHE )

option(BUILD_SHARED_LIBS "" ON)

find_package(Eigen3 REQUIRED)

# add_definitions(-DSILENCE_ARGUS)

add_subdirectory("../SofaWinDependencies" SofaWinDependencies)

add_subdirectory(${PROJECT_SOURCE_DIR}/external)

add_subdirectory(${PROJECT_SOURCE_DIR}/deps/bogus-interface/extern/so-bogus/bogus)

add_subdirectory(${PROJECT_SOURCE_DIR}/deps/bogus-interface/interface)

add_subdirectory(${PROJECT_SOURCE_DIR}/deps/libarcsim)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(${PROJECT_SOURCE_DIR}/apps)
