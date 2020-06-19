/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Next.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:20:53 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 12:35:45 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXT_HPP
# define NEXT_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Next : public AbstractCommand
{
	public:
		Next(void);
		Next(Next const &instance);
		Next &operator=(Next const &rhs);
		virtual ~Next(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);

	private:

};

std::ostream &operator<<(std::ostream &o, Next const &instance);
#endif