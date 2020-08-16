/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debugger.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:58:49 by ldedier           #+#    #+#             */
/*   Updated: 2020/08/15 14:58:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debugger.hpp"
#include "DebuggerVariableAddress.hpp"
#include "DebuggerVariableValue.hpp"
#include "DebuggerVariableConstValue.hpp"
#include "getValue.hpp"

#include "Commands/SetCommand.hpp"
#include "Print.hpp"
#include "XCommand.hpp"
#include "StandardBreakpoint.hpp"
#include "TemporaryBreakpoint.hpp"
#include "Quit.hpp"
#include "Info.hpp"
#include "Watch.hpp"
#include "Continue.hpp"
#include "Start.hpp"
#include "Help.hpp"
#include "Run.hpp"
#include "Registers.hpp"
#include "Delete.hpp"
#include "Next.hpp"
#include "Step.hpp"
#include "Start.hpp"
#include "Verbose.hpp"

Debugger::Debugger(void) : _verbose(DEFAULT_VERBOSE)
{
	
}

Debugger::Debugger(struct gb_cpu_s *cpu) : _cpu(cpu), _verbose(DEFAULT_VERBOSE), _counter(0), _lastCommand("")
{
	_variables["af"] = new DebuggerVariableAddress(&cpu->reg.af);
	_variables["a"] = new DebuggerVariableAddress(&cpu->reg.a);
	_variables["f"] = new DebuggerVariableAddress(&cpu->reg.f);
	_variables["bc"] = new DebuggerVariableAddress(&cpu->reg.bc);
	_variables["b"] = new DebuggerVariableAddress(&cpu->reg.b);
	_variables["c"] = new DebuggerVariableAddress(&cpu->reg.c);
	_variables["de"] = new DebuggerVariableAddress(&cpu->reg.de);
	_variables["d"] = new DebuggerVariableAddress(&cpu->reg.d);
	_variables["e"] = new DebuggerVariableAddress(&cpu->reg.e);
	_variables["hl"] = new DebuggerVariableAddress(&cpu->reg.hl);
	_variables["h"] = new DebuggerVariableAddress(&cpu->reg.h);
	_variables["l"] = new DebuggerVariableAddress(&cpu->reg.l);
	_variables["sp"] = new DebuggerVariableAddress(&cpu->reg.sp);
	_variables["pc"] = new DebuggerVariableAddress(&cpu->reg.pc);

	_variables["IO_OFFSET"] = new DebuggerVariableConstValue(IO_OFFSET);
	_variables["JOYP_OFFSET"] = new DebuggerVariableConstValue(JOYP_OFFSET);
	_variables["DIV_OFFSET"] = new DebuggerVariableConstValue(DIV_OFFSET);
	_variables["TIMA_OFFSET"] = new DebuggerVariableConstValue(TIMA_OFFSET);
	_variables["TMA_OFFSET"] = new DebuggerVariableConstValue(TMA_OFFSET);
	_variables["TAC_OFFSET"] = new DebuggerVariableConstValue(TAC_OFFSET);
	_variables["LCDC_OFFSET"] = new DebuggerVariableConstValue(LCDC_OFFSET);
	_variables["STAT_OFFSET"] = new DebuggerVariableConstValue(STAT_OFFSET);
	_variables["SCY_OFFSET"] = new DebuggerVariableConstValue(SCY_OFFSET);
	_variables["SCX_OFFSET"] = new DebuggerVariableConstValue(SCX_OFFSET);
	_variables["LY_OFFSET"] = new DebuggerVariableConstValue(LY_OFFSET);
	_variables["LYC_OFFSET"] = new DebuggerVariableConstValue(LYC_OFFSET);
	_variables["DMA_OFFSET"] = new DebuggerVariableConstValue(DMA_OFFSET);
	_variables["BGP_OFFSET"] = new DebuggerVariableConstValue(BGP_OFFSET);
	_variables["OBP0_OFFSET"] = new DebuggerVariableConstValue(OBP0_OFFSET);
	_variables["OBP1_OFFSET"] = new DebuggerVariableConstValue(OBP1_OFFSET);
	_variables["WY_OFFSET"] = new DebuggerVariableConstValue(WY_OFFSET);
	_variables["WX_OFFSET"] = new DebuggerVariableConstValue(WX_OFFSET);
	_variables["IF_OFFSET"] = new DebuggerVariableConstValue(IF_OFFSET);
	_variables["BGMAP1_OFFSET"] = new DebuggerVariableConstValue(BGMAP1_OFFSET);
	_variables["BGMAP2_OFFSET"] = new DebuggerVariableConstValue(BGMAP2_OFFSET);
	_variables["BGMAP_SIZE"] = new DebuggerVariableConstValue(BGMAP_SIZE);

	_variables["INT_VBLANK_REQUEST"] = new DebuggerVariableConstValue(INT_VBLANK_REQUEST);
	_variables["INT_STAT_REQUEST"] = new DebuggerVariableConstValue(INT_STAT_REQUEST);
	_variables["INT_TIMER_REQUEST"] = new DebuggerVariableConstValue(INT_TIMER_REQUEST);
	_variables["INT_SERIAL_REQUEST"] = new DebuggerVariableConstValue(INT_SERIAL_REQUEST);
	_variables["INT_JOYPAD_REQUEST"] = new DebuggerVariableConstValue(INT_JOYPAD_REQUEST);
	_variables["INT_VBLANK_ADDR"] = new DebuggerVariableConstValue(INT_VBLANK_ADDR);
	_variables["INT_STAT_ADDR"] = new DebuggerVariableConstValue(INT_STAT_ADDR);
	_variables["INT_TIMER_ADDR"] = new DebuggerVariableConstValue(INT_TIMER_ADDR);

	_commands[BREAKPOINT_COMMAND] = new StandardBreakpoint();
	_commands[TBREAKPOINT_COMMAND] = new TemporaryBreakpoint();
	_commands[DELETE_COMMAND] = new Delete();
	_commands[HELP_COMMAND] = new Help();
	_commands[CONTINUE_COMMAND] = new Continue();
	_commands[INFO_COMMAND] = new Info();
	_commands[NEXT_COMMAND] = new Next();
	_commands[PRINT_COMMAND] = new Print();
	_commands[QUIT_COMMAND] = new Quit();
	_commands[REGISTERS_COMMAND] = new Registers();
	_commands[SET_COMMAND] = new SetCommand();
	_commands[STEP_COMMAND] = new Step();
	_commands[START_COMMAND] = new Start();
	_commands[RUN_COMMAND] = new Run();
	_commands[VERBOSE_COMMAND] = new Verbose();
	_commands[WATCH_COMMAND] = new Watch();
	_commands[X_COMMAND] = new XCommand();

}

Debugger::Debugger(Debugger const &instance)
{
	*this = instance;
}

Debugger::~Debugger(void)
{
	typename std::map<std::string, AbstractCommand *>::iterator it;
	typename std::map<std::string, DebuggerVariable *>::iterator it2;

	it = _commands.begin();
	while (it != _commands.end())
	{
		delete it->second;
		it++;
	}
	it2 = _variables.begin();
	while (it2 != _variables.end())
	{
		delete it2->second;
		it2++;
	}
}

Debugger &	Debugger::operator=(Debugger const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

int Debugger::getVerbose(void)
{
	return _verbose;
}

int Debugger::setVerbose(int verbose)
{
	_verbose = verbose;
	std::cout << "Verbosity level set to " << _verbose << std::endl;
	return 0;
}


struct gb_cpu_s *Debugger::getCPU(void)
{
	return _cpu;
}

DebuggerVariable *Debugger::getVariable(std::string name)
{
	DebuggerVariable *ptr;

	if (!getValue(_variables, name, &ptr))
	{
		ptr = new DebuggerVariableValue();
		_variables[name] = ptr;
	}
	return ptr;
}

DebuggerVariableConstValue &Debugger::getHistoryVariable(int nb)
{
	return _history.getVariable(nb);
}

uint32_t Debugger::getHistoryCounter(void)
{
	return _history.getCounter();
}

void	Debugger::addValue(int value)
{
	DebuggerVariableConstValue val(value);
	_history.addValue(val);
}

std::string	Debugger::getLastCommand(void)
{
	return (this->_lastCommand);
}

void	Debugger::setLastCommand(std::string string)
{
	this->_lastCommand = string;
}

bool	Debugger::deleteValue(uint32_t value)
{
	if ((this->_breakpoints).deleteValue(value))
		return (true);
	if ((this->_temporaryBreakpoints).deleteValue(value))
		return (true);
	if (this->_watchpoints[Debugger::E_WATCHPOINTS_WRITE].deleteValue(value))
		return (true);
	if (this->_watchpoints[Debugger::E_WATCHPOINTS_READ].deleteValue(value))
		return (true);
	return (false);
}

void Debugger::removeAllBreakpoints(void)
{
	this->_breakpoints.clear();
	this->_temporaryBreakpoints.clear();
	this->_watchpoints[Debugger::E_WATCHPOINTS_WRITE].clear();
	this->_watchpoints[Debugger::E_WATCHPOINTS_READ].clear();
}

void	Debugger::addBreakpointValuesList(DebuggerAddress key)
{
	(this->_breakpoints).addValue(key, ++_counter);
}

void	Debugger::addTemporaryBreakpointValuesList(DebuggerAddress key)
{
	(this->_temporaryBreakpoints).addValue(key, ++_counter);
}

void	Debugger::addWatchpointValuesList(WatchPoint watchPoint, e_watchpoint_mode_id id)
{
	(this->_watchpoints[id]).addValue(watchPoint, ++_counter);
}

bool	Debugger::getWatchpointValuesList(WatchPoint watchPoint, std::list<uint32_t> *list, e_watchpoint_mode_id id)
{
	return ((this->_watchpoints[id]).getLists(watchPoint, list));
}

int Debugger::executeCommand(std::string const commandName, 
			ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context)
{
	return _commands[commandName]->execute(ast, context);
}

bool comparator(uint32_t val1, uint32_t val2)
{
	return val1 < val2;
}

bool	Debugger::getBreakpointValuesList(DebuggerAddress key, std::list<uint32_t> *list, uint32_t *id, bool *temp)
{
	bool found = false;
	std::list<uint32_t> *bplist = nullptr;
	std::list<uint32_t> *tempbplist = nullptr;
	std::list<uint32_t> tempbplistcopy;
	
	found |= (this->_temporaryBreakpoints).getLists(key, &tempbplist);
	if (found && list == nullptr)
	{
		*id = tempbplist->front();
		(this->_temporaryBreakpoints).deleteValue(*id);
		*temp = true;
		return found;
	}
	found |= (this->_breakpoints).getLists(key, &bplist);
	if (found && list == nullptr)
	{
		*id = bplist->front();
		*temp = false;
		return found;
	}
	if (found)
	{
		if (bplist && !tempbplist)
			*list = *bplist;
		else if (!bplist && tempbplist)
			*list = *tempbplist;
		else
		{
			*list = *bplist;
			tempbplistcopy = *tempbplist;
			list->merge(tempbplistcopy, comparator);
		}
	}
	return found;
}

bool Debugger::hasWatchPoints(Debugger::e_watchpoint_mode_id id)
{
	return !this->_watchpoints[id].isEmpty();
}

uint32_t Debugger::getCounter(void)
{
	return _counter;
}

void Debugger::showRegisters(void)
{
	std::cout << "Registers:" << std::endl << std::endl;

	std::cout << "f:	" << +_cpu->reg.f << std::endl;
	std::cout << "a:	" << +_cpu->reg.a << std::endl;
	std::cout << "af:	" << _cpu->reg.af << std::endl;

	std::cout << "c:	" << +_cpu->reg.c << std::endl;
	std::cout << "b:	" << +_cpu->reg.b << std::endl;
	std::cout << "bc:	" << _cpu->reg.bc << std::endl;

	std::cout << "e:	" << +_cpu->reg.e << std::endl;
	std::cout << "d:	" << +_cpu->reg.d << std::endl;
	std::cout << "de:	" << _cpu->reg.de << std::endl;

	std::cout << "l:	" << +_cpu->reg.l << std::endl;
	std::cout << "h:	" << +_cpu->reg.h << std::endl;
	std::cout << "hl:	" << _cpu->reg.hl << std::endl;

	std::cout << "sp:	" << _cpu->reg.sp << std::endl;
	std::cout << "pc:	" << _cpu->reg.pc << std::endl;
}

void Debugger::showInfo(void)
{
	std::cout << "Verbosity level:" << _verbose << std::endl << std::endl;
	showRegisters();
}

std::string getPadding(std::string prefix)
{
	return std::string(std::max(static_cast<int>(2 - (prefix.size() / 8)), 1), '\t');
}

void Debugger::showHelp(void)
{
	typename std::map<std::string, AbstractCommand *>::iterator it;
	std::cout << "Available commands:" << std::endl << std::endl;
	it = _commands.begin();
	while (it != _commands.end())
	{
		std::cout << it->first << getPadding(it->first) << ": " << it->second->getShortHelp() << std::endl;
		it++;
	}
}

void Debugger::showHelpCommand(std::string commandName)
{
	std::cout << "usage:\t" << _commands[commandName]->getHelp() << std::endl;
}

