/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:15:16 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 12:35:56 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Set : public AbstractCommand
{
	public:
		Set(void);
		Set(Set const &instance);
		Set &operator=(Set const &rhs);
		virtual ~Set(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);
	
	private:

};

std::ostream &operator<<(std::ostream &o, Set const &instance);
#endif