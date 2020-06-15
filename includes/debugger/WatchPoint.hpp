/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WatchPoint.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 17:55:53 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 15:21:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATCHPOINT_HPP
# define WATCHPOINT_HPP

# include <iostream>
# include "DebuggerAddress.hpp"

class WatchPoint
{
	public:
	
		struct u_watchPointUnion
		{
			DebuggerAddress		address;
			void				*ptr;
		};

		enum e_watchPointEnum
		{
			E_WATCHPOINT_ADDRESS,
			E_WATCHPOINT_POINTER_8,
			E_WATCHPOINT_POINTER_16
		};

		WatchPoint(uint8_t *ptr);
		WatchPoint(uint16_t *ptr);
		WatchPoint(DebuggerAddress address);
		WatchPoint(WatchPoint const &instance);
		WatchPoint &operator=(WatchPoint const &rhs);
		~WatchPoint(void);

		bool operator<(const WatchPoint & WatchPoint) const;


	private:
		WatchPoint(void);
		struct u_watchPointUnion	_un;
		enum e_watchPointEnum		_en;
};

#endif