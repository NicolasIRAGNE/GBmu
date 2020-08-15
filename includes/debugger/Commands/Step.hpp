/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Step.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:19:54 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/26 17:44:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STEP_HPP
# define STEP_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Step : public AbstractCommand
{
	public:
		Step(void);
		Step(Step const &instance);
		Step &operator=(Step const &rhs);
		virtual ~Step(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
		virtual int execute(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

std::ostream &operator<<(std::ostream &o, Step const &instance);
#endif