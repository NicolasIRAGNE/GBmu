/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerVariableConstValue.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:01:52 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/29 18:30:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERVARIABLECONSTVALUE_HPP
# define DEBUGGERVARIABLECONSTVALUE_HPP

# include <iostream>
# include "DebuggerVariableValue.hpp"

class DebuggerVariableConstValue : public DebuggerVariableValue
{
	public:
	
		DebuggerVariableConstValue(int value);
		~DebuggerVariableConstValue(void);

		virtual void setValue(int value);
	
	private:
		DebuggerVariableConstValue(void);

};

#endif