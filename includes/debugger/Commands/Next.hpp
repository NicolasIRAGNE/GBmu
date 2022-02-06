/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Next.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:20:53 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 17:44:06 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXT_HPP
# define NEXT_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Next : public AbstractCommand
{
	public:
		Next(void);
		Next(Next const &instance);
		Next &operator=(Next const &rhs);
		virtual ~Next(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

std::ostream &operator<<(std::ostream &o, Next const &instance);
#endif