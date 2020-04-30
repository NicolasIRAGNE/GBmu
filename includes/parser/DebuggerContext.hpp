/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerContext.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:52:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 14:52:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERCONTEXT_HPP
# define DEBUGGERCONTEXT_HPP

class DebuggerContext
{

	public:

		DebuggerContext(void);
		DebuggerContext(DebuggerContext const &instance);
		DebuggerContext & operator=(DebuggerContext const &rhs);
		~DebuggerContext(void);

};
#endif
