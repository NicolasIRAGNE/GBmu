cmake_minimum_required(VERSION 3.13)

project(gbmu)

################################################
#                  LIBRARIES                   #
################################################

# pthread
find_package(Threads)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

################################################
#                   SOURCES                    #
################################################

# Core
set(SOURCES
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
	srcs/mbc.c
	srcs/mbc_none.c
	srcs/mbc1.c
	srcs/mbc2.c
	srcs/mbc3.c
	srcs/mbc5.c
	srcs/errors.c
	srcs/userscreen.c
	srcs/savestate.c
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
	srcs/instructions/swap.c)

set(HEADERS
	includes/cpu.h
	includes/display.h
	includes/ext_op.h
	includes/gb.h
	includes/mbc.h
	includes/op.h
	includes/registers.h
	includes/renderer.h)

# Renderer
list(APPEND SOURCES
	srcs/renderer/renderer_opengl.cpp
	srcs/renderer/background.cpp
	srcs/renderer/window.cpp
	srcs/renderer/sprites.cpp
	srcs/renderer/gl_utils/compile_program.cpp
	srcs/renderer/wrapper_c/wrapper.cpp)

list(APPEND HEADERS
	srcs/renderer/renderer_opengl.h
	srcs/renderer/background.h
	srcs/renderer/window.h
	srcs/renderer/sprites.h
	srcs/renderer/gl_utils/compile_program.h
	srcs/renderer/wrapper_c/wrapper.h)

set(SHADERS
	srcs/renderer/shaders/background.vert
	srcs/renderer/shaders/background.frag
	srcs/renderer/shaders/window.vert
	srcs/renderer/shaders/window.frag
	srcs/renderer/shaders/sprites.vert
	srcs/renderer/shaders/sprites.frag)

include_directories(srcs)
include_directories(includes)

################################################
#                COMPILE FLAGS                 #
################################################

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS}         -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -g -Werror")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   -O0 -g")
set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS}           -Wall -Wextra")
set(CMAKE_C_FLAGS_RELEASE   "${CMAKE_C_FLAGS_RELEASE}   -O3 -g -Werror")
set(CMAKE_C_FLAGS_DEBUG     "${CMAKE_C_FLAGS_DEBUG}     -O0 -g")

################################################
#                  EXECUTABLE                  #
################################################

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})

################################################
#                   INSTALL                    #
################################################

install(FILES ${SHADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/shaders)
