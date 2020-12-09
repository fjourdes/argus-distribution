cmake_minimum_required(VERSION 3.12)

set(SOURCES argus_cloth.cpp)

include(GNUInstallDirs)

find_package(ArgusDistribution REQUIRED)

add_executable(argus-cloth ${SOURCES})

target_link_libraries(argus-cloth PUBLIC ArgusDistribution::applications)

install(TARGETS argus-cloth
        RUNTIME DESTINATION  "${CMAKE_INSTALL_BINDIR}")

