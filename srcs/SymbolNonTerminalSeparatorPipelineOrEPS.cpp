/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalSeparatorPipelineOrEPS.           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:47:46 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 12:47:46 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalSeparatorPipelineOrEPS.hpp"

SymbolNonTerminalSeparatorPipelineOrEPS::SymbolNonTerminalSeparatorPipelineOrEPS(void) : AbstractNonTerminal("separatorpipelineoreps")
{
	
}

SymbolNonTerminalSeparatorPipelineOrEPS::~SymbolNonTerminalSeparatorPipelineOrEPS(void)
{
	
}

int	SymbolNonTerminalSeparatorPipelineOrEPS::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalSeparatorPipelineOrEPS::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, {"separatorpipeline"});
	addProduction(cfg, {});
}
