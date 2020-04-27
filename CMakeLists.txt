cmake_minimum_required(VERSION 3.13)

project(gbmu)

set(CMAKE_CXX_STANDARD 17)

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
	srcs/init_sdl.c
	srcs/video_loop.c
	srcs/vram_viewer.c
	srcs/tools.c
	srcs/tile.c
	srcs/breakpoints.c
	srcs/main_window_loop.c
	srcs/handle_joypad.c
	srcs/save_game.c
	srcs/palette.c
	srcs/mbc1.c
	srcs/mbc2.c
	srcs/mbc3.c
	srcs/mbc5.c
	srcs/userscreen.c
	srcs/instructions/jp.c
	srcs/instructions/ld.c
	srcs/instructions/misc.c
	srcs/instructions/xor.c
	srcs/instructions/or.c
	srcs/instructions/and.c
	srcs/instructions/add.c
	srcs/instructions/adc.c
	srcs/instructions/sub.c
	srcs/instructions/sbc.c
	srcs/instructions/call.c
	srcs/instructions/inc.c
	srcs/instructions/dec.c
	srcs/instructions/cp.c
	srcs/instructions/stack.c
	srcs/instructions/cb.c
	srcs/instructions/srl.c
	srcs/instructions/rr.c
	srcs/instructions/rrc.c
	srcs/instructions/rl.c
	srcs/instructions/sla.c
	srcs/instructions/sra.c
	srcs/instructions/rlc.c
	srcs/instructions/bit.c
	srcs/instructions/res.c
	srcs/instructions/set.c
	srcs/instructions/swap.c

	srcs/renderer/renderer_opengl.h
	srcs/renderer/renderer_opengl.cpp
	srcs/renderer/background.h
	srcs/renderer/background.cpp
	srcs/renderer/window.h
	srcs/renderer/window.cpp
	srcs/renderer/sprites.h
	srcs/renderer/sprites.cpp
	srcs/renderer/gl_utils/compile_program.h
	srcs/renderer/gl_utils/compile_program.cpp

	srcs/renderer/wrapper_c/wrapper.cpp
	)

SET (INCLUDES
    )

find_package(SDL2 REQUIRED)
find_package(Threads)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(srcs)
message (${SDL2_INCLUDE_DIRS})

INCLUDE_DIRECTORIES(includes)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g3")

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${OPENGL_LIBRARIES})

# SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE TRUE)