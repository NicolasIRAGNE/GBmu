/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalDivide.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 13:25:35 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALDIVIDE_HPP
# define SYMBOLTERMINALDIVIDE_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalDivide : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalDivide(void);
		~SymbolTerminalDivide(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual bool shouldCreateToken(std::string tokenContent
		, char delimiter
		, std::deque<Token<int, DebuggerContext &> *>	& res);
	private:

};

#endif
