/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapOfListNoRepetitions.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 16:09:14 by ldedier           #+#    #+#             */
/*   Updated: 2020/08/15 14:45:24 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPOFLISTNOREPETITIONS_HPP
# define MAPOFLISTNOREPETITIONS_HPP

# include <iostream>
# include <list>

template<typename K, typename V>
class MapOfListNoRepetitions
{
	public:
		MapOfListNoRepetitions(void)
		{

		}

		MapOfListNoRepetitions(MapOfListNoRepetitions const &instance)
		{
			*this = instance;
		}

		MapOfListNoRepetitions &operator=(MapOfListNoRepetitions const &rhs)
		{
			static_cast<void>(rhs);
			return *this;
		}

		~MapOfListNoRepetitions(void)
		{
			
		}

		void addValue(K key, V value)
		{
			typename std::map<K, std::list<V>>::iterator it;

			if (_values.find(value) != _values.end()) //TODO Delete this
			{
				std::cerr << "OLALALA" << std::endl;
				return;
			}

			it = _lists.find(key);
			if (it == _lists.end())
			{
				_lists[key] = std::list<V>();
				_lists[key].push_back(value);
				_values[value] = &(_lists[key]);
			}
			else
			{
				it->second.push_back(value);
				_values[value] = &(it->second);
			}
		}

		void clear(void)
		{
			_lists.clear();
			_values.clear();
		}

		bool deleteValue(V value)
		{
			typename std::map<V, std::list<V> *>::iterator it;

			it = _values.find(value);
			if (it == _values.end())
				return false;
			else
			{
				it->second->remove(value);
				_values.erase(it);
				return true;
			}
		}

		bool getLists(K key, std::list<V> *value)
		{
			typename std::map<K, std::list<V> >::iterator it;

			it = _lists.find(key);
			if (it == _lists.end())
				return false;
			else
			{
				if (it->second.size() == 0)
					return false;
				else
				{
					if (value)
						*value = it->second;
					return true;
				}
			}
		}

		bool getLists(K key, std::list<V> **value)
		{
			typename std::map<K, std::list<V> >::iterator it;

			it = _lists.find(key);
			if (it == _lists.end())
				return false;
			else
			{
				if (it->second.size() == 0)
					return false;
				else
				{
					if (value)
						*value = &(it->second);
					return true;
				}
			}
		}

		bool isEmpty()
		{
			return _values.empty();
		}

	private:
		std::map<K, std::list<V> >		_lists;
		std::map<V, std::list<V> *>		_values;
};

#endif