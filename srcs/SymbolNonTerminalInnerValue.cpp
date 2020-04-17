/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalInnerValue.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalInnerValue.hpp"

SymbolNonTerminalInnerValue::SymbolNonTerminalInnerValue(void) : AbstractNonTerminal("innervalue")
{
	
}

SymbolNonTerminalInnerValue::~SymbolNonTerminalInnerValue(void)
{
	
}

int	SymbolNonTerminalInnerValue::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalInnerValue::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, 1, (std::string[]){"andor"});
	addProduction(cfg, 5, (std::string[]){"(", "separatorpipeline", "innervalue", "separatorpipeline", ")"});
}
