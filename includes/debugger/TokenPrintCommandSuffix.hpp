/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenPrintCommandSuffix.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:02:13 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/14 17:11:45 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENPRINTCOMMANDSUFFIX_HPP
# define TOKENPRINTCOMMANDSUFFIX_HPP

# include "DebuggerGrammar.hpp"
# include "PrintCommandSuffixParams.hpp"

class TokenPrintCommandSuffix : public Token<int, DebuggerContext &>
{
	public:
		TokenPrintCommandSuffix(void);
		TokenPrintCommandSuffix(AbstractTerminal<int, DebuggerContext &> & term, std::string content);
		virtual ~TokenPrintCommandSuffix(void);

		TokenPrintCommandSuffix(AbstractTerminal<int, DebuggerContext &> &term
		, std::string content
		, PrintCommandSuffixParams printCommandSuffixParams);

		PrintCommandSuffixParams getPrintCommandSuffixParams();
		virtual std::ostream &repr(std::ostream &o);

	private:
		PrintCommandSuffixParams _printCommandSuffixParams;
};

std::ostream &operator<<(std::ostream &o, TokenPrintCommandSuffix  &instance);
#endif