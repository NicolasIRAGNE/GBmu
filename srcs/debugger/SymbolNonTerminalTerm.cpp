/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalTerm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/15 18:48:34 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalTerm.hpp"

SymbolNonTerminalTerm::SymbolNonTerminalTerm(void) : AbstractNonTerminal("term")
{
	
}

SymbolNonTerminalTerm::~SymbolNonTerminalTerm(void)
{
	
}

int	SymbolNonTerminalTerm::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	long tmp;

	if (ast.getChildren().size() == 1)
		return ast.getChild(0)->getTraversed(context);

	tmp = ast.getChild(2)->getTraversed(context);
	
	if (ast.getChild(1)->getSymbol().getIdentifier() == "*")
		return ast.getChild(0)->getTraversed(context) * tmp;
	else if (ast.getChild(1)->getSymbol().getIdentifier() == ">>")
		return ast.getChild(0)->getTraversed(context) >> tmp;
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "%"
		|| ast.getChild(1)->getSymbol().getIdentifier() == "/")
	{
		if (!tmp)
			throw DivByZeroException();
		if (ast.getChild(1)->getSymbol().getIdentifier() == "%")
			return ast.getChild(0)->getTraversed(context) % tmp;
		else
			return ast.getChild(0)->getTraversed(context) / tmp;

	}
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "<<")
		return ast.getChild(0)->getTraversed(context) << tmp;
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "|")
		return ast.getChild(0)->getTraversed(context) | tmp;
	else if (ast.getChild(1)->getSymbol().getIdentifier() == "&")
		return ast.getChild(0)->getTraversed(context) & tmp;
	return (0);
}

void	SymbolNonTerminalTerm::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"factor"});
	addProduction(cfg, {"term", "*", "factor"});
	addProduction(cfg, {"term", "%", "factor"});
	addProduction(cfg, {"term", "/", "factor"});
	addProduction(cfg, {"term", ">>", "factor"});
	addProduction(cfg, {"term", "<<", "factor"});
	addProduction(cfg, {"term", "|", "factor"});
	addProduction(cfg, {"term", "&", "factor"});
}

SymbolNonTerminalTerm::DivByZeroException::DivByZeroException(void) : _reason("Division by zero")
{

}

SymbolNonTerminalTerm::DivByZeroException::DivByZeroException(SymbolNonTerminalTerm::DivByZeroException const &instance)
{
	*this = instance;
}

SymbolNonTerminalTerm::DivByZeroException & SymbolNonTerminalTerm::DivByZeroException::operator=(SymbolNonTerminalTerm::DivByZeroException const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

SymbolNonTerminalTerm::DivByZeroException::~DivByZeroException(void) throw()
{

}

const char *SymbolNonTerminalTerm::DivByZeroException::what() const throw()
{
	return _reason.c_str();
}
