cmake_minimum_required(VERSION 3.13)
SET(CMAKE_CXX_STANDARD 17)

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
	srcs/init_sdl.c
	srcs/video_loop.c
	srcs/vram_viewer.c
	srcs/tools.c
	srcs/tile.c
	srcs/breakpoints.c
	srcs/main_window_loop.c
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
	)

# EXECUTE_PROCESS(COMMAND "python3" "libyacc/generator/ParserGenerator.py" "debuggerGrammar" 
				# WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
				# RESULT_VARIABLE CMD_RESULT
				# OUTPUT_VARIABLE CMD_OUTPUT
			# )

message(STATUS ${CMD_OUTPUT})

FILE(GLOB GENERATED_LIBYACC_SOURCES srcs/debugger/*.cpp)

SET (INCLUDES
    )

find_package(SDL2 REQUIRED)
find_package(Threads)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

INCLUDE_DIRECTORIES(includes)
INCLUDE_DIRECTORIES(libyacc/includes)
INCLUDE_DIRECTORIES(includes/debugger)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lpthread -Wall -Wextra")

add_executable(${PROJECT_NAME} ${SOURCES} ${GENERATED_LIBYACC_SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
# SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE TRUE)
