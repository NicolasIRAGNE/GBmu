/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getValue.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:33:09 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/29 17:52:48 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>

template<typename K, typename T>
int getValue(std::map<K, T> & map, K &key, T *res)
{
	typename std::map<K, T>::iterator it;

	it = map.find(key);
	if (it == map.end())
		return (0);
	else
	{
		*res = (*it).second;
		return (1);
	}
}