/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractBreakpoint.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:10:18 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/30 00:45:08 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTBREAKPOINT_HPP
# define ABSTRACTBREAKPOINT_HPP

# include <iostream>
# include "AbstractCommand.hpp"
# include "Debugger.hpp"

class AbstractBreakpoint : public AbstractCommand
{
	public:
		AbstractBreakpoint(std::string name, std::string const type);
		AbstractBreakpoint &operator=(AbstractBreakpoint const &rhs);
		AbstractBreakpoint(AbstractBreakpoint const &rhs);
		~AbstractBreakpoint(void);

		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual int addBreakpointToDebugger(Debugger *debugger, uint16_t address) const = 0;
		AbstractBreakpoint(void);
	
	private:
		std::string const _type;

};

#endif