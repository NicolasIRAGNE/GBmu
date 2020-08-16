/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerVariableValue.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:01:52 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/29 16:43:46 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERVARIABLEVALUE_HPP
# define DEBUGGERVARIABLEVALUE_HPP

# include <iostream>
# include "DebuggerVariable.hpp"

class DebuggerVariableValue : public DebuggerVariable
{
	public:
	
		DebuggerVariableValue(void);
		DebuggerVariableValue(int value);
		DebuggerVariableValue(DebuggerVariableValue const &instance);
		DebuggerVariableValue &operator=(DebuggerVariableValue const &rhs);
		~DebuggerVariableValue(void);

		virtual void setValue(int value);
		virtual int getValue();
	
	private:
		int _value;

};

#endif