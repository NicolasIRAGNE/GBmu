/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenWatchModes.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:34:17 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 17:40:37 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENWATCHMODES_HPP
# define TOKENWATCHMODES_HPP

# include <iostream>
# include "Token.hpp"
# include "DebuggerContext.hpp"
# include "WatchModes.hpp"

class TokenWatchModes : public Token<int, DebuggerContext &>
{
	public:
		TokenWatchModes(void);
		virtual ~TokenWatchModes(void);
		TokenWatchModes(AbstractTerminal<int, DebuggerContext &> &term
		, std::string content
		, WatchModes modes);
		WatchModes getModes(void);
		virtual std::ostream &repr(std::ostream &o);

	private:
		WatchModes _modes;

};

#endif