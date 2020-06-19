/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delete.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:24:03 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 12:35:10 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELETE_HPP
# define DELETE_HPP

# include <iostream>
# include "AbstractCommand.hpp"

class Delete : public AbstractCommand
{
	public:
		Delete(void);
		Delete(Delete const &instance);
		Delete &operator=(Delete const &rhs);
		virtual ~Delete(void);
		virtual std::string getHelp(void);
		virtual std::string getShortHelp(void);

	private:

};

#endif