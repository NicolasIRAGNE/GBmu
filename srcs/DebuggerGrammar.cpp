/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerGrammar.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:47:46 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 12:47:46 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DebuggerGrammar.hpp"
#include "../includes/CustomStack.hpp"

DebuggerGrammar::DebuggerGrammar(void) : AbstractGrammar(new SymbolNonTerminalCommand(), false)
{
	addNonTerminal(new SymbolNonTerminalPrintCommand());
	addNonTerminal(new SymbolNonTerminalXCommand());
	addNonTerminal(new SymbolNonTerminalSimpleCommand());
	addNonTerminal(new SymbolNonTerminalSeparatorPipeline());
	addNonTerminal(new SymbolNonTerminalSeparatorPipelineOrEPS());
	addNonTerminal(new SymbolNonTerminalValue());
	addNonTerminal(new SymbolNonTerminalFormat());
	addNonTerminal(new SymbolNonTerminalXSuffix());
	addNonTerminal(new SymbolNonTerminalUnit());
	addNonTerminal(new SymbolNonTerminalInnerValue());
	addNonTerminal(new SymbolNonTerminalAndOr());
	addNonTerminal(new SymbolNonTerminalComparison());
	addNonTerminal(new SymbolNonTerminalExpr());
	addNonTerminal(new SymbolNonTerminalTerm());
	addNonTerminal(new SymbolNonTerminalCommandName());
	addNonTerminal(new SymbolNonTerminalCommandSuffix());
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
	addTerminal(new SymbolTerminalSeparator());
	addTerminal(new SymbolTerminalInteger());
	addTerminal(new SymbolTerminalVariable());

	computeGrammar();
}

DebuggerGrammar::DebuggerGrammar(DebuggerGrammar const &instance) : AbstractGrammar<int, CustomStack &>(instance)
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
