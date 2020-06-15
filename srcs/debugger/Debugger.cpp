/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debugger.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:58:49 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 15:32:40 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debugger.hpp"
#include "DebuggerVariableAddress.hpp"
#include "DebuggerVariableValue.hpp"
#include "DebuggerVariableConstValue.hpp"
#include "getValue.hpp"

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
}

Debugger::Debugger(Debugger const &instance)
{
	*this = instance;
}

Debugger::~Debugger(void)
{

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

void	Debugger::deleteValue(uint32_t value)
{
	static_cast<void>(value);
	// (this->_maps[id]).removeValue(value);
}

void	Debugger::addBreakpointValuesList(DebuggerAddress key)
{
	(this->_breakpoints).addValue(key, ++_counter);
}

void	Debugger::addWatchpointValuesList(WatchPoint watchPoint, e_watchpoint_mode_id id)
{
	(this->_watchpoints[id]).addValue(watchPoint, ++_counter);
}

bool	Debugger::getWatchpointValuesList(WatchPoint watchPoint, std::list<uint32_t> *list, e_watchpoint_mode_id id)
{
	return ((this->_watchpoints[id]).getLists(watchPoint, list));
}

bool	Debugger::getBreakpointValuesList(DebuggerAddress key, std::list<uint32_t> *list)
{
	return ((this->_breakpoints).getLists(key, list));
}

uint32_t Debugger::getCounter(void)
{
	return _counter;
}
