/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:15:38 by niragne           #+#    #+#             */
/*   Updated: 2020/02/04 16:32:49 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

int		jp_a16(struct gb_cpu_s* gb)
{
	uint16_t new_pc;
	uint8_t* ptr = gb->rom_ptr->ptr;

	new_pc = gb->current_instruction->args;
	gb->reg.pc = new_pc;
	gb->jmp = 1;
}
