/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:56:17 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/18 04:01:34 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	delta_presort(t_all *all)
{
	int		i;

	i = all->ps.a[0] + 1;
	while (--i)
	{
		if (all->ps.a[all->ps.a[0]] == all->ps.max_value
		|| all->ps.a[all->ps.a[0]] == all->ps.min_value
		|| get_value_mark(all->ps.marks, all->ps.a[all->ps.a[0]]).level == 3)
			make_cmd(all, RA);
		else
		{
			make_cmd(all, PB);
			if (get_value_mark(all->ps.marks,
			all->ps.b[all->ps.b[0]]).level == 2)
				make_cmd(all, RB);
		}
		get_info(&all->ps.info, all->ps.a);
	}
}

void		pull_b_stack(t_all *all)
{
	if (all->ps.size > 10)
		delta_presort(all);
	while (all->ps.a[0] > 3 && !is_loop_sorted(all->ps.a, all->ps.info.min_adr))
	{
		if (all->ps.a[all->ps.a[0]] == all->ps.max_value
		|| all->ps.a[all->ps.a[0]] == all->ps.min_value)
			make_cmd(all, RA);
		else
			make_cmd(all, PB);
		get_info(&all->ps.info, all->ps.a);
	}
	if (!is_loop_sorted(all->ps.a, all->ps.info.min_adr))
	{
		if (all->ps.a[1] != all->ps.max_value
		&& all->ps.a[1] != all->ps.min_value)
			make_cmd(all, RA);
		make_cmd(all, SA);
	}
}
