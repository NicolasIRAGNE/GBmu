cmake_minimum_required(VERSION 3.13)

project(gbmu)

SET (SOURCES
	srcs/main.c
	srcs/debug.c
	srcs/execute.c
	srcs/init_cpu.c
	srcs/init_op_tab.c
	srcs/init_ext_op_tab.c
	srcs/memory.c
	srcs/debugger.c
	srcs/gpu.c
	srcs/cpu_toggle_flag.c
	srcs/video_loop.c
	srcs/instructions/jp.c
	srcs/instructions/ld.c
	srcs/instructions/misc.c
	srcs/instructions/xor.c
	srcs/instructions/or.c
	srcs/instructions/and.c
	srcs/instructions/add.c
	srcs/instructions/sub.c
	srcs/instructions/call.c
	srcs/instructions/inc.c
	srcs/instructions/dec.c
	srcs/instructions/cp.c
	srcs/instructions/stack.c
	srcs/instructions/cb.c
	srcs/instructions/srl.c
	srcs/instructions/rr.c
	srcs/instructions/rl.c
	)

SET (INCLUDES
    )

find_package(SDL2 REQUIRED)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
message (${SDL2_INCLUDE_DIRS})

INCLUDE_DIRECTORIES(includes)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
# SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE TRUE)
