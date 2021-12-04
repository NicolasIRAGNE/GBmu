/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:18:01 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 17:44:14 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUIT_HPP
# define QUIT_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Quit : public AbstractCommand
{
	public:
		Quit(void);
		Quit(Quit const &instance);
		Quit &operator=(Quit const &rhs);
		virtual ~Quit(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

std::ostream &operator<<(std::ostream &o, Quit const &instance);
#endif