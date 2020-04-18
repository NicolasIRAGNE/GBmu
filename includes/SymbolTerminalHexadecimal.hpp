/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalHexadecimal.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:47:46 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 12:47:46 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALHEXADECIMAL_HPP
# define SYMBOLTERMINALHEXADECIMAL_HPP

# include "AbstractTerminal.hpp"
# include "CustomStack.hpp"

class SymbolTerminalHexadecimal : public AbstractTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalHexadecimal(void);
		~SymbolTerminalHexadecimal(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;

	private:

};

#endif
