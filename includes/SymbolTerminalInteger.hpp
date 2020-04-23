/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalInteger.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:30:57 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 16:30:57 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALINTEGER_HPP
# define SYMBOLTERMINALINTEGER_HPP

# include "AbstractUnsignedIntegerTerminal.hpp"
# include "CustomStack.hpp"

class SymbolTerminalInteger : public AbstractTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalInteger(void);
		~SymbolTerminalInteger(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;
		virtual bool isEligibleForCurrent(std::string & current);
		virtual bool staysEligibleForCurrent(std::string & current);
		virtual Token<int, CustomStack &> *createToken(std::string tokenContent);
	private:

};

#endif
