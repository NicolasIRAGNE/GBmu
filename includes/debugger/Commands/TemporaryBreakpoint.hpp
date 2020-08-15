/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemporaryBreakpoint.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:05:13 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/30 00:48:35 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPORARYBREAKPOINT_HPP
# define TEMPORARYBREAKPOINT_HPP

# include <iostream>
# include "AbstractBreakpoint.hpp"

class TemporaryBreakpoint : public AbstractBreakpoint
{
	public:
		TemporaryBreakpoint(void);
		TemporaryBreakpoint(TemporaryBreakpoint const &instance);
		TemporaryBreakpoint &operator=(TemporaryBreakpoint const &rhs);
		~TemporaryBreakpoint(void);
		virtual int addBreakpointToDebugger(Debugger *debugger, uint16_t address) const;

	private:

};

#endif