/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:25:34 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 17:50:29 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_HPP
# define INFO_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Info : public AbstractCommand
{
	public:
		Info(void);
		Info(Info const &instance);
		Info &operator=(Info const &rhs);
		virtual ~Info(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

std::ostream &operator<<(std::ostream &o, Info const &instance);
#endif