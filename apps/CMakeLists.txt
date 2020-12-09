cmake_minimum_required(VERSION 3.12)

set(SOURCES argus_cloth.cpp)

add_executable(argus-cloth ${SOURCES})

target_link_libraries(argus-cloth PUBLIC applications ArcSim::arcsim)