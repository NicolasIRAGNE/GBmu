/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerGrammar.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 15:36:19 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/24 17:03:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DebuggerGrammar.hpp"
#include "DebuggerContext.hpp"

DebuggerGrammar::DebuggerGrammar(void) : AbstractGrammar(new SymbolNonTerminalCommand(), true)
{
	addNonTerminal(new SymbolNonTerminalPrintCommand());
	addNonTerminal(new SymbolNonTerminalXCommand());
	addNonTerminal(new SymbolNonTerminalStepCommand());
	addNonTerminal(new SymbolNonTerminalNextCommand());
	addNonTerminal(new SymbolNonTerminalBreakpointCommand());
	addNonTerminal(new SymbolNonTerminalDeleteCommand());
	addNonTerminal(new SymbolNonTerminalInfoCommand());
	addNonTerminal(new SymbolNonTerminalRegistersCommand());
	addNonTerminal(new SymbolNonTerminalQuitCommand());
	addNonTerminal(new SymbolNonTerminalVerboseCommand());
	addNonTerminal(new SymbolNonTerminalValue());
	addNonTerminal(new SymbolNonTerminalFormat());
	addNonTerminal(new SymbolNonTerminalXSuffix());
	addNonTerminal(new SymbolNonTerminalUnit());
	addNonTerminal(new SymbolNonTerminalAndOr());
	addNonTerminal(new SymbolNonTerminalComparison());
	addNonTerminal(new SymbolNonTerminalExpr());
	addNonTerminal(new SymbolNonTerminalTerm());
	addNonTerminal(new SymbolNonTerminalFactor());

	addTerminal(new SymbolTerminalGreater());
	addTerminal(new SymbolTerminalGreaterOrEqual());
	addTerminal(new SymbolTerminalLesser());
	addTerminal(new SymbolTerminalLesserOrEqual());
	addTerminal(new SymbolTerminalAnd());
	addTerminal(new SymbolTerminalOr());
	addTerminal(new SymbolTerminalBinaryAnd());
	addTerminal(new SymbolTerminalBinaryOr());
	addTerminal(new SymbolTerminalLeftShift());
	addTerminal(new SymbolTerminalRightShift());
	addTerminal(new SymbolTerminalNotEqual());
	addTerminal(new SymbolTerminalEqual());
	addTerminal(new SymbolTerminalMultiply());
	addTerminal(new SymbolTerminalDivide());
	addTerminal(new SymbolTerminalModulo());
	addTerminal(new SymbolTerminalMinus());
	addTerminal(new SymbolTerminalPlus());
	addTerminal(new SymbolTerminalDecimal());
	addTerminal(new SymbolTerminalHexadecimal());
	addTerminal(new SymbolTerminalOctal());
	addTerminal(new SymbolTerminalBinary());
	addTerminal(new SymbolTerminalOpenParenthesis());
	addTerminal(new SymbolTerminalClosedParenthesis());
	addTerminal(new SymbolTerminalHalfWordFormat());
	addTerminal(new SymbolTerminalWordFormat());
	addTerminal(new SymbolTerminalPrint());
	addTerminal(new SymbolTerminalStep());
	addTerminal(new SymbolTerminalNext());
	addTerminal(new SymbolTerminalBreakpoint());
	addTerminal(new SymbolTerminalDelete());
	addTerminal(new SymbolTerminalInfo());
	addTerminal(new SymbolTerminalRegisters());
	addTerminal(new SymbolTerminalQuit());
	addTerminal(new SymbolTerminalVerbose());
	addTerminal(new SymbolTerminalInteger());

	computeGrammar();
}

DebuggerGrammar::DebuggerGrammar(DebuggerGrammar const &instance) : AbstractGrammar<int, DebuggerContext &>(instance)
{
	*this = instance;
}

DebuggerGrammar::~DebuggerGrammar(void)
{
	
}

DebuggerGrammar & DebuggerGrammar::operator=(DebuggerGrammar const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}
