/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerGrammar.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:03:31 by ldedier           #+#    #+#             */
/*   Updated: 2021/06/04 13:36:04 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERGRAMMAR_HPP
# define DEBUGGERGRAMMAR_HPP

#include "AbstractGrammar.hpp"

#include "DebuggerContext.hpp"
#include "SymbolNonTerminalPrintCommand.hpp"
#include "SymbolNonTerminalRegisterName.hpp"
#include "SymbolNonTerminalWatchModeList.hpp"
#include "SymbolNonTerminalFormat.hpp"
#include "SymbolNonTerminalVariable.hpp"
#include "SymbolTerminalRegisterBC.hpp"
#include "SymbolNonTerminalUnwatchCommand.hpp"
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
#include "SymbolNonTerminalContinueCommand.hpp"
#include "SymbolNonTerminalRunCommand.hpp"
#include "SymbolNonTerminalSetCommand.hpp"
#include "SymbolNonTerminalHelpCommand.hpp"
#include "SymbolNonTerminalStartCommand.hpp"
#include "SymbolNonTerminalTemporaryBreakpointCommand.hpp"
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
#include "SymbolTerminalTimaOffset.hpp"
#include "SymbolTerminalDivOffset.hpp"
#include "SymbolTerminalAssign.hpp"
#include "SymbolTerminalLesser.hpp"
#include "SymbolTerminalGreater.hpp"
#include "SymbolTerminalInfo.hpp"
#include "SymbolTerminalRun.hpp"
#include "SymbolTerminalContinue.hpp"
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
#include "SymbolTerminalStart.hpp"
#include "SymbolTerminalTemporaryBreakpoint.hpp"

#include "SymbolTerminalInterruptTimer.hpp"
#include "SymbolTerminalHalfWordFormat.hpp"
#include "SymbolTerminalWordFormat.hpp"

#include "SymbolTerminalRegisterA.hpp"
#include "SymbolTerminalUnwatch.hpp"
#include "SymbolTerminalRegisterC.hpp"
#include "SymbolTerminalRegisterB.hpp"
#include "SymbolTerminalRegisterE.hpp"
#include "SymbolTerminalRegisterD.hpp"
#include "SymbolTerminalRegisterF.hpp"
#include "SymbolTerminalInstruction.hpp"
#include "SymbolTerminalRegisterH.hpp"
#include "SymbolTerminalDecimal.hpp"
#include "SymbolTerminalStackPointer.hpp"
#include "SymbolTerminalRegisterL.hpp"
#include "SymbolTerminalOctal.hpp"
#include "SymbolTerminalReadMode.hpp"
#include "SymbolTerminalWriteMode.hpp"
#include "SymbolTerminalHexadecimal.hpp"
#include "SymbolTerminalBinary.hpp"

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
