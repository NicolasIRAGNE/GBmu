/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Run.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:03:42 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 18:04:10 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_HPP
# define RUN_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Run : public AbstractCommand
{
	public:
		Run(void);
		Run(Run const &instance);
		Run &operator=(Run const &rhs);
		~Run(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

std::ostream &operator<<(std::ostream &o, Run const &instance);
#endif