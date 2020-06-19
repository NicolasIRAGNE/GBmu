/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Watch.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:15:25 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 18:24:42 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Watch.hpp"

Watch::Watch(void) : AbstractCommand(WATCH_COMMAND)
{
	
}

Watch::Watch(Watch const &instance)
{
	*this = instance;
}

Watch::~Watch(void)
{
	
}

Watch &	Watch::operator=(Watch const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Watch::getHelp(void)
{
	return (_name + " $register " +  "\t# add a write watchpoint to the given register"\
		"\n\t" + _name + " r $register \t# add a read watchpoint the given register"\
		"\n\t" + _name + " rw * offset\t# add a write/read watchpoint to offset \"offset\""\
		"\n\t" + _name + " [w] * offset\t# add a write watchpoint to offset \"offset\""\
		"\n\t" + _name + " r * offset\t# add a read watchpoint to offset \"offset\"");
}

std::string	Watch::getShortHelp(void)
{
	return ("add a watchpoint to some registers or cpu address");
}