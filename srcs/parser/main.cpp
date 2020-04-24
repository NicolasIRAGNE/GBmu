/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 19:16:33 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/24 19:16:33 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "DebuggerGrammar.hpp"
#include "LRParser.hpp"

int main(void)
{
	DebuggerGrammar grammar;
	LRParser<int, DebuggerContext &> parser(grammar);
	std::deque<Token<int, DebuggerContext &> *> tokens;
	DebuggerContext context;

	grammar.debug(false);
	try
	{
		tokens = grammar.lex(true, std::cin);
		printTokenQueue(tokens);
		ASTBuilder<int, DebuggerContext &>*b = parser.parse(tokens);
		int res = b->getASTRoot()->getTraversed(context);
		std::cout << *b << std::endl;
		std::cout << "result: " << res << std::endl;
		delete b;
		deleteTokens(tokens);
	}
	catch (const LRActionError<int, DebuggerContext &>::SyntaxErrorException &e)
	{
		deleteTokens(tokens);
		std::cerr << std::endl << e.what() << std::endl;
	}
	catch (const AbstractGrammar<int, DebuggerContext &>::LexicalErrorException &e)
	{
		deleteTokens(tokens);
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
