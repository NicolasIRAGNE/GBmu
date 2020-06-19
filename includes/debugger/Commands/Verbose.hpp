/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Verbose.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:20:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 12:36:02 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOSE_HPP
# define VERBOSE_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Verbose : public AbstractCommand
{
	public:
		Verbose(void);
		Verbose(Verbose const &instance);
		Verbose &operator=(Verbose const &rhs);
		virtual ~Verbose(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);

	private:

};

std::ostream &operator<<(std::ostream &o, Verbose const &instance);
#endif