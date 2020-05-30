/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   History.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 12:16:27 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/30 12:53:33 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "History.hpp"

History::History(void) : _values()
{
	
}

History::History(History const &instance)
{
	*this = instance;
}

History::~History(void)
{
	
}

History &	History::operator=(History const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

DebuggerVariableConstValue &History::getVariable(uint32_t index)
{
	uint32_t indexSave;

	indexSave = index;
	if (index == 0)
		index++;
	if (index - 1 >= _values.size())
		throw IndexOutOfRangeException(indexSave);
	else
	{
		return _values.at(index - 1);
	}
}

void	History::addValue(DebuggerVariableConstValue value)
{
	_values.push_back(value);
}

uint32_t History::getCounter(void)
{
	return _values.size();
}

History::IndexOutOfRangeException::IndexOutOfRangeException(void) : _index(0)
{

}

History::IndexOutOfRangeException::IndexOutOfRangeException(const uint32_t index) : _index(index)
	, _reason(index == 0 ? "History is empty." : "History has not yet reached $" + std::to_string(index) + ".")
{

}

History::IndexOutOfRangeException::IndexOutOfRangeException(History::IndexOutOfRangeException const &instance) : _index(instance._index)
{
	*this = instance;
}

History::IndexOutOfRangeException & History::IndexOutOfRangeException::operator=(History::IndexOutOfRangeException const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

History::IndexOutOfRangeException::~IndexOutOfRangeException(void) throw()
{

}

const char *History::IndexOutOfRangeException::what() const throw()
{
	return _reason.c_str();
}
