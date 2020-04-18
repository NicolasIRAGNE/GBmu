/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:47:46 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 12:47:46 by ldedier           ###   ########.fr      */
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
