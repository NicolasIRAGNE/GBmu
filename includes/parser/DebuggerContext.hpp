/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerContext.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/30 19:40:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERCONTEXT_HPP
# define DEBUGGERCONTEXT_HPP

#include "cpu.h"

class DebuggerContext
{
	public:

		typedef enum	e_debugger_format
		{
			E_DEBUGGER_FORMAT_DEFAULT = -1,
			E_DEBUGGER_FORMAT_BINARY = 2,
			E_DEBUGGER_FORMAT_OCTAL = 8,
			E_DEBUGGER_FORMAT_DECIMAL = 10,
			E_DEBUGGER_FORMAT_HEXADECIMAL = 16,
		}				t_debugger_format;

		DebuggerContext(void);
		DebuggerContext(DebuggerContext const &instance);
		DebuggerContext & operator=(DebuggerContext const &rhs);
		~DebuggerContext(void);
	
		struct gb_cpu_s cpu;
		t_debugger_format format;
};
#endif
