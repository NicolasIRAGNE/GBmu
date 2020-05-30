/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debugger.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:56:33 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/30 17:37:45 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGER_HPP
# define DEBUGGER_HPP

# include <iostream>
# include <map>
# include "DebuggerVariable.hpp"
# include "History.hpp"

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
		void	addValue(int value);

		std::string getLastCommand(void);
		void		setLastCommand(std::string string);

	private:
		Debugger(void);
		struct gb_cpu_s								*_cpu;
		int											_verbose;
		History										_history;
		std::map<std::string, DebuggerVariable *>	_variables;
		std::map<uint32_t, bool>					_breakpoints;
		std::map<uint32_t, bool> 					_watchPointsRead;
		std::map<uint32_t, bool>					_breakpointsWrite;
		std::string									_lastCommand;
};

#endif