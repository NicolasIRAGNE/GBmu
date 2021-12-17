cmake_minimum_required(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(gbmu)

add_library(gbmu_lib)
set_property(TARGET gbmu_lib PROPERTY C_STANDARD 11)
add_executable(gbmu srcs/main.c)
target_link_libraries(gbmu ${CMAKE_THREAD_LIBS_INIT})

include(FetchContent)

option(WITH_LIBYACC "Build libyacc" OFF)
option(WITH_ASAN "Build with memory sanitizer" OFF)
option(DEBUG_COLORS "Enable debug palette" ON)
option(WITH_TESTS "Build tests" ON)
option(WITH_HWACCEL "Build with hardware acceleration" OFF)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
target_link_libraries(gbmu_lib ${CMAKE_THREAD_LIBS_INIT})
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lpthread")

FetchContent_Declare(
        SDL2
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL/"
        GIT_TAG release-2.0.18
)

FetchContent_Declare(
        GLEW
        GIT_REPOSITORY "https://github.com/Perlmint/glew-cmake"
        GIT_TAG glew-cmake-release
)

FetchContent_MakeAvailable(GLEW SDL2)

if(WIN32)
	FetchContent_Declare(
			WINEDITLINE
			GIT_REPOSITORY "https://github.com/NicolasIRAGNE/wineditline"
			GIT_TAG WinEditLine-2.207
	)

	FetchContent_MakeAvailable(WINEDITLINE)
endif()

################################################
#                  LIBRARIES                   #
################################################

# pthread
find_package(Threads)

# OpenGL
if (WITH_HWACCEL)
find_package(OpenGL REQUIRED)
endif()

add_compile_definitions(_SCL_SECURE_NO_WARNINGS)
add_compile_definitions(_ITERATOR_DEBUG_LEVEL=0)

if (NOT WIN32)
	#Readline
	add_compile_definitions(USE_READLINE_STATIC=1)
	add_compile_definitions(READLINE_LIBRARY=1)
	find_package(Readline REQUIRED)
	target_include_directories(gbmu_lib PRIVATE ${Readline_INCLUDE_DIR})
	target_link_libraries(gbmu_lib ${Readline_LIBRARY})
	target_include_directories(gbmu_lib PUBLIC ${Readline_INCLUDE_DIR})
endif()

################################################
#                   SOURCES                    #
################################################

# Core
set(SOURCES
	srcs/debug.c
	srcs/debugger.c
	srcs/execute.c
	srcs/init_cpu.c
	srcs/init_op_tab.c
	srcs/init_ext_op_tab.c
	srcs/gpu.c
	srcs/cpu_toggle_flag.c
	srcs/video_loop.c
	srcs/vram_viewer.c
	srcs/tools.c
	srcs/tile.c
	srcs/breakpoints.c
	srcs/main_window_loop.c
	srcs/input_functions.c
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
	srcs/timer.c
	srcs/write.c
	srcs/read.c
	srcs/div.c
	srcs/io_map.c
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
	includes/renderer.h
	includes/input_functions.c
	)

if (WIN32)
	list (APPEND SOURCES 
		srcs/asprintf.c
	)
	list (APPEND HEADERS 
		includes/asprintf.h
	)
endif()

if (NOT WITH_LIBYACC)
 list(APPEND SOURCES
		srcs/fallback_debugger.c
	)
endif()

# Renderer
if (WITH_HWACCEL)
list(APPEND SOURCES
	srcs/renderer_gpu/renderer_opengl.cpp
	srcs/renderer_gpu/background.cpp
	srcs/renderer_gpu/window.cpp
	srcs/renderer_gpu/sprites.cpp
	srcs/renderer_gpu/rescale.cpp
	srcs/renderer_gpu/gl_utils/compile_program.cpp
	srcs/renderer_gpu/wrapper_c/wrapper.cpp
	srcs/renderer_gpu/init_sdl.c)
else()
list (APPEND SOURCES
	srcs/renderer_cpu/init_sdl.c
	srcs/renderer_cpu/renderer_sdl.c
	)
endif()

if (WITH_HWACCEL)
list(APPEND HEADERS
	srcs/renderer_gpu/renderer_opengl.h
	srcs/renderer_gpu/background.h
	srcs/renderer_gpu/window.h
	srcs/renderer_gpu/sprites.h
	srcs/renderer_gpu/rescale.h
	srcs/renderer_gpu/gl_utils/compile_program.h
	srcs/renderer_gpu/gl_utils/glerr.h
	srcs/renderer_gpu/wrapper_c/wrapper.h)
	
	set(SHADERS
	srcs/renderer_gpu/shaders/background.vert
	srcs/renderer_gpu/shaders/background.frag
	srcs/renderer_gpu/shaders/window.vert
	srcs/renderer_gpu/shaders/window.frag
	srcs/renderer_gpu/shaders/sprites.vert
	srcs/renderer_gpu/shaders/sprites.frag
	srcs/renderer_gpu/shaders/basic.vert
	srcs/renderer_gpu/shaders/basic.frag
	srcs/renderer_gpu/shaders/rain.frag)
endif()

# Debugger

set(DEBUGGER_SOURCES
	srcs/debugger/DebuggerAddress.cpp
	srcs/debugger/DebuggerContext.cpp
	srcs/debugger/Debugger.cpp
	srcs/debugger/DebuggerGrammar.cpp
	srcs/debugger/DebuggerVariableConstValue.cpp
	srcs/debugger/DebuggerVariable.cpp
	srcs/debugger/DebuggerVariableValue.cpp
	srcs/debugger/History.cpp
	srcs/debugger/libyacc_wrapper.cpp
	srcs/debugger/PrintCommandSuffixParams.cpp
	srcs/debugger/SymbolNonTerminalAbstractCommand.cpp
	srcs/debugger/SymbolNonTerminalAddress.cpp
	srcs/debugger/SymbolNonTerminalAndOr.cpp
	srcs/debugger/SymbolNonTerminalAssignable.cpp
	srcs/debugger/SymbolNonTerminalBreakpointCommand.cpp
	srcs/debugger/SymbolNonTerminalCommand.cpp
	srcs/debugger/SymbolNonTerminalCommandName.cpp
	srcs/debugger/SymbolNonTerminalComparison.cpp
	srcs/debugger/SymbolNonTerminalContinueCommand.cpp
	srcs/debugger/SymbolNonTerminalDeleteCommand.cpp
	srcs/debugger/SymbolNonTerminalExpr.cpp
	srcs/debugger/SymbolNonTerminalFactor.cpp
	srcs/debugger/SymbolNonTerminalHelpCommand.cpp
	srcs/debugger/SymbolNonTerminalInfoCommand.cpp
	srcs/debugger/SymbolNonTerminalIntegerList.cpp
	srcs/debugger/SymbolNonTerminalIoPort.cpp
	srcs/debugger/SymbolNonTerminalNextCommand.cpp
	srcs/debugger/SymbolNonTerminalPrintCommand.cpp
	srcs/debugger/SymbolNonTerminalPrintCommandSuffix.cpp
	srcs/debugger/SymbolNonTerminalQuitCommand.cpp
	srcs/debugger/SymbolNonTerminalRegisterName.cpp
	srcs/debugger/SymbolNonTerminalRegistersCommand.cpp
	srcs/debugger/SymbolNonTerminalRunCommand.cpp
	srcs/debugger/SymbolNonTerminalSetCommand.cpp
	srcs/debugger/SymbolNonTerminalStartCommand.cpp
	srcs/debugger/SymbolNonTerminalStepCommand.cpp
	srcs/debugger/SymbolNonTerminalTemporaryBreakpointCommand.cpp
	srcs/debugger/SymbolNonTerminalTerm.cpp
	srcs/debugger/SymbolNonTerminalValue.cpp
	srcs/debugger/SymbolNonTerminalVariable.cpp
	srcs/debugger/SymbolNonTerminalVector.cpp
	srcs/debugger/SymbolNonTerminalVerboseCommand.cpp
	srcs/debugger/SymbolNonTerminalWatchCommand.cpp
	srcs/debugger/SymbolNonTerminalXCommand.cpp
	srcs/debugger/SymbolTerminalAnd.cpp
	srcs/debugger/SymbolTerminalAssign.cpp
	srcs/debugger/SymbolTerminalBinaryAnd.cpp
	srcs/debugger/SymbolTerminalBinaryOr.cpp
	srcs/debugger/SymbolTerminalBreakpoint.cpp
	srcs/debugger/SymbolTerminalClosedParenthesis.cpp
	srcs/debugger/SymbolTerminalCommand.cpp
	srcs/debugger/SymbolTerminalContinue.cpp
	srcs/debugger/SymbolTerminalDelete.cpp
	srcs/debugger/SymbolTerminalDivide.cpp
	srcs/debugger/SymbolTerminalDivOffset.cpp
	srcs/debugger/SymbolTerminalEqual.cpp
	srcs/debugger/SymbolTerminalExpansion.cpp
	srcs/debugger/SymbolTerminalGreater.cpp
	srcs/debugger/SymbolTerminalGreaterOrEqual.cpp
	srcs/debugger/SymbolTerminalHelp.cpp
	srcs/debugger/SymbolTerminalInfo.cpp
	srcs/debugger/SymbolTerminalInteger.cpp
	srcs/debugger/SymbolTerminalInterruptJoypad.cpp
	srcs/debugger/SymbolTerminalInterruptSerial.cpp
	srcs/debugger/SymbolTerminalInterruptStat.cpp
	srcs/debugger/SymbolTerminalInterruptTimer.cpp
	srcs/debugger/SymbolTerminalInterruptVBlank.cpp
	srcs/debugger/SymbolTerminalLeftShift.cpp
	srcs/debugger/SymbolTerminalLesser.cpp
	srcs/debugger/SymbolTerminalLesserOrEqual.cpp
	srcs/debugger/SymbolTerminalMinus.cpp
	srcs/debugger/SymbolTerminalModulo.cpp
	srcs/debugger/SymbolTerminalMultiply.cpp
	srcs/debugger/SymbolTerminalNext.cpp
	srcs/debugger/SymbolTerminalNotEqual.cpp
	srcs/debugger/SymbolTerminalOpenParenthesis.cpp
	srcs/debugger/SymbolTerminalOr.cpp
	srcs/debugger/SymbolTerminalPlus.cpp
	srcs/debugger/SymbolTerminalPrintCommandParams.cpp
	srcs/debugger/SymbolTerminalPrint.cpp
	srcs/debugger/SymbolTerminalPrintingCommand.cpp
	srcs/debugger/SymbolTerminalProgramCounter.cpp
	srcs/debugger/SymbolTerminalQuit.cpp
	srcs/debugger/SymbolTerminalRegisterA.cpp
	srcs/debugger/SymbolTerminalRegisterAF.cpp
	srcs/debugger/SymbolTerminalRegisterBC.cpp
	srcs/debugger/SymbolTerminalRegisterB.cpp
	srcs/debugger/SymbolTerminalRegisterC.cpp
	srcs/debugger/SymbolTerminalRegisterD.cpp
	srcs/debugger/SymbolTerminalRegisterDE.cpp
	srcs/debugger/SymbolTerminalRegisterE.cpp
	srcs/debugger/SymbolTerminalRegisterF.cpp
	srcs/debugger/SymbolTerminalRegisterH.cpp
	srcs/debugger/SymbolTerminalRegisterHL.cpp
	srcs/debugger/SymbolTerminalRegisterL.cpp
	srcs/debugger/SymbolTerminalRegisters.cpp
	srcs/debugger/SymbolTerminalRightShift.cpp
	srcs/debugger/SymbolTerminalRun.cpp
	srcs/debugger/SymbolTerminalSet.cpp
	srcs/debugger/SymbolTerminalStackPointer.cpp
	srcs/debugger/SymbolTerminalStart.cpp
	srcs/debugger/SymbolTerminalStep.cpp
	srcs/debugger/SymbolTerminalTemporaryBreakpoint.cpp
	srcs/debugger/SymbolTerminalTimaOffset.cpp
	srcs/debugger/SymbolTerminalVariable.cpp
	srcs/debugger/SymbolTerminalVerbose.cpp
	srcs/debugger/SymbolTerminalWatch.cpp
	srcs/debugger/SymbolTerminalWatchModes.cpp
	srcs/debugger/SymbolTerminalX.cpp
	srcs/debugger/TokenPrintCommandSuffix.cpp
	srcs/debugger/TokenWatchModes.cpp
	srcs/debugger/toLower.cpp
	srcs/debugger/WatchPoint.cpp

	srcs/debugger/Commands/AbstractCommand.cpp
	srcs/debugger/Commands/SetCommand.cpp
	srcs/debugger/Commands/Print.cpp
	srcs/debugger/Commands/XCommand.cpp
	srcs/debugger/Commands/Quit.cpp
	srcs/debugger/Commands/Watch.cpp
	srcs/debugger/Commands/Info.cpp
	srcs/debugger/Commands/Help.cpp
	srcs/debugger/Commands/Registers.cpp
	srcs/debugger/Commands/Delete.cpp
	srcs/debugger/Commands/Next.cpp
	srcs/debugger/Commands/Step.cpp
	srcs/debugger/Commands/Verbose.cpp
	srcs/debugger/Commands/AbstractBreakpoint.cpp
	srcs/debugger/Commands/StandardBreakpoint.cpp
	srcs/debugger/Commands/TemporaryBreakpoint.cpp
	srcs/debugger/Commands/Run.cpp
	srcs/debugger/Commands/Start.cpp
	srcs/debugger/Commands/Continue.cpp
	)

	set (DEBUGGER_HEADERS
	includes/debugger/toLower.hpp
	includes/debugger/WatchModes.hpp
	includes/debugger/DebuggerColors.h
	includes/debugger/libyacc_wrapper.h
	includes/debugger/SymbolNonTerminalWatchModeList.hpp
	includes/debugger/PrintCommandSuffixParams.hpp
	includes/debugger/WatchPoint.hpp
	includes/debugger/DebuggerAddress.hpp
	includes/debugger/MapOfListNoRepetitions.hpp
	includes/debugger/Debugger.hpp
	includes/debugger/History.hpp
	includes/debugger/DebuggerVariable.hpp
	includes/debugger/DebuggerVariableAddress.hpp
	includes/debugger/DebuggerVariableValue.hpp
	includes/debugger/DebuggerVariableConstValue.hpp
	includes/debugger/DebuggerContext.hpp
	includes/debugger/DebuggerGrammar.hpp
	includes/debugger/SymbolNonTerminalAndOr.hpp
	includes/debugger/SymbolNonTerminalAssignable.hpp
	includes/debugger/SymbolNonTerminalAddress.hpp
	includes/debugger/SymbolNonTerminalBreakpointCommand.hpp
	includes/debugger/SymbolNonTerminalCommand.hpp
	includes/debugger/SymbolNonTerminalCommandName.hpp
	includes/debugger/SymbolNonTerminalComparison.hpp
	includes/debugger/SymbolNonTerminalDeleteCommand.hpp
	includes/debugger/SymbolNonTerminalExpr.hpp
	includes/debugger/SymbolNonTerminalFactor.hpp
	includes/debugger/SymbolNonTerminalHelpCommand.hpp
	includes/debugger/SymbolNonTerminalInfoCommand.hpp
	includes/debugger/SymbolNonTerminalIntegerList.hpp
	includes/debugger/SymbolNonTerminalIoPort.hpp
	includes/debugger/SymbolNonTerminalNextCommand.hpp
	includes/debugger/SymbolNonTerminalPrintCommand.hpp
	includes/debugger/SymbolNonTerminalPrintCommandSuffix.hpp
	includes/debugger/SymbolNonTerminalQuitCommand.hpp
	includes/debugger/SymbolNonTerminalContinueCommand.hpp
	includes/debugger/SymbolNonTerminalRunCommand.hpp
	includes/debugger/SymbolNonTerminalRegistersCommand.hpp
	includes/debugger/SymbolNonTerminalSetCommand.hpp
	includes/debugger/SymbolNonTerminalStepCommand.hpp
	includes/debugger/SymbolNonTerminalTerm.hpp
	includes/debugger/SymbolNonTerminalValue.hpp
	includes/debugger/SymbolNonTerminalVariable.hpp
	includes/debugger/SymbolNonTerminalVector.hpp
	includes/debugger/SymbolNonTerminalVerboseCommand.hpp
	includes/debugger/SymbolNonTerminalWatchCommand.hpp
	includes/debugger/SymbolNonTerminalXCommand.hpp
	includes/debugger/SymbolNonTerminalStartCommand.hpp
	includes/debugger/SymbolNonTerminalTemporaryBreakpointCommand.hpp
    includes/debugger/SymbolNonTerminalAbstractCommand.hpp
	includes/debugger/SymbolTerminalAnd.hpp
	includes/debugger/SymbolTerminalAssign.hpp
	includes/debugger/SymbolTerminalBinaryAnd.hpp
	includes/debugger/SymbolTerminalBinaryOr.hpp
	includes/debugger/SymbolTerminalBreakpoint.hpp
	includes/debugger/SymbolTerminalClosedParenthesis.hpp
	includes/debugger/SymbolTerminalCommand.hpp
	includes/debugger/SymbolTerminalDelete.hpp
	includes/debugger/SymbolTerminalDivide.hpp
	includes/debugger/SymbolTerminalDivOffset.hpp
	includes/debugger/SymbolTerminalEqual.hpp
	includes/debugger/SymbolTerminalExpansion.hpp
	includes/debugger/SymbolTerminalGreater.hpp
	includes/debugger/SymbolTerminalGreaterOrEqual.hpp
	includes/debugger/SymbolTerminalHelp.hpp
	includes/debugger/SymbolTerminalInfo.hpp
	includes/debugger/SymbolTerminalInteger.hpp
	includes/debugger/SymbolTerminalInterruptJoypad.hpp
	includes/debugger/SymbolTerminalInterruptSerial.hpp
	includes/debugger/SymbolTerminalInterruptStat.hpp
	includes/debugger/SymbolTerminalInterruptTimer.hpp
	includes/debugger/SymbolTerminalInterruptVBlank.hpp
	includes/debugger/SymbolTerminalLeftShift.hpp
	includes/debugger/SymbolTerminalLesser.hpp
	includes/debugger/SymbolTerminalLesserOrEqual.hpp
	includes/debugger/SymbolTerminalMinus.hpp
	includes/debugger/SymbolTerminalModulo.hpp
	includes/debugger/SymbolTerminalMultiply.hpp
	includes/debugger/SymbolTerminalNext.hpp
	includes/debugger/SymbolTerminalNotEqual.hpp
	includes/debugger/SymbolTerminalOpenParenthesis.hpp
	includes/debugger/SymbolTerminalOr.hpp
	includes/debugger/SymbolTerminalPlus.hpp
	includes/debugger/SymbolTerminalPrintCommandParams.hpp
	includes/debugger/SymbolTerminalPrint.hpp
	includes/debugger/SymbolTerminalPrintingCommand.hpp
	includes/debugger/SymbolTerminalProgramCounter.hpp
	includes/debugger/SymbolTerminalQuit.hpp
	includes/debugger/SymbolTerminalRegisters.hpp
	includes/debugger/SymbolTerminalRightShift.hpp
	includes/debugger/SymbolTerminalSet.hpp
	includes/debugger/SymbolTerminalStackPointer.hpp
	includes/debugger/SymbolTerminalStep.hpp
	includes/debugger/SymbolTerminalVerbose.hpp
	includes/debugger/SymbolTerminalWatch.hpp
	includes/debugger/SymbolTerminalX.hpp
	includes/debugger/SymbolTerminalRun.hpp
	includes/debugger/SymbolTerminalContinue.hpp
	includes/debugger/SymbolTerminalWatchModes.hpp
	includes/debugger/SymbolTerminalStart.hpp
	includes/debugger/SymbolTerminalTemporaryBreakpoint.hpp
	includes/debugger/SymbolTerminalTimaOffset.hpp
	includes/debugger/TokenPrintCommandSuffix.hpp
	includes/debugger/TokenWatchModes.hpp
	includes/debugger/Commands/SetCommand.hpp
	includes/debugger/Commands/XCommand.hpp
	includes/debugger/Commands/Quit.hpp
	includes/debugger/Commands/Watch.hpp
	includes/debugger/Commands/Info.hpp
	includes/debugger/Commands/Help.hpp
	includes/debugger/Commands/Registers.hpp
	includes/debugger/Commands/Delete.hpp
	includes/debugger/Commands/Next.hpp
	includes/debugger/Commands/Step.hpp
	includes/debugger/Commands/Verbose.hpp
	includes/debugger/Commands/AbstractBreakpoint.hpp
	includes/debugger/Commands/StandardBreakpoint.hpp
	includes/debugger/Commands/TemporaryBreakpoint.hpp
	includes/debugger/Commands/Run.hpp
	includes/debugger/Commands/Start.hpp
	includes/debugger/Commands/Continue.hpp
	)

target_include_directories(gbmu_lib PUBLIC srcs)
target_include_directories(gbmu_lib PUBLIC includes)
	
################################################
#                COMPILE FLAGS                 #
################################################

set(CMAKE_CXX_STANDARD 17)

if (WIN32)
	set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS}         ")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ")
	set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   /DEBUG")
	set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS}           ")
	set(CMAKE_C_FLAGS_RELEASE   "${CMAKE_C_FLAGS_RELEASE}   ")
	set(CMAKE_C_FLAGS_DEBUG     "${CMAKE_C_FLAGS_DEBUG}     /DEBUG")
else()
	# set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS}         -Wall -Wextra")
	# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -g -Werror")
	set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   -O0 -g")
	# set(CMAKE_C_FLAGS           "${CMAKE_C_FLAGS}           -Wall -Wextra")
	# set(CMAKE_C_FLAGS_RELEASE   "${CMAKE_C_FLAGS_RELEASE}   -O3 -g -Werror")
	set(CMAKE_C_FLAGS_DEBUG     "${CMAKE_C_FLAGS_DEBUG}     -O0 -g")
endif()


if (WITH_ASAN)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
	set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS_DEBUG}   -fsanitize=address")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
endif()

if (DEBUG_COLORS)
	target_compile_definitions(gbmu_lib PRIVATE DEBUG_COLORS)
endif()


################################################
#                  EXECUTABLE                  #
################################################

if (WITH_LIBYACC)
	message("bah ouais")
	target_sources(gbmu_lib PRIVATE ${GENERATED_LIBYACC_SOURCES} ${DEBUGGER_SOURCES})
	FILE(GLOB GENERATED_LIBYACC_SOURCES srcs/debugger/*.cpp)
	FILE(GLOB GENERATED_LIBYACC_SOURCES srcs/debugger/Commands/*.cpp)
	target_compile_definitions(gbmu_lib PUBLIC WITH_LIBYACC)
	target_include_directories(gbmu_lib PUBLIC includes/debugger)
	target_include_directories(gbmu_lib PUBLIC includes/debugger/Commands)
	include_directories(libyacc/includes)
endif()

target_sources(gbmu_lib PRIVATE ${SOURCES})
target_link_libraries(gbmu_lib SDL2main)
target_link_libraries(gbmu_lib SDL2-static)
target_link_libraries(gbmu_lib ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(gbmu_lib ${OPENGL_LIBRARIES})
target_link_libraries(gbmu_lib libglew_static)

if (WIN32)
	target_link_libraries(gbmu_lib edit_static)
endif()

# target_include_directories(gbmu_lib ${SDL2_INCLUDE_DIRS})

################################################
#                   INSTALL                    #
################################################
foreach(shader ${SHADERS})
	get_filename_component(filename ${shader} NAME)
	add_custom_command(
		OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename}
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${shader}
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${shader} ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename}
		COMMENT "Copying shader ${filename} to ${CMAKE_CURRENT_BINARY_DIR}/shaders/"
		)
		set (GENERATED_SHADERS ${GENERATED_SHADERS} ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename})
	# add_custom_target(gbmu_shader_${filename} ALL
	# 	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/${shader} ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename}
	# 	DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename}
	# 	COMMENT "Copying shader ${filename} to ${CMAKE_CURRENT_BINARY_DIR}/shaders/"
	# 	SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${shader}
	# )
	# add_dependencies(gbmu_lib gbmu_shader_${filename})
endforeach()

target_link_libraries(gbmu gbmu_lib)
add_custom_target(gbmu_shaders ALL DEPENDS ${GENERATED_SHADERS})

add_dependencies(gbmu_lib gbmu_shaders)

if (WITH_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()