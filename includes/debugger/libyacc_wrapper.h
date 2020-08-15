/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libyacc_wrapper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 19:15:42 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/25 19:17:10 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBYACC_WRAPPER_H
# define LIBYACC_WRAPPER_H

#include "cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

int libyacc_init_debugger(struct gb_cpu_s *cpu, struct gbmu_debugger_s* debugger);
int libyacc_execute(struct gb_cpu_s *cpu, const char *string, int store, int *quit);
void libyacc_free(struct gbmu_debugger_s *debugger);
int	get_verbose(void *debugger);
int	find_breakpoint(void *debugger, int pc);
int	find_watchpointFromPointer(void *debugger, void *pointer , int mode);
int	find_watchpointFromOffset(void *debugger, uint16_t offset, size_t size, int mode);

void libyacc_free(struct gbmu_debugger_s *debugger);

#ifdef __cplusplus
}
#endif

#endif
