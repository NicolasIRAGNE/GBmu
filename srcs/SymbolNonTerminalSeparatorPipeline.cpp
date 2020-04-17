/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalSeparatorPipeline.cpp             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalSeparatorPipeline.hpp"

SymbolNonTerminalSeparatorPipeline::SymbolNonTerminalSeparatorPipeline(void) : AbstractNonTerminal("separatorpipeline")
{
	
}

SymbolNonTerminalSeparatorPipeline::~SymbolNonTerminalSeparatorPipeline(void)
{
	
}

int	SymbolNonTerminalSeparatorPipeline::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalSeparatorPipeline::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, 2, (std::string[]){"separatorpipeline", "separator"});
	addProduction(cfg, 1, (std::string[]){"separator"});
}
