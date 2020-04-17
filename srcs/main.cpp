/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "DebuggerGrammar.hpp"
#include "LRParser.hpp"

int main(void)
{
	DebuggerGrammar grammar;
	LRParser<int, CustomStack &> parser(grammar);
	std::deque<Token<int, CustomStack &> *> tokens;
	CustomStack context;

	grammar.debug(false);
	try
	{
		tokens = grammar.lex(true, std::cin);
		printTokenQueue(tokens);
		ASTBuilder<int, CustomStack &>*b = parser.parse(tokens);
		int res = b->getASTRoot()->getTraversed(context);
		std::cout << *b << std::endl;
		std::cout << "result: " << res << std::endl;
		delete b;
		deleteTokens(tokens);
	}
	catch (const LRActionError<int, CustomStack &>::SyntaxErrorException &e)
	{
		deleteTokens(tokens);
		std::cerr << std::endl << e.what() << std::endl;
	}
	catch (const AbstractGrammar<int, CustomStack &>::LexicalErrorException &e)
	{
		deleteTokens(tokens);
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
