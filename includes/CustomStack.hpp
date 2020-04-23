/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:30:57 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 16:30:57 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOMSTACK_HPP
# define CUSTOMSTACK_HPP

class CustomStack
{

	public:

		CustomStack(void);
		CustomStack(CustomStack const &instance);
		CustomStack & operator=(CustomStack const &rhs);
		~CustomStack(void);

};
#endif
