/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalComparison.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:29 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 14:56:29 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalComparison.hpp"

SymbolNonTerminalComparison::SymbolNonTerminalComparison(void) : AbstractNonTerminal("comparison")
{
	
}

SymbolNonTerminalComparison::~SymbolNonTerminalComparison(void)
{
	
}

int	SymbolNonTerminalComparison::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalComparison::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, {"expr"});
	addProduction(cfg, {"comparison", "separatorpipelineoreps", ">", "separatorpipelineoreps", "expr"});
	addProduction(cfg, {"comparison", "separatorpipelineoreps", ">=", "separatorpipelineoreps", "expr"});
	addProduction(cfg, {"comparison", "separatorpipelineoreps", "<", "separatorpipelineoreps", "expr"});
	addProduction(cfg, {"comparison", "separatorpipelineoreps", "<=", "separatorpipelineoreps", "expr"});
	addProduction(cfg, {"comparison", "separatorpipelineoreps", "!=", "separatorpipelineoreps", "expr"});
	addProduction(cfg, {"comparison", "separatorpipelineoreps", "==", "separatorpipelineoreps", "expr"});
}
