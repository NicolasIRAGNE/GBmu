/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerContext.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/10 19:05:16 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERCONTEXT_HPP
# define DEBUGGERCONTEXT_HPP

#include "cpu.h"
#include <iostream>

class DebuggerContext
{
	public:

		typedef enum	e_debugger_unit
		{
			E_DEBUGGER_UNIT_WORD,
			E_DEBUGGER_UNIT_HALFWORD,
		}				t_debugger_unit;

		typedef enum	e_debugger_format
		{
			E_DEBUGGER_FORMAT_BINARY = 2,
			E_DEBUGGER_FORMAT_OCTAL = 8,
			E_DEBUGGER_FORMAT_DECIMAL = 10,
			E_DEBUGGER_FORMAT_HEXADECIMAL = 16,
			E_DEBUGGER_FORMAT_INSTRUCTION
		}				t_debugger_format;

		DebuggerContext(void);
		DebuggerContext(struct gb_cpu_s *cpu);
		DebuggerContext(DebuggerContext const &instance);
		DebuggerContext & operator=(DebuggerContext const &rhs);
		~DebuggerContext(void);

		static std::string getUnitString(t_debugger_unit unit);
		static char getFormatChar(t_debugger_format format);

		struct gb_cpu_s *cpu;
		t_debugger_format format;
};
#endif
