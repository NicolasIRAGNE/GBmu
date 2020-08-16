/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Watch.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:15:39 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:43:32 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATCH_HPP
# define WATCH_HPP

# include <iostream>
# include "AbstractCommand.hpp"
# include "Debugger.hpp"

class Watch : public AbstractCommand
{
	public:
		Watch(void);
		Watch(Watch const &instance);
		Watch &operator=(Watch const &rhs);
		virtual ~Watch(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:
		static void addWatchPoint(Debugger *debugger, const std::string & mode
	, WatchPoint &watchPoint, Debugger::e_watchpoint_mode_id id);
};

std::ostream &operator<<(std::ostream &o, Watch const &instance);
#endif