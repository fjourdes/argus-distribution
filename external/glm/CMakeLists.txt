file(GLOB ROOT_SOURCE *.cpp)
file(GLOB ROOT_INLINE *.inl)
file(GLOB ROOT_HEADER *.hpp)
file(GLOB ROOT_TEXT ../*.txt)
file(GLOB ROOT_MD ../*.md)
file(GLOB ROOT_NAT ../util/glm.natvis)

file(GLOB_RECURSE CORE_SOURCE ./detail/*.cpp)
file(GLOB_RECURSE CORE_INLINE ./detail/*.inl)
file(GLOB_RECURSE CORE_HEADER ./detail/*.hpp)

file(GLOB_RECURSE EXT_SOURCE ./ext/*.cpp)
file(GLOB_RECURSE EXT_INLINE ./ext/*.inl)
file(GLOB_RECURSE EXT_HEADER ./ext/*.hpp)

file(GLOB_RECURSE GTC_SOURCE ./gtc/*.cpp)
file(GLOB_RECURSE GTC_INLINE ./gtc/*.inl)
file(GLOB_RECURSE GTC_HEADER ./gtc/*.hpp)

file(GLOB_RECURSE GTX_SOURCE ./gtx/*.cpp)
file(GLOB_RECURSE GTX_INLINE ./gtx/*.inl)
file(GLOB_RECURSE GTX_HEADER ./gtx/*.hpp)

file(GLOB_RECURSE SIMD_SOURCE ./simd/*.cpp)
file(GLOB_RECURSE SIMD_INLINE ./simd/*.inl)
file(GLOB_RECURSE SIMD_HEADER ./simd/*.h)

source_group("Text Files" FILES ${ROOT_TEXT} ${ROOT_MD})
source_group("Core Files" FILES ${CORE_SOURCE})
source_group("Core Files" FILES ${CORE_INLINE})
source_group("Core Files" FILES ${CORE_HEADER})
source_group("EXT Files" FILES ${EXT_SOURCE})
source_group("EXT Files" FILES ${EXT_INLINE})
source_group("EXT Files" FILES ${EXT_HEADER})
source_group("GTC Files" FILES ${GTC_SOURCE})
source_group("GTC Files" FILES ${GTC_INLINE})
source_group("GTC Files" FILES ${GTC_HEADER})
source_group("GTX Files" FILES ${GTX_SOURCE})
source_group("GTX Files" FILES ${GTX_INLINE})
source_group("GTX Files" FILES ${GTX_HEADER})
source_group("SIMD Files" FILES ${SIMD_SOURCE})
source_group("SIMD Files" FILES ${SIMD_INLINE})
source_group("SIMD Files" FILES ${SIMD_HEADER})

add_library(glm_headers INTERFACE)
target_include_directories(glm_headers INTERFACE
                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>)

add_library(glm_static STATIC ${ROOT_TEXT} ${ROOT_MD} ${ROOT_NAT}
	${ROOT_SOURCE}    ${ROOT_INLINE}    ${ROOT_HEADER}
	${CORE_SOURCE}    ${CORE_INLINE}    ${CORE_HEADER}
	${EXT_SOURCE}     ${EXT_INLINE}     ${EXT_HEADER}
	${GTC_SOURCE}     ${GTC_INLINE}     ${GTC_HEADER}
	${GTX_SOURCE}     ${GTX_INLINE}     ${GTX_HEADER}
	${SIMD_SOURCE}    ${SIMD_INLINE}    ${SIMD_HEADER})

target_include_directories(glm_static PUBLIC
                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../> )


add_library(glm_shared SHARED ${ROOT_TEXT} ${ROOT_MD} ${ROOT_NAT}
	${ROOT_SOURCE}    ${ROOT_INLINE}    ${ROOT_HEADER}
	${CORE_SOURCE}    ${CORE_INLINE}    ${CORE_HEADER}
	${EXT_SOURCE}     ${EXT_INLINE}     ${EXT_HEADER}
	${GTC_SOURCE}     ${GTC_INLINE}     ${GTC_HEADER}
	${GTX_SOURCE}     ${GTX_INLINE}     ${GTX_HEADER}
	${SIMD_SOURCE}    ${SIMD_INLINE}    ${SIMD_HEADER})

target_include_directories(glm_shared PUBLIC
                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../> )

install(FILES ${ROOT_HEADER} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm)
install(FILES ${ROOT_INLINE} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm)
install(FILES ${ROOT_MD} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm)
install(FILES ${ROOT_NAT} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm)

install(FILES ${CORE_HEADER} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm/detail)
install(FILES ${CORE_HEADER} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm/detail)

install(FILES ${EXT_HEADER} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm/ext)
install(FILES ${EXT_INLINE} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm/ext)

install(FILES ${GTC_HEADER} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm/gtc)
install(FILES ${GTC_INLINE} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm/gtc)

install(FILES ${GTX_HEADER} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm/gtx)
install(FILES ${GTX_INLINE} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm/gtx)

install(FILES ${SIMD_HEADER} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm/simd)
install(FILES ${SIMD_INLINE} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm/simd)

