/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalTerm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
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
	addProduction(cfg, 1, (std::string[]){"factor"});
	addProduction(cfg, 5, (std::string[]){"term", "separatorpipelineoreps", "*", "separatorpipelineoreps", "factor"});
	addProduction(cfg, 5, (std::string[]){"term", "separatorpipelineoreps", "/", "separatorpipelineoreps", "factor"});
	addProduction(cfg, 5, (std::string[]){"term", "separatorpipelineoreps", ">>", "separatorpipelineoreps", "factor"});
	addProduction(cfg, 5, (std::string[]){"term", "separatorpipelineoreps", "<<", "separatorpipelineoreps", "factor"});
	addProduction(cfg, 5, (std::string[]){"term", "separatorpipelineoreps", "|", "separatorpipelineoreps", "factor"});
	addProduction(cfg, 5, (std::string[]){"term", "separatorpipelineoreps", "&", "separatorpipelineoreps", "factor"});
}
