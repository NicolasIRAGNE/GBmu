/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Help.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:13:28 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 17:43:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_HPP
# define HELP_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Help : public AbstractCommand
{
	public:
		Help(void);
		Help(Help const &instance);
		Help &operator=(Help const &rhs);
		virtual ~Help(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif