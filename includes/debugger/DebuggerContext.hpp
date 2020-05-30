/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerContext.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/30 16:59:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERCONTEXT_HPP
# define DEBUGGERCONTEXT_HPP

# include "Debugger.hpp"
# include "ASTNode.hpp"
# include <iostream>
# include "PrintCommandSuffixParams.hpp"

enum e_address_descriptor_type
{
	ADDRESS_DESCRIPTOR_TYPE_VARIABLE,
	ADDRESS_DESCRIPTOR_TYPE_INDEX
};

typedef struct						s_address_descriptor
{
	enum e_address_descriptor_type type;

	union
	{
		DebuggerVariable			*variable;
		int32_t						index;
	};
}									t_address_descriptor;

class DebuggerContext
{
	public:

		DebuggerContext(Debugger *debugger);
		DebuggerContext(DebuggerContext const &instance);
		DebuggerContext & operator=(DebuggerContext const &rhs);
		int 			printError(void);
		~DebuggerContext(void);

		Debugger					*debugger;
		PrintCommandSuffixParams	printCommandSuffixParams;
		t_address_descriptor		address_descriptor;

	private:
		DebuggerContext(void);
		

};

#endif
