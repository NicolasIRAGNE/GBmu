cmake_minimum_required(VERSION 3.13)
SET(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

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

# Glew
find_package(GLEW REQUIRED)

#Readline
find_package(Readline REQUIRED)

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
	srcs/timer.c
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
	includes/renderer.h)

# Renderer
list(APPEND SOURCES
	srcs/renderer/renderer_opengl.cpp
	srcs/renderer/background.cpp
	srcs/renderer/window.cpp
	srcs/renderer/sprites.cpp
	srcs/renderer/rescale.cpp
	srcs/renderer/gl_utils/compile_program.cpp
	srcs/renderer/wrapper_c/wrapper.cpp)

list(APPEND HEADERS
	srcs/renderer/renderer_opengl.h
	srcs/renderer/background.h
	srcs/renderer/window.h
	srcs/renderer/sprites.h
	srcs/renderer/rescale.h
	srcs/renderer/gl_utils/compile_program.h
	srcs/renderer/wrapper_c/wrapper.h)

set(SHADERS
	srcs/renderer/shaders/background.vert
	srcs/renderer/shaders/background.frag
	srcs/renderer/shaders/window.vert
	srcs/renderer/shaders/window.frag
	srcs/renderer/shaders/sprites.vert
	srcs/renderer/shaders/sprites.frag
	srcs/renderer/shaders/basic.vert
	srcs/renderer/shaders/basic.frag
	srcs/renderer/shaders/rain.frag)

# Debugger

set(DEBUGGER_SOURCES
	srcs/debugger/libyacc_wrapper.cpp
	srcs/debugger/DebuggerContext.cpp
	srcs/debugger/DebuggerGrammar.cpp
	srcs/debugger/SymbolNonTerminalAndOr.cpp
	srcs/debugger/SymbolNonTerminalAssignable.cpp
	srcs/debugger/SymbolNonTerminalAssignableList.cpp
	srcs/debugger/SymbolNonTerminalBreakpointCommand.cpp
	srcs/debugger/SymbolNonTerminalCommand.cpp
	srcs/debugger/SymbolNonTerminalCommandName.cpp
	srcs/debugger/SymbolNonTerminalComparison.cpp
	srcs/debugger/SymbolNonTerminalDeleteCommand.cpp
	srcs/debugger/SymbolNonTerminalExpr.cpp
	srcs/debugger/SymbolNonTerminalFactor.cpp
	srcs/debugger/SymbolNonTerminalFormat.cpp
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
	srcs/debugger/SymbolNonTerminalSetCommand.cpp
	srcs/debugger/SymbolNonTerminalStepCommand.cpp
	srcs/debugger/SymbolNonTerminalTerm.cpp
	srcs/debugger/SymbolNonTerminalUnit.cpp
	srcs/debugger/SymbolNonTerminalUnwatchCommand.cpp
	srcs/debugger/SymbolNonTerminalValue.cpp
	srcs/debugger/SymbolNonTerminalVariable.cpp
	srcs/debugger/SymbolNonTerminalVector.cpp
	srcs/debugger/SymbolNonTerminalVerboseCommand.cpp
	srcs/debugger/SymbolNonTerminalWatchCommand.cpp
	srcs/debugger/SymbolNonTerminalWatchMode.cpp
	srcs/debugger/SymbolNonTerminalWatchModeList.cpp
	srcs/debugger/SymbolNonTerminalXCommand.cpp
	srcs/debugger/SymbolTerminalAnd.cpp
	srcs/debugger/SymbolTerminalAssign.cpp
	srcs/debugger/SymbolTerminalBinaryAnd.cpp
	srcs/debugger/SymbolTerminalBinary.cpp
	srcs/debugger/SymbolTerminalBinaryOr.cpp
	srcs/debugger/SymbolTerminalBreakpoint.cpp
	srcs/debugger/SymbolTerminalClosedParenthesis.cpp
	srcs/debugger/SymbolTerminalCommand.cpp
	srcs/debugger/SymbolTerminalDecimal.cpp
	srcs/debugger/SymbolTerminalDelete.cpp
	srcs/debugger/SymbolTerminalDivide.cpp
	srcs/debugger/SymbolTerminalDivOffset.cpp
	srcs/debugger/SymbolTerminalEqual.cpp
	srcs/debugger/SymbolTerminalExpansion.cpp
	srcs/debugger/SymbolTerminalGreater.cpp
	srcs/debugger/SymbolTerminalGreaterOrEqual.cpp
	srcs/debugger/SymbolTerminalHalfWordFormat.cpp
	srcs/debugger/SymbolTerminalHelp.cpp
	srcs/debugger/SymbolTerminalHexadecimal.cpp
	srcs/debugger/SymbolTerminalInfo.cpp
	srcs/debugger/SymbolTerminalInstruction.cpp
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
	srcs/debugger/SymbolTerminalOctal.cpp
	srcs/debugger/SymbolTerminalOpenParenthesis.cpp
	srcs/debugger/SymbolTerminalOr.cpp
	srcs/debugger/SymbolTerminalPlus.cpp
	srcs/debugger/SymbolTerminalPrintCommandParams.cpp
	srcs/debugger/SymbolTerminalPrint.cpp
	srcs/debugger/SymbolTerminalPrintingCommand.cpp
	srcs/debugger/SymbolTerminalProgramCounter.cpp
	srcs/debugger/SymbolTerminalQuit.cpp
	srcs/debugger/SymbolTerminalReadMode.cpp
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
	srcs/debugger/SymbolTerminalSet.cpp
	srcs/debugger/SymbolTerminalStackPointer.cpp
	srcs/debugger/SymbolTerminalStep.cpp
	srcs/debugger/SymbolTerminalTimaOffset.cpp
	srcs/debugger/SymbolTerminalUnwatch.cpp
	srcs/debugger/SymbolTerminalVariable.cpp
	srcs/debugger/SymbolTerminalVerbose.cpp
	srcs/debugger/SymbolTerminalWatch.cpp
	srcs/debugger/SymbolTerminalWordFormat.cpp
	srcs/debugger/SymbolTerminalWriteMode.cpp
	srcs/debugger/SymbolTerminalX.cpp
	srcs/debugger/TokenPrintCommandSuffix.cpp
	)

	list(APPEND HEADERS
	includes/debugger/libyacc_wrapper.h
	includes/debugger/DebuggerContext.hpp
	includes/debugger/DebuggerGrammar.hpp
	includes/debugger/SymbolNonTerminalAndOr.hpp
	includes/debugger/SymbolNonTerminalAssignable.hpp
	includes/debugger/SymbolNonTerminalAssignableList.hpp
	includes/debugger/SymbolNonTerminalBreakpointCommand.hpp
	includes/debugger/SymbolNonTerminalCommand.hpp
	includes/debugger/SymbolNonTerminalCommandName.hpp
	includes/debugger/SymbolNonTerminalComparison.hpp
	includes/debugger/SymbolNonTerminalDeleteCommand.hpp
	includes/debugger/SymbolNonTerminalExpr.hpp
	includes/debugger/SymbolNonTerminalFactor.hpp
	includes/debugger/SymbolNonTerminalFormat.hpp
	includes/debugger/SymbolNonTerminalHelpCommand.hpp
	includes/debugger/SymbolNonTerminalInfoCommand.hpp
	includes/debugger/SymbolNonTerminalIntegerList.hpp
	includes/debugger/SymbolNonTerminalIoPort.hpp
	includes/debugger/SymbolNonTerminalNextCommand.hpp
	includes/debugger/SymbolNonTerminalPrintCommand.hpp
	includes/debugger/SymbolNonTerminalPrintCommandSuffix.hpp
	includes/debugger/SymbolNonTerminalQuitCommand.hpp
	includes/debugger/SymbolNonTerminalRegisterName.hpp
	includes/debugger/SymbolNonTerminalRegistersCommand.hpp
	includes/debugger/SymbolNonTerminalSetCommand.hpp
	includes/debugger/SymbolNonTerminalStepCommand.hpp
	includes/debugger/SymbolNonTerminalTerm.hpp
	includes/debugger/SymbolNonTerminalUnit.hpp
	includes/debugger/SymbolNonTerminalUnwatchCommand.hpp
	includes/debugger/SymbolNonTerminalValue.hpp
	includes/debugger/SymbolNonTerminalVariable.hpp
	includes/debugger/SymbolNonTerminalVector.hpp
	includes/debugger/SymbolNonTerminalVerboseCommand.hpp
	includes/debugger/SymbolNonTerminalWatchCommand.hpp
	includes/debugger/SymbolNonTerminalWatchMode.hpp
	includes/debugger/SymbolNonTerminalWatchModeList.hpp
	includes/debugger/SymbolNonTerminalXCommand.hpp
	includes/debugger/SymbolTerminalAnd.hpp
	includes/debugger/SymbolTerminalAssign.hpp
	includes/debugger/SymbolTerminalBinaryAnd.hpp
	includes/debugger/SymbolTerminalBinary.hpp
	includes/debugger/SymbolTerminalBinaryOr.hpp
	includes/debugger/SymbolTerminalBreakpoint.hpp
	includes/debugger/SymbolTerminalClosedParenthesis.hpp
	includes/debugger/SymbolTerminalCommand.hpp
	includes/debugger/SymbolTerminalDecimal.hpp
	includes/debugger/SymbolTerminalDelete.hpp
	includes/debugger/SymbolTerminalDivide.hpp
	includes/debugger/SymbolTerminalDivOffset.hpp
	includes/debugger/SymbolTerminalEqual.hpp
	includes/debugger/SymbolTerminalExpansion.hpp
	includes/debugger/SymbolTerminalGreater.hpp
	includes/debugger/SymbolTerminalGreaterOrEqual.hpp
	includes/debugger/SymbolTerminalHalfWordFormat.hpp
	includes/debugger/SymbolTerminalHelp.hpp
	includes/debugger/SymbolTerminalHexadecimal.hpp
	includes/debugger/SymbolTerminalInfo.hpp
	includes/debugger/SymbolTerminalInstruction.hpp
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
	includes/debugger/SymbolTerminalOctal.hpp
	includes/debugger/SymbolTerminalOpenParenthesis.hpp
	includes/debugger/SymbolTerminalOr.hpp
	includes/debugger/SymbolTerminalPlus.hpp
	includes/debugger/SymbolTerminalPrintCommandParams.hpp
	includes/debugger/SymbolTerminalPrint.hpp
	includes/debugger/SymbolTerminalPrintingCommand.hpp
	includes/debugger/SymbolTerminalProgramCounter.hpp
	includes/debugger/SymbolTerminalQuit.hpp
	includes/debugger/SymbolTerminalReadMode.hpp
	includes/debugger/SymbolTerminalRegisterAF.hpp
	includes/debugger/SymbolTerminalRegisterA.hpp
	includes/debugger/SymbolTerminalRegisterBC.hpp
	includes/debugger/SymbolTerminalRegisterB.hpp
	includes/debugger/SymbolTerminalRegisterC.hpp
	includes/debugger/SymbolTerminalRegisterDE.hpp
	includes/debugger/SymbolTerminalRegisterD.hpp
	includes/debugger/SymbolTerminalRegisterE.hpp
	includes/debugger/SymbolTerminalRegisterF.hpp
	includes/debugger/SymbolTerminalRegisterH.hpp
	includes/debugger/SymbolTerminalRegisterHL.hpp
	includes/debugger/SymbolTerminalRegisterL.hpp
	includes/debugger/SymbolTerminalRegisters.hpp
	includes/debugger/SymbolTerminalRightShift.hpp
	includes/debugger/SymbolTerminalSet.hpp
	includes/debugger/SymbolTerminalStackPointer.hpp
	includes/debugger/SymbolTerminalStep.hpp
	includes/debugger/SymbolTerminalTimaOffset.hpp
	includes/debugger/SymbolTerminalUnwatch.hpp
	includes/debugger/SymbolTerminalVariable.hpp
	includes/debugger/SymbolTerminalVerbose.hpp
	includes/debugger/SymbolTerminalWatch.hpp
	includes/debugger/SymbolTerminalWordFormat.hpp
	includes/debugger/SymbolTerminalWriteMode.hpp
	includes/debugger/SymbolTerminalX.hpp
	includes/debugger/TokenPrintCommandSuffix.hpp
	)

include_directories(srcs)
include_directories(includes)
include_directories(includes/debugger)
include_directories(libyacc/includes)
include_directories(${Readline_INCLUDE_DIR})



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
FILE(GLOB GENERATED_LIBYACC_SOURCES srcs/debugger/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${GENERATED_LIBYACC_SOURCES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} GLEW::GLEW)
target_link_libraries(${PROJECT_NAME} ${Readline_LIBRARY})

################################################
#                   INSTALL                    #
################################################

foreach(shader ${SHADERS})
	get_filename_component(filename ${shader} NAME)

	add_custom_command(
	 	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename}
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${shader} ${CMAKE_CURRENT_BINARY_DIR}/shaders/${filename}
		MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/${shader})
endforeach()
