cmake_minimum_required(VERSION 3.12)

include(GNUInstallDirs)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

find_package(Argus REQUIRED)
find_package(ArcSim REQUIRED)


file(GLOB DISPLAY_HEADERS "display/*.h")
file(GLOB DISPLAY_SOURCES "display/*.cpp")
add_library(display SHARED ${DISPLAY_SOURCES} ${DISPLAY_HEADERS})
target_link_libraries(display PUBLIC ${OPENGL_LIBRARIES} ${GLFW3_LIBRARY} GLEW::GLEW ArcSim::arcsim stb_image glm_headers)
target_include_directories(display PUBLIC
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/display>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                           $<BUILD_INTERFACE:${GLFW3_INCLUDE_DIR}>
                           )
target_compile_options(display PRIVATE -DBUILD_ARGUS_DISPLAY)
add_library(ArgusDistribution::display ALIAS display)

file(GLOB INTEGRATORS_HEADERS "integrators/*.h")
file(GLOB INTEGRATORS_SOURCES "integrators/*.cpp")
add_library(integrators SHARED ${INTEGRATORS_SOURCES} ${INTEGRATORS_HEADERS})
target_link_libraries(integrators PUBLIC Argus::interface ArcSim::arcsim)
target_include_directories(integrators PUBLIC 
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/integrators>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> )
target_compile_options(integrators PRIVATE -DBUILD_ARGUS_INTEGRATORS)
add_library(ArgusDistribution::integrators ALIAS integrators)


file(GLOB SIMULATORS_HEADERS "simulators/*.h")
file(GLOB SIMULATORS_SOURCES "simulators/*.cpp")
add_library(simulators SHARED ${SIMULATORS_SOURCES})
target_link_libraries(simulators PUBLIC ArcSim::arcsim display integrators)
target_include_directories(simulators PUBLIC 
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/simulators>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> )
target_compile_options(simulators PRIVATE -DBUILD_ARGUS_SIMULATORS)
add_library(ArgusDistribution::simulators ALIAS simulators)


file(GLOB APPLICATIONS_HEADERS "applications/*.cpp")
file(GLOB APPLICATIONS_SOURCES "applications/*.cpp")
add_library(applications SHARED ${APPLICATIONS_SOURCES} ${APPLICATIONS_HEADERS})
target_link_libraries(applications PUBLIC simulators integrators)
target_include_directories(applications PUBLIC
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/applications>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> )
target_compile_options(applications PRIVATE -DBUILD_ARGUS_APPLICATIONS)
add_library(ArgusDistribution::applications ALIAS applications)


install(TARGETS display integrators simulators applications stb_image glm_headers
        EXPORT ArgusDistributionTargets
        INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
        RUNTIME DESTINATION  "${CMAKE_INSTALL_BINDIR}"
        LIBRARY DESTINATION  "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION  "${CMAKE_INSTALL_LIBDIR}"
)

install(FILES ${DISPLAY_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/argus/display )
install(FILES ${INTEGRATORS_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/argus/integrators )
install(FILES ${SIMULATORS_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/argus/simulators )
install(FILES ${APPLICATIONS_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/argus/applications )

include(CMakePackageConfigHelpers)

configure_package_config_file(ArgusDistributionConfig.cmake.in
    ${CMAKE_BINARY_DIR}/ArgusDistribution/ArgusDistributionConfig.cmake
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/ArgusDistribution"
)

install(FILES ${CMAKE_BINARY_DIR}/ArgusDistribution/ArgusDistributionConfig.cmake
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/ArgusDistribution")

install( EXPORT ArgusDistributionTargets
        NAMESPACE "ArgusDistribution::"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/ArgusDistribution")
