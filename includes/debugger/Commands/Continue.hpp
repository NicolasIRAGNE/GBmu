/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Continue.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:39:35 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 18:40:17 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTINUE_HPP
# define CONTINUE_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Continue : public AbstractCommand
{
	public:
		Continue(void);
		Continue(Continue const &instance);
		Continue &operator=(Continue const &rhs);
		~Continue(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};
#endif