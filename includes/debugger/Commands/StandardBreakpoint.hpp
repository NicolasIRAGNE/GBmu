/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StandardBreakpoint.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:18:41 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/30 00:37:47 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STANDARDBREAKPOINT_HPP
# define STANDARDBREAKPOINT_HPP

# include <iostream>
# include "AbstractCommand.hpp"
# include "AbstractBreakpoint.hpp"

class StandardBreakpoint : public AbstractBreakpoint
{
	public:
		StandardBreakpoint(void);
		StandardBreakpoint(StandardBreakpoint const &instance);
		StandardBreakpoint &operator=(StandardBreakpoint const &rhs);
		virtual ~StandardBreakpoint(void);
		virtual int addBreakpointToDebugger(Debugger *debugger, uint16_t address) const;

	private:

};

#endif