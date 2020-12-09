cmake_minimum_required(VERSION 3.12)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

find_package(Argus REQUIRED)
find_package(ArcSim REQUIRED)


file(GLOB DISPLAY_SOURCES "display/*")
add_library(display SHARED ${DISPLAY_SOURCES})
target_link_libraries(display PUBLIC ${OPENGL_LIBRARIES} ${GLFW3_LIBRARY} GLEW::GLEW ArcSim::arcsim ArgusExternal)
target_include_directories(display PUBLIC 
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                           $<BUILD_INTERFACE:${GLFW3_INCLUDE_DIR}>
                           )
target_compile_options(display PRIVATE -DBUILD_ARGUS_DISPLAY)


file(GLOB INTEGRATORS_SOURCES "integrators/*")
add_library(integrators SHARED ${INTEGRATORS_SOURCES})
target_link_libraries(integrators PUBLIC Argus::interface ArcSim::arcsim)
target_include_directories(integrators PUBLIC 
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> )
target_compile_options(integrators PRIVATE -DBUILD_ARGUS_INTEGRATORS)


file(GLOB SIMULATORS_SOURCES "simulators/*")
add_library(simulators SHARED ${SIMULATORS_SOURCES})
target_link_libraries(simulators PUBLIC ArcSim::arcsim display integrators)
target_include_directories(simulators PUBLIC 
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> )
target_compile_options(simulators PRIVATE -DBUILD_ARGUS_SIMULATORS)


file(GLOB SYSTEM_SOURCES "applications/*")
add_library(applications SHARED ${SYSTEM_SOURCES})
target_link_libraries(applications PUBLIC simulators integrators)
target_include_directories(applications PUBLIC 
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> )
target_compile_options(applications PRIVATE -DBUILD_ARGUS_APPLICATIONS)
