/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   History.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 12:13:39 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/30 13:11:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef History_HPP
# define History_HPP

# include <iostream>
# include <vector>
# include "DebuggerVariableConstValue.hpp"
# include <string>

class History
{
	public:

		class IndexOutOfRangeException : public std::exception
		{
			public:
				IndexOutOfRangeException(const uint32_t index);
				IndexOutOfRangeException(IndexOutOfRangeException const &instance);
				IndexOutOfRangeException &operator=(IndexOutOfRangeException const &rhs);
				virtual ~IndexOutOfRangeException(void) throw();
				virtual const char *what() const throw();
			private:
				IndexOutOfRangeException(void);
				const uint32_t _index;
				std::string _reason;
		};

		History(void);
		History(History const &instance);
		History &operator=(History const &rhs);
		~History(void);
		void addValue(DebuggerVariableConstValue value);
		DebuggerVariableConstValue &getVariable(uint32_t index);
		uint32_t					getCounter(void);

	private:
		std::vector<DebuggerVariableConstValue>		_values;
};

#endif