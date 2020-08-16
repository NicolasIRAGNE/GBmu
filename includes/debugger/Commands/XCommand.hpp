/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   XCommand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:17:34 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 17:50:19 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XCOMMAND_HPP
# define XCOMMAND_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class XCommand : public AbstractCommand
{
	public:
		XCommand(void);
		XCommand(XCommand const &instance);
		XCommand &operator=(XCommand const &rhs);
		virtual ~XCommand(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};
#endif