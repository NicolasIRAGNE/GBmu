/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenWatchModes.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:38:33 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 17:46:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenWatchModes.hpp"

TokenWatchModes::TokenWatchModes(void)
{
	
}

TokenWatchModes::~TokenWatchModes(void)
{
	
}

TokenWatchModes::TokenWatchModes(AbstractTerminal<int, DebuggerContext &> &term
	, std::string content
	, WatchModes modes) : Token(term, content), _modes(modes)
{

}

WatchModes TokenWatchModes::getModes(void)
{
	return _modes;
}

std::ostream &	TokenWatchModes::repr(std::ostream &o)
{
	o << YACC_YELLOW << " (";
	if (_modes & WATCH_MODE_READ)
	{
		o << YACC_GREEN << "READ" << YACC_YELLOW;
	}
	if (_modes & WATCH_MODE_WRITE)
	{
		if (_modes & WATCH_MODE_READ)
			o << " ; ";
		o << YACC_GREEN << "WRITE" << YACC_YELLOW;
	}
	o << ") " << YACC_EOC;
	return o;
}