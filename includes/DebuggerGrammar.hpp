/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerGrammar.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:47:46 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 12:47:46 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERGRAMMAR_HPP
# define DEBUGGERGRAMMAR_HPP

#include "../libyacc/includes/AbstractGrammar.hpp"

#include "CustomStack.hpp"
#include "SymbolNonTerminalCommand.hpp"
#include "SymbolNonTerminalPrintCommand.hpp"
#include "SymbolNonTerminalXCommand.hpp"
#include "SymbolNonTerminalSimpleCommand.hpp"
#include "SymbolNonTerminalSeparatorPipeline.hpp"
#include "SymbolNonTerminalSeparatorPipelineOrEPS.hpp"
#include "SymbolNonTerminalValue.hpp"
#include "SymbolNonTerminalFormat.hpp"
#include "SymbolNonTerminalXSuffix.hpp"
#include "SymbolNonTerminalUnit.hpp"
#include "SymbolNonTerminalInnerValue.hpp"
#include "SymbolNonTerminalAndOr.hpp"
#include "SymbolNonTerminalComparison.hpp"
#include "SymbolNonTerminalExpr.hpp"
#include "SymbolNonTerminalTerm.hpp"
#include "SymbolNonTerminalCommandName.hpp"
#include "SymbolNonTerminalCommandSuffix.hpp"
#include "SymbolNonTerminalFactor.hpp"

#include "SymbolTerminalGreater.hpp"
#include "SymbolTerminalGreaterOrEqual.hpp"
#include "SymbolTerminalLesser.hpp"
#include "SymbolTerminalLesserOrEqual.hpp"
#include "SymbolTerminalAnd.hpp"
#include "SymbolTerminalOr.hpp"
#include "SymbolTerminalBinaryAnd.hpp"
#include "SymbolTerminalBinaryOr.hpp"
#include "SymbolTerminalLeftShift.hpp"
#include "SymbolTerminalRightShift.hpp"
#include "SymbolTerminalNotEqual.hpp"
#include "SymbolTerminalEqual.hpp"
#include "SymbolTerminalMultiply.hpp"
#include "SymbolTerminalDivide.hpp"
#include "SymbolTerminalModulo.hpp"
#include "SymbolTerminalMinus.hpp"
#include "SymbolTerminalPlus.hpp"
#include "SymbolTerminalDecimal.hpp"
#include "SymbolTerminalHexadecimal.hpp"
#include "SymbolTerminalOctal.hpp"
#include "SymbolTerminalBinary.hpp"
#include "SymbolTerminalOpenParenthesis.hpp"
#include "SymbolTerminalClosedParenthesis.hpp"
#include "SymbolTerminalHalfWordFormat.hpp"
#include "SymbolTerminalWordFormat.hpp"
#include "SymbolTerminalPrint.hpp"
#include "SymbolTerminalSeparator.hpp"
#include "SymbolTerminalInteger.hpp"
#include "SymbolTerminalVariable.hpp"

class DebuggerGrammar : public AbstractGrammar<int, CustomStack &>
{
	public:
		DebuggerGrammar(void);
		DebuggerGrammar(DebuggerGrammar const &instance);
		DebuggerGrammar &operator=(DebuggerGrammar const &rhs);
		virtual ~DebuggerGrammar(void);

	private:

};

#endif
