/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libyacc_wrapper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 19:15:42 by ldedier           #+#    #+#             */
/*   Updated: 2020/05/15 15:12:10 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBYACC_WRAPPER_H
# define LIBYACC_WRAPPER_H

#include "cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

int libyacc_init_debugger(struct gb_cpu_s *cpu, struct gbmu_debugger_s* debugger);
int libyacc_execute(struct gb_cpu_s *cpu, char *string);
void libyacc_free(struct gbmu_debugger_s *debugger);

#ifdef __cplusplus
}
#endif

#endif
