/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalWatchModes.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:59:19 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 18:32:07 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalWatchModes.hpp"
# include "TokenWatchModes.hpp"
# include "toLower.hpp"

SymbolTerminalWatchModes::SymbolTerminalWatchModes(void) : AbstractTerminal("watchmodes", E_PRIORITY_STANDARD, E_ADJACENT_DETACHED)
{
	
}

SymbolTerminalWatchModes::~SymbolTerminalWatchModes(void)
{
	
}

int	SymbolTerminalWatchModes::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{

	TokenWatchModes *token = dynamic_cast<TokenWatchModes *>(ast.getToken());

	context.watchModes = token->getModes();
	return (0);
}

bool	SymbolTerminalWatchModes::isEligibleForCurrent(std::string & current)
{
	size_t size;

	std::string lower = tolower(current);
	size = lower.size();
	return (!lower.compare(0, std::string::npos, "rw", 0, size)
		|| !lower.compare(0, std::string::npos, "wr", 0, size));
}

bool	SymbolTerminalWatchModes::staysEligibleForCurrent(std::string & current)
{
	return (this->isEligibleForCurrent(current));
}

Token<int, DebuggerContext &> *SymbolTerminalWatchModes::createToken(std::string tokenContent)
{
	size_t		i;
	WatchModes	modes;

	modes = 0;
	i = 0;
	if (tokenContent.at(0) == '-')
		i++;
	while (i < tokenContent.size())
	{
		if (tolower(tokenContent.at(i)) == 'r')
			modes |= WATCH_MODE_READ;
		else if (tolower(tokenContent.at(i)) == 'w')
			modes |= WATCH_MODE_WRITE;
		i++;
	}
	return new TokenWatchModes(*this, tokenContent, modes);
}