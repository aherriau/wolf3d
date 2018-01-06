/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 06:34:24 by ldedier           #+#    #+#             */
/*   Updated: 2018/01/05 00:22:47 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init_init(t_env *e)
{
	e->enemy_init[0].init = &init_sa;
	e->enemy_init[1].init = &init_ss;
	e->enemy_init[2].init = &init_white;
	e->enemy_init[3].init = &init_dog;
	e->enemy_init[4].init = &init_sergent;
	e->enemy_init[5].init = &init_butcher;
	e->enemy_init[6].init = &init_spike_boss;
	e->enemy_init[7].init = &init_vodoo;
	e->enemy_init[8].init = &init_hitler;
}

void	ft_init_process(t_env *e)
{
	e->enemy_process[0].process = &ft_process_ss;
	e->enemy_process[1].process = &ft_process_ss;
	e->enemy_process[2].process = &ft_process_ss;
	e->enemy_process[3].process = &ft_process_ss;
	e->enemy_process[4].process = &ft_process_sergent;
	e->enemy_process[5].process = &ft_process_boss_butcher;
	e->enemy_process[6].process = &ft_process_boss_spike;
	e->enemy_process[7].process = &ft_process_vodoo;
	e->enemy_process[8].process = &ft_process_hitler;
}
