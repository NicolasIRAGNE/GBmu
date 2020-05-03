# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#              #
#    Updated: 2020/05/02 19:14:15 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	debuggerTest

CC				=	g++ -std=c++11 -O3

ECHO			=	echo
MKDIR			=	mkdir

DEBUG ?= 0

SRCDIR			=	srcs/parser/
OBJDIR			=	objs/
BINDIR			=	./
INCLUDESDIR		=	includes/parser/

INCLUDES		=	DebuggerGrammar.hpp \
					SymbolTerminalInterruptStat.hpp \
					SymbolTerminalSet.hpp \
					SymbolTerminalGreaterOrEqual.hpp \
					SymbolTerminalRightShift.hpp \
					SymbolTerminalRegisterAF.hpp \
					SymbolTerminalOr.hpp \
					SymbolTerminalLesserOrEqual.hpp \
					SymbolTerminalInterruptVBlank.hpp \
					SymbolTerminalRegisters.hpp \
					SymbolTerminalRegisterHL.hpp \
					SymbolTerminalExpansion.hpp \
					SymbolTerminalNotEqual.hpp \
					SymbolTerminalHelp.hpp \
					SymbolTerminalQuit.hpp \
					SymbolTerminalModulo.hpp \
					SymbolTerminalBinaryAnd.hpp \
					SymbolTerminalClosedParenthesis.hpp \
					SymbolTerminalOpenParenthesis.hpp \
					SymbolTerminalPlus.hpp \
					SymbolTerminalMultiply.hpp \
					SymbolTerminalMinus.hpp \
					SymbolTerminalDivide.hpp \
					SymbolTerminalNext.hpp \
					SymbolTerminalProgramCounter.hpp \
					SymbolTerminalPrint.hpp \
					SymbolTerminalInteger.hpp \
					SymbolTerminalDivOffset.hpp \
					SymbolTerminalAssign.hpp \
					SymbolTerminalLesser.hpp \
					SymbolTerminalGreater.hpp \
					SymbolTerminalInfo.hpp \
					SymbolTerminalRegisterBC.hpp \
					SymbolTerminalEqual.hpp \
					SymbolTerminalInterruptJoypad.hpp \
					SymbolTerminalRegisterDE.hpp \
					SymbolTerminalWatch.hpp \
					SymbolTerminalInterruptTimer.hpp \
					SymbolTerminalHalfWordFormat.hpp \
					SymbolTerminalWordFormat.hpp \
					SymbolTerminalTodoOffset.hpp \
					SymbolTerminalTimaOffset.hpp \
					SymbolTerminalAnd.hpp \
					SymbolTerminalBreakpoint.hpp \
					SymbolTerminalStep.hpp \
					SymbolTerminalVerbose.hpp \
					SymbolTerminalInterruptSerial.hpp \
					SymbolTerminalLeftShift.hpp \
					SymbolTerminalRegisterA.hpp \
					SymbolTerminalUnwatch.hpp \
					SymbolTerminalRegisterC.hpp \
					SymbolTerminalRegisterB.hpp \
					SymbolTerminalRegisterE.hpp \
					SymbolTerminalRegisterD.hpp \
					SymbolTerminalRegisterF.hpp \
					SymbolTerminalInstruction.hpp \
					SymbolTerminalRegisterH.hpp \
					SymbolTerminalDecimal.hpp \
					SymbolTerminalStackPointer.hpp \
					SymbolTerminalRegisterL.hpp \
					SymbolTerminalOctal.hpp \
					SymbolTerminalReadMode.hpp \
					SymbolTerminalWriteMode.hpp \
					SymbolTerminalHexadecimal.hpp \
					SymbolTerminalBinaryOr.hpp \
					SymbolTerminalBinary.hpp \
					SymbolTerminalDelete.hpp \
					SymbolTerminalX.hpp \
					SymbolNonTerminalPrintCommand.hpp \
					SymbolNonTerminalWatchMode.hpp \
					SymbolNonTerminalQuitCommand.hpp \
					SymbolNonTerminalVerboseCommand.hpp \
					SymbolNonTerminalRegistersCommand.hpp \
					SymbolNonTerminalRegisterName.hpp \
					SymbolNonTerminalXSuffix.hpp \
					SymbolNonTerminalUnit.hpp \
					SymbolNonTerminalIntegerList.hpp \
					SymbolNonTerminalIoPort.hpp \
					SymbolNonTerminalCommandName.hpp \
					SymbolNonTerminalUnwatchCommand.hpp \
					SymbolNonTerminalComparison.hpp \
					SymbolNonTerminalFactor.hpp \
					SymbolNonTerminalWatchModeList.hpp \
					SymbolNonTerminalStepCommand.hpp \
					SymbolNonTerminalFormat.hpp \
					SymbolNonTerminalInfoCommand.hpp \
					SymbolNonTerminalNextCommand.hpp \
					SymbolNonTerminalXCommand.hpp \
					SymbolNonTerminalVariable.hpp \
					SymbolNonTerminalSetCommand.hpp \
					SymbolNonTerminalHelpCommand.hpp \
					SymbolNonTerminalAssignable.hpp \
					SymbolNonTerminalTerm.hpp \
					SymbolNonTerminalWatchCommand.hpp \
					SymbolNonTerminalAndOr.hpp \
					SymbolNonTerminalExpr.hpp \
					SymbolNonTerminalValue.hpp \
					SymbolNonTerminalVector.hpp \
					SymbolNonTerminalCommand.hpp \
					SymbolNonTerminalDeleteCommand.hpp \
					SymbolNonTerminalBreakpointCommand.hpp \
					SymbolTerminalCommand.hpp \
					SymbolTerminalVariable.hpp\
					SymbolTerminalPrintingCommand.hpp \
					DebuggerContext.hpp \

SRCS			=	DebuggerGrammar.cpp \
					SymbolTerminalInterruptStat.cpp \
					SymbolTerminalSet.cpp \
					SymbolTerminalGreaterOrEqual.cpp \
					SymbolTerminalRightShift.cpp \
					SymbolTerminalRegisterAF.cpp \
					SymbolTerminalOr.cpp \
					SymbolTerminalLesserOrEqual.cpp \
					SymbolTerminalInterruptVBlank.cpp \
					SymbolTerminalRegisters.cpp \
					SymbolTerminalDecimal.cpp \
					SymbolTerminalRegisterHL.cpp \
					SymbolTerminalExpansion.cpp \
					SymbolTerminalNotEqual.cpp \
					SymbolTerminalHelp.cpp \
					SymbolTerminalQuit.cpp \
					SymbolTerminalModulo.cpp \
					SymbolTerminalBinaryAnd.cpp \
					SymbolTerminalClosedParenthesis.cpp \
					SymbolTerminalOpenParenthesis.cpp \
					SymbolTerminalPlus.cpp \
					SymbolTerminalMultiply.cpp \
					SymbolTerminalMinus.cpp \
					SymbolTerminalDivide.cpp \
					SymbolTerminalNext.cpp \
					SymbolTerminalProgramCounter.cpp \
					SymbolTerminalPrint.cpp \
					SymbolTerminalInteger.cpp \
					SymbolTerminalDivOffset.cpp \
					SymbolTerminalAssign.cpp \
					SymbolTerminalLesser.cpp \
					SymbolTerminalGreater.cpp \
					SymbolTerminalInfo.cpp \
					SymbolTerminalRegisterBC.cpp \
					SymbolTerminalEqual.cpp \
					SymbolTerminalInterruptJoypad.cpp \
					SymbolTerminalRegisterDE.cpp \
					SymbolTerminalWatch.cpp \
					SymbolTerminalInterruptTimer.cpp \
					SymbolTerminalHalfWordFormat.cpp \
					SymbolTerminalWordFormat.cpp \
					SymbolTerminalTodoOffset.cpp \
					SymbolTerminalTimaOffset.cpp \
					SymbolTerminalAnd.cpp \
					SymbolTerminalBreakpoint.cpp \
					SymbolTerminalStep.cpp \
					SymbolTerminalVerbose.cpp \
					SymbolTerminalInterruptSerial.cpp \
					SymbolTerminalLeftShift.cpp \
					SymbolTerminalRegisterA.cpp \
					SymbolTerminalUnwatch.cpp \
					SymbolTerminalRegisterC.cpp \
					SymbolTerminalRegisterB.cpp \
					SymbolTerminalRegisterE.cpp \
					SymbolTerminalRegisterD.cpp \
					SymbolTerminalRegisterF.cpp \
					SymbolTerminalInstruction.cpp \
					SymbolTerminalRegisterH.cpp \
					SymbolTerminalStackPointer.cpp \
					SymbolTerminalRegisterL.cpp \
					SymbolTerminalOctal.cpp \
					SymbolTerminalReadMode.cpp \
					SymbolTerminalWriteMode.cpp \
					SymbolTerminalHexadecimal.cpp \
					SymbolTerminalBinaryOr.cpp \
					SymbolTerminalBinary.cpp \
					SymbolTerminalDelete.cpp \
					SymbolTerminalVariable.cpp \
					SymbolTerminalCommand.cpp \
					SymbolTerminalPrintingCommand.cpp \
					SymbolTerminalX.cpp \
					SymbolNonTerminalPrintCommand.cpp \
					SymbolNonTerminalWatchMode.cpp \
					SymbolNonTerminalQuitCommand.cpp \
					SymbolNonTerminalVerboseCommand.cpp \
					SymbolNonTerminalRegistersCommand.cpp \
					SymbolNonTerminalRegisterName.cpp \
					SymbolNonTerminalXSuffix.cpp \
					SymbolNonTerminalUnit.cpp \
					SymbolNonTerminalIntegerList.cpp \
					SymbolNonTerminalIoPort.cpp \
					SymbolNonTerminalCommandName.cpp \
					SymbolNonTerminalUnwatchCommand.cpp \
					SymbolNonTerminalComparison.cpp \
					SymbolNonTerminalFactor.cpp \
					SymbolNonTerminalWatchModeList.cpp \
					SymbolNonTerminalStepCommand.cpp \
					SymbolNonTerminalFormat.cpp \
					SymbolNonTerminalInfoCommand.cpp \
					SymbolNonTerminalNextCommand.cpp \
					SymbolNonTerminalXCommand.cpp \
					SymbolNonTerminalVariable.cpp \
					SymbolNonTerminalSetCommand.cpp \
					SymbolNonTerminalHelpCommand.cpp \
					SymbolNonTerminalAssignable.cpp \
					SymbolNonTerminalTerm.cpp \
					SymbolNonTerminalWatchCommand.cpp \
					SymbolNonTerminalAndOr.cpp \
					SymbolNonTerminalExpr.cpp \
					SymbolNonTerminalValue.cpp \
					SymbolNonTerminalVector.cpp \
					SymbolNonTerminalCommand.cpp \
					SymbolNonTerminalDeleteCommand.cpp \
					SymbolNonTerminalBreakpointCommand.cpp \
					main.cpp \
					DebuggerContext.cpp \

VPATH				=	$(INCLUDESDIR) \
					=	$(SRCDIR)

OBJECTS			=	$(addprefix $(OBJDIR), $(SRCS:.cpp=.o))
CFLAGS			=	-I $(INCLUDESDIR) -Wall -Wextra -Werror -I includes -I libyacc/includes

OK_COLOR			=	\x1b[32;01m
EOC					=	\033[0m

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address
	CC += -g3
endif

all: $(NAME)

debug:
	@$(MAKE) all DEBUG=1

$(BINDIR)$(NAME): $(OBJDIR) $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)
	@$(ECHO) "$(OK_COLOR)$(NAME) linked with success ! $(EOC)"

$(OBJDIR):
	@$(MKDIR) $@

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(INCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) -rf $(OBJDIR)
fclean: clean
	@$(RM) -f $(BINDIR)$(NAME)

re: fclean all

.PHONY: all clean fclean re debug
