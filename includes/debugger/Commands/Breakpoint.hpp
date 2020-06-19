/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Breakpoint.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:18:41 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 12:35:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BREAKPOINT_HPP
# define BREAKPOINT_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Breakpoint : public AbstractCommand
{
	public:
		Breakpoint(void);
		Breakpoint(Breakpoint const &instance);
		Breakpoint &operator=(Breakpoint const &rhs);
		virtual ~Breakpoint(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);

	private:

};

#endif