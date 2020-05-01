/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalFormat.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< Updated upstream
/*   Created: 2020/04/30 16:25:25 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/01 18:45:12 by ldedier          ###   ########.fr       */
=======
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalFormat.hpp"

SymbolNonTerminalFormat::SymbolNonTerminalFormat(void) : AbstractNonTerminal("format")
{
	
}

SymbolNonTerminalFormat::~SymbolNonTerminalFormat(void)
{
	
}

int	SymbolNonTerminalFormat::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalFormat::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"decimal"});
	addProduction(cfg, {"x"});
	addProduction(cfg, {"o"});
	addProduction(cfg, {"b"});
	addProduction(cfg, {"i"});
}
