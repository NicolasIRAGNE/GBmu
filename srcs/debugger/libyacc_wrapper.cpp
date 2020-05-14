#include "DebuggerGrammar.hpp"
#include "LRParser.hpp"
#include "gb.h"
#include <sstream>

extern "C"
{

	int libyacc_init_debugger(struct gbmu_debugger_s* debugger)
	{
		DebuggerGrammar *debugGrammar = new DebuggerGrammar();
		if (!(debugger->grammar = (void *) debugGrammar))
			return EXIT_FAILURE;
		if (!(debugger->parser = (void *) (new LRParser<int, DebuggerContext &>(*debugGrammar))))
		{
			delete static_cast<DebuggerGrammar *>(debugger->grammar);
			debugger->grammar = NULL;
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}

	int libyacc_execute(struct gb_cpu_s *cpu, char *string)
	{
		int res;
		DebuggerGrammar *grammar = static_cast<DebuggerGrammar *>(cpu->debugger->grammar);
		LRParser<int, DebuggerContext &> *parser = static_cast<LRParser<int, DebuggerContext &> *>(cpu->debugger->parser);
		std::deque<Token<int, DebuggerContext &> *> tokens;
		std::stringstream sstr(string);
		DebuggerContext context(cpu);

		res = 0;
		try
		{
			tokens = grammar->lex(false, sstr);
			// printTokenQueue(tokens);
			ASTBuilder<int, DebuggerContext &>*b = parser->parse(tokens);
			res = b->getASTRoot()->getTraversed(context);
			// std::cout << *b << std::endl;
			delete b;
			deleteTokens(tokens);
		}
		catch (const LRActionError<int, DebuggerContext &>::SyntaxErrorException &e)
		{
			deleteTokens(tokens);
			std::cerr << std::endl << e.what() << std::endl;
			res = 1;
		}
		catch (const AbstractGrammar<int, DebuggerContext &>::LexicalErrorException &e)
		{
			deleteTokens(tokens);
			std::cerr << e.what() << std::endl;
			res = 1;
		}
		return (res);
	}

	void libyacc_free(struct gbmu_debugger_s *debugger)
	{
		DebuggerGrammar *grammar = static_cast<DebuggerGrammar *>(debugger->grammar);
		LRParser<int, DebuggerContext &> *parser = static_cast<LRParser<int, DebuggerContext &> *>(debugger->parser);

		if (grammar != nullptr)
			delete grammar;
		if (parser != nullptr)
			delete parser;
	}

}