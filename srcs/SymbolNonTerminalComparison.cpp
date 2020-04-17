/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalComparison.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
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
	addProduction(cfg, 1, (std::string[]){"expr"});
	addProduction(cfg, 5, (std::string[]){"comparison", "separatorpipelineoreps", ">", "separatorpipelineoreps", "expr"});
	addProduction(cfg, 5, (std::string[]){"comparison", "separatorpipelineoreps", ">=", "separatorpipelineoreps", "expr"});
	addProduction(cfg, 5, (std::string[]){"comparison", "separatorpipelineoreps", "<", "separatorpipelineoreps", "expr"});
	addProduction(cfg, 5, (std::string[]){"comparison", "separatorpipelineoreps", "<=", "separatorpipelineoreps", "expr"});
	addProduction(cfg, 5, (std::string[]){"comparison", "separatorpipelineoreps", "!=", "separatorpipelineoreps", "expr"});
	addProduction(cfg, 5, (std::string[]){"comparison", "separatorpipelineoreps", "==", "separatorpipelineoreps", "expr"});
}
