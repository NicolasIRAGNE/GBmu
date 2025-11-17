cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

project(gbmu LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(FetchContent)
include(cmake/Dependencies.cmake)

option(WITH_LIBYACC "Build libyacc" OFF)
option(WITH_ASAN "Build with memory sanitizer" OFF)
option(DEBUG_COLORS "Enable debug palette" ON)
option(WITH_TESTS "Build tests" OFF)

gbmu_configure_tooling()

add_library(gb STATIC)
target_compile_definitions(gb PUBLIC "ASAN_OPTIONS=detect_leaks=0")
target_compile_features(gb PUBLIC cxx_std_17)

gbmu_configure_dependencies(gb)

include(cmake/Sources.cmake)

set(BUILD_SOURCES ${SOURCES})
if(NOT WITH_LIBYACC)
        list(FILTER BUILD_SOURCES EXCLUDE REGEX "srcs/debugger/.*\\.cpp$")
endif()

target_sources(gb PRIVATE ${BUILD_SOURCES} ${HEADERS} srcs/lib.c includes/lib.h)

target_include_directories(gb PUBLIC "${CMAKE_CURRENT_BINARY_DIR}" srcs includes)

message(STATUS "Including gb headers from build directory : ${CMAKE_CURRENT_BINARY_DIR}")

target_compile_options(gb PRIVATE
  "$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wall>"
  "$<$<CXX_COMPILER_ID:MSVC>:/W4>"
  "$<$<CXX_COMPILER_ID:MSVC>:/wd4201>"
  "$<$<CXX_COMPILER_ID:MSVC>:/wd4267>"
  "$<$<CXX_COMPILER_ID:MSVC>:/wd4244>"
)

if(WITH_ASAN)
        target_link_options(gb PUBLIC "-fsanitize=address")
        target_compile_options(gb PUBLIC "-fsanitize=address")
endif()

if(DEBUG_COLORS)
        target_compile_definitions(gb PRIVATE DEBUG_COLORS)
endif()

if(WITH_LIBYACC)
        target_compile_definitions(gb PUBLIC WITH_LIBYACC)
        target_include_directories(gb PUBLIC includes/debugger includes/debugger/Commands)
        include_directories(libyacc/includes)
endif()

add_subdirectory(srcs/gbclodo)

include(CopyDLLs)

if(WITH_TESTS)
        enable_testing()
        add_subdirectory(tests)
endif()

install(TARGETS gb DESTINATION bin)

if(TARGET gbclodo)
        install(TARGETS gbclodo DESTINATION bin)
endif()

install(
        FILES
                ressources/fonts/hasklig/Hasklig-BlackIt.ttf
                ressources/fonts/hasklig/Hasklig-Black.ttf
                ressources/fonts/hasklig/Hasklig-BoldIt.ttf
                ressources/fonts/hasklig/Hasklig-Bold.ttf
                ressources/fonts/hasklig/Hasklig-ExtraLightIt.ttf
                ressources/fonts/hasklig/Hasklig-ExtraLight.ttf
                ressources/fonts/hasklig/Hasklig-It.ttf
                ressources/fonts/hasklig/Hasklig-LightIt.ttf
                ressources/fonts/hasklig/Hasklig-Light.ttf
                ressources/fonts/hasklig/Hasklig-MediumIt.ttf
                ressources/fonts/hasklig/Hasklig-Medium.ttf
                ressources/fonts/hasklig/Hasklig-Regular.ttf
                ressources/fonts/hasklig/Hasklig-SemiboldIt.ttf
                ressources/fonts/hasklig/Hasklig-Semibold.ttf
        DESTINATION
                "."
        )

install(FILES DMG_ROM.bin DESTINATION ".")
