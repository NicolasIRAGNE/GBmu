/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerGrammar.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 19:16:33 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/24 19:16:33 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERGRAMMAR_HPP
# define DEBUGGERGRAMMAR_HPP

#include "AbstractGrammar.hpp"

#include "DebuggerContext.hpp"
#include "SymbolNonTerminalCommand.hpp"
#include "SymbolNonTerminalPrintCommand.hpp"
#include "SymbolNonTerminalXCommand.hpp"
#include "SymbolNonTerminalStepCommand.hpp"
#include "SymbolNonTerminalNextCommand.hpp"
#include "SymbolNonTerminalBreakpointCommand.hpp"
#include "SymbolNonTerminalDeleteCommand.hpp"
#include "SymbolNonTerminalInfoCommand.hpp"
#include "SymbolNonTerminalRegistersCommand.hpp"
#include "SymbolNonTerminalQuitCommand.hpp"
#include "SymbolNonTerminalVerboseCommand.hpp"
#include "SymbolNonTerminalValue.hpp"
#include "SymbolNonTerminalFormat.hpp"
#include "SymbolNonTerminalXSuffix.hpp"
#include "SymbolNonTerminalUnit.hpp"
#include "SymbolNonTerminalAndOr.hpp"
#include "SymbolNonTerminalComparison.hpp"
#include "SymbolNonTerminalExpr.hpp"
#include "SymbolNonTerminalTerm.hpp"
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
#include "SymbolTerminalStep.hpp"
#include "SymbolTerminalNext.hpp"
#include "SymbolTerminalBreakpoint.hpp"
#include "SymbolTerminalDelete.hpp"
#include "SymbolTerminalInfo.hpp"
#include "SymbolTerminalRegisters.hpp"
#include "SymbolTerminalQuit.hpp"
#include "SymbolTerminalVerbose.hpp"
#include "SymbolTerminalInteger.hpp"

class DebuggerGrammar : public AbstractGrammar<int, DebuggerContext &>
{
	public:
		DebuggerGrammar(void);
		DebuggerGrammar(DebuggerGrammar const &instance);
		DebuggerGrammar &operator=(DebuggerGrammar const &rhs);
		virtual ~DebuggerGrammar(void);

	private:

};

#endif
