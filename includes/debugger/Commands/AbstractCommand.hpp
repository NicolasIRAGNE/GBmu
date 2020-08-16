/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractCommand.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:07:07 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/30 01:07:39 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include "ASTNode.hpp"
# include "AbstractSymbol.hpp"

# define BREAKPOINT_COMMAND		"break"
# define TBREAKPOINT_COMMAND	"tbreak"
# define DELETE_COMMAND			"delete"
# define HELP_COMMAND			"help"
# define INFO_COMMAND			"info"
# define NEXT_COMMAND			"next"
# define PRINT_COMMAND			"print"
# define QUIT_COMMAND			"quit"
# define REGISTERS_COMMAND		"registers"
# define SET_COMMAND			"set"
# define STEP_COMMAND			"step"
# define VERBOSE_COMMAND		"verbose"
# define WATCH_COMMAND			"watch"
# define X_COMMAND				"x"
# define RUN_COMMAND			"run"
# define START_COMMAND			"start"
# define CONTINUE_COMMAND		"continue"

class DebuggerContext;

class AbstractCommand
{
	public:
		AbstractCommand(void);
		AbstractCommand(std::string name);
		AbstractCommand(AbstractCommand const &instance);
		AbstractCommand &operator=(AbstractCommand const &rhs);
		virtual ~AbstractCommand(void);

		virtual std::string getHelp(void) = 0;
		virtual std::string getShortHelp(void) = 0;
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const = 0;

	protected:
		std::string _name;
};

#endif