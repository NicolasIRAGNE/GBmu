/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WatchModes.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:24:28 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/15 17:37:32 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATCHMODES_HPP
# define WATCHMODES_HPP

#include <stdint.h>

# define WATCH_MODE_READ (1 << 1)
# define WATCH_MODE_WRITE (1 << 2)

typedef uint8_t WatchModes; 

#endif