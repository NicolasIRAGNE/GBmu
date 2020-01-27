cmake_minimum_required(VERSION 3.13)

project(gbmu)

SET (SOURCES
    srcs/main.c
        )

SET (INCLUDES
    )

find_package(SDL2 REQUIRED)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
message (${SDL2_INCLUDE_DIRS})

INCLUDE_DIRECTORIES(includes)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")

add_executable(gbmu ${SOURCES})
target_link_libraries(gbmu ${SDL2_LIBRARIES})
# SET_TARGET_PROPERTIES(gbmu PROPERTIES MACOSX_BUNDLE TRUE)
