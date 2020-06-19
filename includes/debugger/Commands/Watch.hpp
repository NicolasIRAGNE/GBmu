/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Watch.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:15:39 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 12:36:04 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATCH_HPP
# define WATCH_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Watch : public AbstractCommand
{
	public:
		Watch(void);
		Watch(Watch const &instance);
		Watch &operator=(Watch const &rhs);
		virtual ~Watch(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);

	private:

};

std::ostream &operator<<(std::ostream &o, Watch const &instance);
#endif