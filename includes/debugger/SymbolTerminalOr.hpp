/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalOr.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:29 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 14:56:29 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALOR_HPP
# define SYMBOLTERMINALOR_HPP

# include "AbstractTerminal.hpp"
# include "CustomStack.hpp"

class SymbolTerminalOr : public AbstractTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalOr(void);
		~SymbolTerminalOr(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;

	private:

};

#endif