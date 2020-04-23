/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalSeparatorPipeline.cpp             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 15:33:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 15:33:38 by ldedier           ###   ########.fr      */
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
	addProduction(cfg, {"separatorpipeline", "separator"});
	addProduction(cfg, {"separator"});
}
