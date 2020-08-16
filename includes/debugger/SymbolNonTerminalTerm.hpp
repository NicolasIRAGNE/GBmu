/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalTerm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/15 18:47:38 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALTERM_HPP
# define SYMBOLNONTERMINALTERM_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalTerm : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:

		class DivByZeroException : public std::exception
		{
			public:
				DivByZeroException(void);
				DivByZeroException(DivByZeroException const &instance);
				DivByZeroException &operator=(DivByZeroException const &rhs);
				virtual ~DivByZeroException(void) throw();
				virtual const char *what() const throw();
			private:
				std::string _reason;
		};

		SymbolNonTerminalTerm(void);
		~SymbolNonTerminalTerm(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
