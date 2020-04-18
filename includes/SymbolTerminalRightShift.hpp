/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRightShift.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:47:46 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 12:47:46 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALRIGHTSHIFT_HPP
# define SYMBOLTERMINALRIGHTSHIFT_HPP

# include "AbstractTerminal.hpp"
# include "CustomStack.hpp"

class SymbolTerminalRightShift : public AbstractTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalRightShift(void);
		~SymbolTerminalRightShift(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;

	private:

};

#endif
