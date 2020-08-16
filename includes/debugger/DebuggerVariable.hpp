/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerVariable.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:00:08 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/29 16:38:11 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERVARIABLE_HPP
# define DEBUGGERVARIABLE_HPP

# include <iostream>

class DebuggerVariable
{
	public:

		DebuggerVariable();
		DebuggerVariable(DebuggerVariable const &instance);
		DebuggerVariable &operator=(DebuggerVariable const &rhs);
		virtual ~DebuggerVariable(void);

		virtual int getValue() = 0;
		virtual void setValue(int value) = 0;

};
#endif