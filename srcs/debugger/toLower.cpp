/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toLower.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:14:37 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 17:16:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toLower.hpp"

std::string tolower(std::string string)
{
	std::string res = "";

	for (std::string::size_type i=0; i<string.length(); ++i)
		res = res + static_cast<char>(std::tolower(string[i]));
	return res;
}
