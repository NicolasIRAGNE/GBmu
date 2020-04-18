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

#ifndef SYMBOLNONTERMINALSEPARATORPIPELINEOREPS_HPP
# define SYMBOLNONTERMINALSEPARATORPIPELINEOREPS_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalSeparatorPipelineOrEPS : public AbstractNonTerminal<int, CustomStack &>
{
	public:
		SymbolNonTerminalSeparatorPipelineOrEPS(void);
		~SymbolNonTerminalSeparatorPipelineOrEPS(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;
		virtual void computeProductions(AbstractGrammar<int, CustomStack &> & cfg);

	private:

};

#endif
