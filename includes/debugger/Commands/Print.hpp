/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:16:16 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 17:44:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HPP
# define PRINT_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Print : public AbstractCommand
{
	public:
		Print(void);
		Print(Print const &instance);
		Print &operator=(Print const &rhs);
		virtual ~Print(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

std::ostream &operator<<(std::ostream &o, Print const &instance);
#endif