/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debugger.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:56:33 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 18:56:07 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGER_HPP
# define DEBUGGER_HPP

# include <iostream>
# include <map>
# include "DebuggerVariable.hpp"
# include "MapOfListNoRepetitions.hpp"
# include "History.hpp"
# include "DebuggerAddress.hpp"
# include "WatchPoint.hpp"
# include "Commands/AbstractCommand.hpp"

extern "C" {
# include "gb.h"
}

class Debugger
{
	public:
		Debugger(struct gb_cpu_s *cpu);
		Debugger(Debugger const &instance);
		Debugger &operator=(Debugger const &rhs);
		~Debugger(void);

		int getVerbose();
		struct gb_cpu_s *getCPU(void);
		DebuggerVariable *getVariable(std::string);
		DebuggerVariableConstValue &getHistoryVariable(int nb);
		uint32_t getHistoryCounter(void);
		uint32_t getCounter(void);

		void	addValue(int value);

		std::string getLastCommand(void);
		void		setLastCommand(std::string string);

		
		enum e_watchpoint_mode_id
		{
			E_WATCHPOINTS_READ,
			E_WATCHPOINTS_WRITE,
			E_NB_WATCHPOINT_MODES
		};

		bool getBreakpointValuesList(DebuggerAddress key, std::list<uint32_t> *list);
		void addBreakpointValuesList(DebuggerAddress key);

		bool getWatchpointValuesList(WatchPoint key, std::list<uint32_t> *list, e_watchpoint_mode_id id);
		void addWatchpointValuesList(WatchPoint key, e_watchpoint_mode_id id);
		bool hasWatchPoints(e_watchpoint_mode_id id);

		bool deleteValue(uint32_t value);
		void removeAllBreakpoints(void);

		void showRegisters(void);
		void showInfo(void);
		void showHelp(void);
		void showHelpCommand(std::string commandName);

	private:
		Debugger(void);

		struct gb_cpu_s											*_cpu;
		int														_verbose;
		History													_history;
		uint32_t												_counter;
		MapOfListNoRepetitions<DebuggerAddress, uint32_t>		_breakpoints;
		MapOfListNoRepetitions<WatchPoint, uint32_t>			_watchpoints[E_NB_WATCHPOINT_MODES];
		std::string												_lastCommand;
		
		std::map<std::string, DebuggerVariable *>				_variables;
		std::map<std::string, AbstractCommand *>				_commands;

};

#endif