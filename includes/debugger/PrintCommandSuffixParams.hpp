/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintCommandSuffixParams.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:04:36 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/14 19:08:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTCOMMANDSUFFIXPARAMS_HPP
# define PRINTCOMMANDSUFFIXPARAMS_HPP

# include <iostream>

#define PRECISED_UNIT 1
#define PRECISED_FORMAT 2
#define PRECISED_COUNT 4

class PrintCommandSuffixParams
{
	public:

	typedef enum	e_debugger_unit
	{
		E_UNIT_WORD,
		E_UNIT_HALFWORD,
	}				t_debugger_unit;

	typedef enum	e_debugger_format
	{
		E_FORMAT_BINARY = 2,
		E_FORMAT_OCTAL = 8,
		E_FORMAT_DECIMAL = 10,
		E_FORMAT_HEXADECIMAL = 16,
		E_FORMAT_INSTRUCTION
	}				t_debugger_format;

		PrintCommandSuffixParams(void);
		PrintCommandSuffixParams(PrintCommandSuffixParams const &instance);
		PrintCommandSuffixParams &operator=(PrintCommandSuffixParams const &rhs);
		~PrintCommandSuffixParams(void);
		
		std::string			getUnitString();
		char				getFormatChar();

		int					precised;
		int					count;
		t_debugger_unit		unit;
		t_debugger_format	format;

};

#endif