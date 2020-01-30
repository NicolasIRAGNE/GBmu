/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:15:38 by niragne           #+#    #+#             */
/*   Updated: 2020/01/30 17:15:45 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

int		jp_a16(struct gb_cpu_s* gb)
{
	uint16_t new_pc;
	uint8_t* ptr = gb->rom_ptr->ptr;

	new_pc = ptr[gb->reg.pc + 1] | (ptr[gb->reg.pc + 2] << 8);
	gb->reg.pc = new_pc;
}
