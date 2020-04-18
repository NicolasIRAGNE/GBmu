/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalTerm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:47:46 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 12:47:46 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalTerm.hpp"

SymbolNonTerminalTerm::SymbolNonTerminalTerm(void) : AbstractNonTerminal("term")
{
	
}

SymbolNonTerminalTerm::~SymbolNonTerminalTerm(void)
{
	
}

int	SymbolNonTerminalTerm::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalTerm::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, {"factor"});
	addProduction(cfg, {"term", "separatorpipelineoreps", "*", "separatorpipelineoreps", "factor"});
	addProduction(cfg, {"term", "separatorpipelineoreps", "/", "separatorpipelineoreps", "factor"});
	addProduction(cfg, {"term", "separatorpipelineoreps", ">>", "separatorpipelineoreps", "factor"});
	addProduction(cfg, {"term", "separatorpipelineoreps", "<<", "separatorpipelineoreps", "factor"});
	addProduction(cfg, {"term", "separatorpipelineoreps", "|", "separatorpipelineoreps", "factor"});
	addProduction(cfg, {"term", "separatorpipelineoreps", "&", "separatorpipelineoreps", "factor"});
}
