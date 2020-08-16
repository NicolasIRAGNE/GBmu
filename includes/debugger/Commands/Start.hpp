/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Start.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:57:48 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 18:04:14 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_HPP
# define START_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Start : public AbstractCommand
{
	public:
		Start(void);
		Start(Start const &instance);
		Start &operator=(Start const &rhs);
		~Start(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

std::ostream &operator<<(std::ostream &o, Start const &instance);
#endif