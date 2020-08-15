/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Registers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:14:48 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 17:44:16 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGISTERS_HPP
# define REGISTERS_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Registers : public AbstractCommand
{
	public:
		Registers(void);
		Registers(Registers const &instance);
		Registers &operator=(Registers const &rhs);
		virtual ~Registers(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

std::ostream &operator<<(std::ostream &o, Registers const &instance);
#endif