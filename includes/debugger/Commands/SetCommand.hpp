/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetCommand.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:15:16 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/27 16:32:59 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETCOMMAND_HPP
# define SETCOMMAND_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class SetCommand : public AbstractCommand
{
	public:
		SetCommand(void);
		SetCommand(SetCommand const &instance);
		SetCommand &operator=(SetCommand const &rhs);
		virtual ~SetCommand(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif