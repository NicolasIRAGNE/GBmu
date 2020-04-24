# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/24 15:36:19 by ldedier           #+#    #+#              #
#    Updated: 2020/04/24 17:04:00 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	debuggerTest

CC				=	g++ -std=c++11

ECHO			=	echo
MKDIR			=	mkdir

DEBUG ?= 0

SRCDIR			=	srcs/parser/
OBJDIR			=	objs/
BINDIR			=	./
INCLUDESDIR		=	includes/parser/

INCLUDES		=	DebuggerGrammar.hpp \
					SymbolTerminalGreater.hpp \
					SymbolTerminalGreaterOrEqual.hpp \
					SymbolTerminalLesser.hpp \
					SymbolTerminalLesserOrEqual.hpp \
					SymbolTerminalAnd.hpp \
					SymbolTerminalOr.hpp \
					SymbolTerminalBinaryAnd.hpp \
					SymbolTerminalBinaryOr.hpp \
					SymbolTerminalLeftShift.hpp \
					SymbolTerminalRightShift.hpp \
					SymbolTerminalNotEqual.hpp \
					SymbolTerminalEqual.hpp \
					SymbolTerminalMultiply.hpp \
					SymbolTerminalDivide.hpp \
					SymbolTerminalModulo.hpp \
					SymbolTerminalMinus.hpp \
					SymbolTerminalPlus.hpp \
					SymbolTerminalDecimal.hpp \
					SymbolTerminalHexadecimal.hpp \
					SymbolTerminalOctal.hpp \
					SymbolTerminalBinary.hpp \
					SymbolTerminalOpenParenthesis.hpp \
					SymbolTerminalClosedParenthesis.hpp \
					SymbolTerminalHalfWordFormat.hpp \
					SymbolTerminalWordFormat.hpp \
					SymbolTerminalPrint.hpp \
					SymbolTerminalInteger.hpp \
					SymbolTerminalVariable.hpp \
					SymbolNonTerminalCommand.hpp \
					SymbolNonTerminalPrintCommand.hpp \
					SymbolNonTerminalXCommand.hpp \
					SymbolNonTerminalSimpleCommand.hpp \
					SymbolNonTerminalValue.hpp \
					SymbolNonTerminalFormat.hpp \
					SymbolNonTerminalXSuffix.hpp \
					SymbolNonTerminalUnit.hpp \
					SymbolNonTerminalAndOr.hpp \
					SymbolNonTerminalComparison.hpp \
					SymbolNonTerminalExpr.hpp \
					SymbolNonTerminalTerm.hpp \
					SymbolNonTerminalCommandName.hpp \
					SymbolNonTerminalCommandSuffix.hpp \
					SymbolNonTerminalFactor.hpp \
					DebuggerContext.hpp \

SRCS			=	DebuggerGrammar.cpp \
					SymbolTerminalGreater.cpp \
					SymbolTerminalGreaterOrEqual.cpp \
					SymbolTerminalLesser.cpp \
					SymbolTerminalLesserOrEqual.cpp \
					SymbolTerminalAnd.cpp \
					SymbolTerminalOr.cpp \
					SymbolTerminalBinaryAnd.cpp \
					SymbolTerminalBinaryOr.cpp \
					SymbolTerminalLeftShift.cpp \
					SymbolTerminalRightShift.cpp \
					SymbolTerminalNotEqual.cpp \
					SymbolTerminalEqual.cpp \
					SymbolTerminalMultiply.cpp \
					SymbolTerminalDivide.cpp \
					SymbolTerminalModulo.cpp \
					SymbolTerminalMinus.cpp \
					SymbolTerminalPlus.cpp \
					SymbolTerminalDecimal.cpp \
					SymbolTerminalHexadecimal.cpp \
					SymbolTerminalOctal.cpp \
					SymbolTerminalBinary.cpp \
					SymbolTerminalOpenParenthesis.cpp \
					SymbolTerminalClosedParenthesis.cpp \
					SymbolTerminalHalfWordFormat.cpp \
					SymbolTerminalWordFormat.cpp \
					SymbolTerminalPrint.cpp \
					SymbolTerminalInteger.cpp \
					SymbolTerminalVariable.cpp \
					SymbolNonTerminalCommand.cpp \
					SymbolNonTerminalPrintCommand.cpp \
					SymbolNonTerminalXCommand.cpp \
					SymbolNonTerminalSimpleCommand.cpp \
					SymbolNonTerminalValue.cpp \
					SymbolNonTerminalFormat.cpp \
					SymbolNonTerminalXSuffix.cpp \
					SymbolNonTerminalUnit.cpp \
					SymbolNonTerminalAndOr.cpp \
					SymbolNonTerminalComparison.cpp \
					SymbolNonTerminalExpr.cpp \
					SymbolNonTerminalTerm.cpp \
					SymbolNonTerminalCommandName.cpp \
					SymbolNonTerminalCommandSuffix.cpp \
					SymbolNonTerminalFactor.cpp \
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
	\CC += -g3
endif

all: $(NAME)

debug:
	@$(MAKE) all DEBUG=1

$(BINDIR)$(NAME): $(OBJDIR) $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)
	@$(ECHO) "$(OK_COLOR)$(NAME) linked with success ! $(EOC)"

$(OBJDIR):
	@$(MKDIR) $@

$(OBJDIR)%.o: $(SRC_DIR)%.cpp $(INCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) -rf $(OBJDIR)
fclean: clean
	@$(RM) -f $(BINDIR)$(NAME)

re: fclean all

.PHONY: all clean fclean re debug
