/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerGrammar.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:03:31 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 17:52:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERGRAMMAR_HPP
# define DEBUGGERGRAMMAR_HPP

#include "AbstractGrammar.hpp"

#include "DebuggerContext.hpp"
#include "SymbolNonTerminalPrintCommand.hpp"
#include "SymbolNonTerminalQuitCommand.hpp"
#include "SymbolNonTerminalVerboseCommand.hpp"
#include "SymbolNonTerminalRegistersCommand.hpp"
#include "SymbolNonTerminalIntegerList.hpp"
#include "SymbolNonTerminalIoPort.hpp"
#include "SymbolNonTerminalCommandName.hpp"
#include "SymbolNonTerminalComparison.hpp"
#include "SymbolNonTerminalFactor.hpp"
#include "SymbolNonTerminalStepCommand.hpp"
#include "SymbolNonTerminalInfoCommand.hpp"
#include "SymbolNonTerminalNextCommand.hpp"
#include "SymbolNonTerminalXCommand.hpp"
#include "SymbolNonTerminalVariable.hpp"
#include "SymbolNonTerminalSetCommand.hpp"
#include "SymbolNonTerminalHelpCommand.hpp"
#include "SymbolNonTerminalAssignable.hpp"
#include "SymbolNonTerminalAddress.hpp"
#include "SymbolNonTerminalTerm.hpp"
#include "SymbolNonTerminalWatchCommand.hpp"
#include "SymbolNonTerminalAndOr.hpp"
#include "SymbolNonTerminalExpr.hpp"
#include "SymbolNonTerminalValue.hpp"
#include "SymbolNonTerminalVector.hpp"
#include "SymbolNonTerminalCommand.hpp"
#include "SymbolNonTerminalDeleteCommand.hpp"
#include "SymbolNonTerminalBreakpointCommand.hpp"
#include "SymbolNonTerminalPrintCommandSuffix.hpp"

#include "SymbolTerminalInterruptStat.hpp"
#include "SymbolTerminalSet.hpp"
#include "SymbolTerminalGreaterOrEqual.hpp"
#include "SymbolTerminalRightShift.hpp"
#include "SymbolTerminalRegisterAF.hpp"
#include "SymbolTerminalOr.hpp"
#include "SymbolTerminalLesserOrEqual.hpp"
#include "SymbolTerminalInterruptVBlank.hpp"
#include "SymbolTerminalRegisters.hpp"
#include "SymbolTerminalRegisterHL.hpp"
#include "SymbolTerminalExpansion.hpp"
#include "SymbolTerminalNotEqual.hpp"
#include "SymbolTerminalHelp.hpp"
#include "SymbolTerminalQuit.hpp"
#include "SymbolTerminalModulo.hpp"
#include "SymbolTerminalBinaryAnd.hpp"
#include "SymbolTerminalClosedParenthesis.hpp"
#include "SymbolTerminalOpenParenthesis.hpp"
#include "SymbolTerminalPlus.hpp"
#include "SymbolTerminalMultiply.hpp"
#include "SymbolTerminalMinus.hpp"
#include "SymbolTerminalDivide.hpp"
#include "SymbolTerminalNext.hpp"
#include "SymbolTerminalProgramCounter.hpp"
#include "SymbolTerminalPrint.hpp"
#include "SymbolTerminalInteger.hpp"
#include "SymbolTerminalDivOffset.hpp"
#include "SymbolTerminalAssign.hpp"
#include "SymbolTerminalLesser.hpp"
#include "SymbolTerminalGreater.hpp"
#include "SymbolTerminalInfo.hpp"
#include "SymbolTerminalRegisterBC.hpp"
#include "SymbolTerminalEqual.hpp"
#include "SymbolTerminalInterruptJoypad.hpp"
#include "SymbolTerminalRegisterDE.hpp"
#include "SymbolTerminalWatch.hpp"
#include "SymbolTerminalAnd.hpp"
#include "SymbolTerminalBreakpoint.hpp"
#include "SymbolTerminalStep.hpp"
#include "SymbolTerminalVerbose.hpp"
#include "SymbolTerminalInterruptSerial.hpp"
#include "SymbolTerminalLeftShift.hpp"
#include "SymbolTerminalBinaryOr.hpp"
#include "SymbolTerminalDelete.hpp"
#include "SymbolTerminalX.hpp"
#include "SymbolTerminalPrintCommandParams.hpp"
#include "SymbolTerminalWatchModes.hpp"

class DebuggerGrammar : public AbstractGrammar<int, DebuggerContext &>
{
	public:
		DebuggerGrammar(void);
		DebuggerGrammar(DebuggerGrammar const &instance);
		DebuggerGrammar &operator=(DebuggerGrammar const &rhs);
		virtual ~DebuggerGrammar(void);
		
		virtual bool treatTerminalEligibility(std::string current
		, AbstractTerminal<int, DebuggerContext &> **terminal
		, std::deque<Token<int, DebuggerContext &> *>tokens
		, bool & ambiguous
		, int & staysEligiblePos
		, int & isEligiblePos);

		virtual std::deque<Token<int, DebuggerContext &> *> innerLex(bool stopAtNewline, std::istream & istream);
	private:

};

#endif
