#include "DebuggerGrammar.hpp"
#include "LRParser.hpp"
#include "gb.h"
#include <sstream>

extern "C"
{

	int libyacc_init_debugger(struct gb_cpu_s *cpu, struct gbmu_debugger_s* debugger)
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
		if (!(debugger->instance = (void *) (new Debugger(cpu))))
		{
			delete static_cast<DebuggerGrammar *>(debugger->grammar);
			delete static_cast<LRParser<int, DebuggerContext &> *>(debugger->parser);
			debugger->grammar = NULL;
			debugger->parser = NULL;
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}

	int libyacc_execute(struct gb_cpu_s *cpu, const char *string, int store)
	{
		int res;
		DebuggerGrammar *grammar = static_cast<DebuggerGrammar *>(cpu->debugger->grammar);
		LRParser<int, DebuggerContext &> *parser = static_cast<LRParser<int, DebuggerContext &> *>(cpu->debugger->parser);
		Debugger *debugger = static_cast<Debugger *>(cpu->debugger->instance);

		std::deque<Token<int, DebuggerContext &> *> tokens;
		std::stringstream sstr(string);
		DebuggerContext context(debugger);
		
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
		catch (const std::out_of_range &e)
		{
			deleteTokens(tokens);
			std::cerr << "Numeric constant too large." << std::endl;
			res = 1;
		}
		catch (const SymbolNonTerminalTerm::DivByZeroException &e)
		{
			deleteTokens(tokens);
			std::cerr << e.what() << std::endl;
			res = 1;
		}
		catch (const History::IndexOutOfRangeException &e)
		{
			deleteTokens(tokens);
			std::cerr << e.what() << std::endl;
			res = 1;
		}
		if (store && context.shouldSaveAsLastCommand)
			debugger->setLastCommand(string);
		return (res);
	}

	void libyacc_free(struct gbmu_debugger_s *debugger)
	{
		DebuggerGrammar *grammar = static_cast<DebuggerGrammar *>(debugger->grammar);
		LRParser<int, DebuggerContext &> *parser = static_cast<LRParser<int, DebuggerContext &> *>(debugger->parser);
		Debugger *instance = static_cast<Debugger *>(debugger->instance);

		if (grammar != nullptr)
			delete grammar;
		if (parser != nullptr)
			delete parser;
		if (instance != nullptr)
			delete instance;
	}

	int	get_verbose(void *debugger)
	{
		(void)debugger;
		return 0;
	}

	int	find_breakpoint(void *debugger, int pc)
	{
		(void)debugger;
		(void)pc;
		return 0;
	}

}