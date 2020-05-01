/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisterD.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
/*   Created: 2020/04/30 16:25:25 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/01 17:43:58 by ldedier          ###   ########.fr       */
=======
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
>>>>>>> Stashed changes
=======
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
>>>>>>> Stashed changes
=======
/*   Created: 2020/05/01 16:38:32 by ldedier            #+#    #+#            */
/*   Updated: 2020/05/01 16:38:32 by ldedier           ###   ########.fr      */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalRegisterD.hpp"

SymbolTerminalRegisterD::SymbolTerminalRegisterD(void) : AbstractTerminal("d")
{
	
}

SymbolTerminalRegisterD::~SymbolTerminalRegisterD(void)
{
	
}

int	SymbolTerminalRegisterD::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

