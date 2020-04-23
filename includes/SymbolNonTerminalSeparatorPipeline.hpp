/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalSeparatorPipeline.hpp             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 15:33:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 15:33:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALSEPARATORPIPELINE_HPP
# define SYMBOLNONTERMINALSEPARATORPIPELINE_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalSeparatorPipeline : public AbstractNonTerminal<int, CustomStack &>
{
	public:
		SymbolNonTerminalSeparatorPipeline(void);
		~SymbolNonTerminalSeparatorPipeline(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;
		virtual void computeProductions(AbstractGrammar<int, CustomStack &> & cfg);

	private:

};

#endif
