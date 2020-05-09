/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenPrintCommandSuffix.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:02:13 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/03 21:31:53 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENPRINTCOMMANDSUFFIX_HPP
# define TOKENPRINTCOMMANDSUFFIX_HPP

# include "DebuggerGrammar.hpp"

#define PRECISED_UNIT 1
#define PRECISED_FORMAT 2
#define PRECISED_COUNT 4

class TokenPrintCommandSuffix : public Token<int, DebuggerContext &>
{
	public:
		TokenPrintCommandSuffix(void);
		TokenPrintCommandSuffix(AbstractTerminal<int, DebuggerContext &> & term, std::string content);
		virtual ~TokenPrintCommandSuffix(void);

		TokenPrintCommandSuffix(AbstractTerminal<int, DebuggerContext &> &term
		, std::string content
		, int precised
		, int count
		, DebuggerContext::t_debugger_unit unit
		, DebuggerContext::t_debugger_format format);
		
		DebuggerContext::t_debugger_unit getUnit();
		DebuggerContext::t_debugger_format getFormat();
		int getPrecised();
		int getCount();
		virtual std::ostream &repr(std::ostream &o);

	private:

	int	_precised;
	int _count;
	DebuggerContext::t_debugger_unit _unit;
	DebuggerContext::t_debugger_format _format;
};

std::ostream &operator<<(std::ostream &o, TokenPrintCommandSuffix  &instance);
#endif