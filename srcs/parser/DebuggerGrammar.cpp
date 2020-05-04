/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerGrammar.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:03:31 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 19:07:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DebuggerGrammar.hpp"
#include "DebuggerContext.hpp"

DebuggerGrammar::DebuggerGrammar(void) : AbstractGrammar(new SymbolNonTerminalCommand(), true)
{
	addNonTerminal(new SymbolNonTerminalPrintCommand());
	addNonTerminal(new SymbolNonTerminalWatchMode());
	addNonTerminal(new SymbolNonTerminalQuitCommand());
	addNonTerminal(new SymbolNonTerminalVerboseCommand());
	addNonTerminal(new SymbolNonTerminalRegistersCommand());
	addNonTerminal(new SymbolNonTerminalRegisterName());
	addNonTerminal(new SymbolNonTerminalUnit());
	addNonTerminal(new SymbolNonTerminalIntegerList());
	addNonTerminal(new SymbolNonTerminalIoPort());
	addNonTerminal(new SymbolNonTerminalCommandName());
	addNonTerminal(new SymbolNonTerminalUnwatchCommand());
	addNonTerminal(new SymbolNonTerminalComparison());
	addNonTerminal(new SymbolNonTerminalFactor());
	addNonTerminal(new SymbolNonTerminalWatchModeList());
	addNonTerminal(new SymbolNonTerminalStepCommand());
	addNonTerminal(new SymbolNonTerminalFormat());
	addNonTerminal(new SymbolNonTerminalInfoCommand());
	addNonTerminal(new SymbolNonTerminalNextCommand());
	addNonTerminal(new SymbolNonTerminalXCommand());
	addNonTerminal(new SymbolNonTerminalVariable());
	addNonTerminal(new SymbolNonTerminalSetCommand());
	addNonTerminal(new SymbolNonTerminalHelpCommand());
	addNonTerminal(new SymbolNonTerminalAssignable());
	addNonTerminal(new SymbolNonTerminalTerm());
	addNonTerminal(new SymbolNonTerminalWatchCommand());
	addNonTerminal(new SymbolNonTerminalAndOr());
	addNonTerminal(new SymbolNonTerminalExpr());
	addNonTerminal(new SymbolNonTerminalValue());
	addNonTerminal(new SymbolNonTerminalVector());
	addNonTerminal(new SymbolNonTerminalDeleteCommand());
	addNonTerminal(new SymbolNonTerminalBreakpointCommand());
	addNonTerminal(new SymbolNonTerminalPrintCommandSuffix());

	addTerminal(new SymbolTerminalInterruptStat());
	addTerminal(new SymbolTerminalSet());
	addTerminal(new SymbolTerminalGreaterOrEqual());
	addTerminal(new SymbolTerminalRightShift());
	addTerminal(new SymbolTerminalRegisterAF());
	addTerminal(new SymbolTerminalOr());
	addTerminal(new SymbolTerminalLesserOrEqual());
	addTerminal(new SymbolTerminalInterruptVBlank());
	addTerminal(new SymbolTerminalRegisters());
	addTerminal(new SymbolTerminalRegisterHL());
	addTerminal(new SymbolTerminalExpansion());
	addTerminal(new SymbolTerminalNotEqual());
	addTerminal(new SymbolTerminalHelp());
	addTerminal(new SymbolTerminalQuit());
	addTerminal(new SymbolTerminalModulo());
	addTerminal(new SymbolTerminalBinaryAnd());
	addTerminal(new SymbolTerminalClosedParenthesis());
	addTerminal(new SymbolTerminalOpenParenthesis());
	addTerminal(new SymbolTerminalPlus());
	addTerminal(new SymbolTerminalMultiply());
	addTerminal(new SymbolTerminalMinus());
	addTerminal(new SymbolTerminalDivide());
	addTerminal(new SymbolTerminalNext());
	addTerminal(new SymbolTerminalProgramCounter());
	addTerminal(new SymbolTerminalPrint());
	addTerminal(new SymbolTerminalInteger());
	addTerminal(new SymbolTerminalDivOffset());
	addTerminal(new SymbolTerminalAssign());
	addTerminal(new SymbolTerminalLesser());
	addTerminal(new SymbolTerminalGreater());
	addTerminal(new SymbolTerminalInfo());
	addTerminal(new SymbolTerminalRegisterBC());
	addTerminal(new SymbolTerminalEqual());
	addTerminal(new SymbolTerminalInterruptJoypad());
	addTerminal(new SymbolTerminalRegisterDE());
	addTerminal(new SymbolTerminalWatch());
	addTerminal(new SymbolTerminalInterruptTimer());
	addTerminal(new SymbolTerminalHalfWordFormat());
	addTerminal(new SymbolTerminalWordFormat());
	addTerminal(new SymbolTerminalTodoOffset());
	addTerminal(new SymbolTerminalTimaOffset());
	addTerminal(new SymbolTerminalAnd());
	addTerminal(new SymbolTerminalBreakpoint());
	addTerminal(new SymbolTerminalStep());
	addTerminal(new SymbolTerminalVerbose());
	addTerminal(new SymbolTerminalInterruptSerial());
	addTerminal(new SymbolTerminalLeftShift());
	addTerminal(new SymbolTerminalRegisterA());
	addTerminal(new SymbolTerminalUnwatch());
	addTerminal(new SymbolTerminalRegisterC());
	addTerminal(new SymbolTerminalRegisterB());
	addTerminal(new SymbolTerminalRegisterE());
	addTerminal(new SymbolTerminalRegisterD());
	addTerminal(new SymbolTerminalRegisterF());
	addTerminal(new SymbolTerminalInstruction());
	addTerminal(new SymbolTerminalRegisterH());
	addTerminal(new SymbolTerminalDecimal());
	addTerminal(new SymbolTerminalStackPointer());
	addTerminal(new SymbolTerminalRegisterL());
	addTerminal(new SymbolTerminalOctal());
	addTerminal(new SymbolTerminalReadMode());
	addTerminal(new SymbolTerminalWriteMode());
	addTerminal(new SymbolTerminalHexadecimal());
	addTerminal(new SymbolTerminalBinaryOr());
	addTerminal(new SymbolTerminalBinary());
	addTerminal(new SymbolTerminalDelete());
	addTerminal(new SymbolTerminalX());
	addTerminal(new SymbolTerminalPrintCommandParams());

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

bool DebuggerGrammar::treatTerminalEligibility(std::string current
	, AbstractTerminal<int, DebuggerContext &> **terminal
	, std::deque<Token<int, DebuggerContext &> *>tokens
	, bool & ambiguous
	, int & staysEligiblePos
	, int & isEligiblePos
)
{
	typename std::vector<AbstractTerminal<int, DebuggerContext &> *>::iterator it = _tokens.begin();
	bool res = false;
	SymbolTerminalCommand * commandTerminal;

	if (tokens.size() == 0)
	{
		while (it != _tokens.end())
		{
			if ((commandTerminal = dynamic_cast<SymbolTerminalCommand *>(*it)))
			{
				if (commandTerminal->canBeAdded(tokens))
				{
					if (commandTerminal->isEligibleForCurrent(current))
					{
						isEligiblePos = staysEligiblePos + 1;
						if (terminal)
							ambiguous = true;
						*terminal = *it;
						res = true;
					}
				}
			}
			it++;
		}
	}
	else
	{
		while (it != _tokens.end())
		{
			if (!(commandTerminal = dynamic_cast<SymbolTerminalCommand *>(*it)))
			{
				if ((*it)->canBeAdded(tokens))
				{
					if ((*it)->staysEligibleForCurrent(current))
						res = true;
					if ((*it)->isEligibleForCurrent(current))
					{
						isEligiblePos = staysEligiblePos + 1;
						if (!(*terminal) || !(*terminal)->isEligibleForCurrent(current) || (*terminal)->getPriority() < (*it)->getPriority())
							*terminal = *it;
					}
				}
			}
			it++;
		}
	}
	return res;
}

std::deque<Token<int, DebuggerContext &> *> DebuggerGrammar::innerLex(bool stopAtNewline, std::istream & istream)
{
	std::deque<Token<int, DebuggerContext &> *>	res;
	int							staysEligiblePos;
	int							isEligiblePos;
	std::string					current;
	AbstractTerminal<int, DebuggerContext &>	*terminal;
	Token <int, DebuggerContext &>				*token;
	char						c;
	bool 						ambiguous;

	while (!istream.eof())
	{
		current.clear();
		terminal = nullptr;
		staysEligiblePos = 0;
		isEligiblePos = 0;
		ambiguous = false;
		while (!istream.eof())
		{
			if ((c = istream.peek()) != EOF && (c != '\n' || !stopAtNewline))
			{
				current += c;
				if (!treatTerminalEligibility(current, &terminal, res, ambiguous, staysEligiblePos, isEligiblePos))
				{
					if (terminal)
					{
						if (terminal->shouldCreateToken(current.substr(0, isEligiblePos), c, res))
						{
							token = terminal->createToken(current.substr(0, isEligiblePos));
							res.push_back(token);
							break;
						}
						else
						{
							deleteTokens(res);
							throw AbstractGrammar<int, DebuggerContext &>::LexicalErrorException(current);
						}
					}
					else if (isblank(c) && _blankAsDelimiters)
					{
						istream.get();
						break;
					}
					else
					{
						deleteTokens(res);
						throw AbstractGrammar<int, DebuggerContext &>::LexicalErrorException(current);
					}
				}
				else
				{
					staysEligiblePos++;
					istream.get();
				}
			}
			else
			{
				if (terminal)
				{
 					token = terminal->createToken(current.substr(0, isEligiblePos));
					res.push_back(token);
					if (current.substr(isEligiblePos) != "")
					{
						deleteTokens(res);
					 	throw AbstractGrammar<int, DebuggerContext &>::LexicalErrorException(current);
					}
				}
				else if (current != "")
				{
					deleteTokens(res);
					throw AbstractGrammar<int, DebuggerContext &>::LexicalErrorException(current);
				}
				return res;
			}
		}
	}
	return (res);
}
