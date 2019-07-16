/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:08:37 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 16:08:18 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_place_to_put(int *arr, int value)
{
	int		adr;

	adr = 1;
	while (adr <= arr[0])
	{
		if (value < arr[adr] && value > arr[(adr == arr[0]) ? 1 : adr + 1])
			return (adr);
		adr++;
	}
	return (0);
}

static void	better_rotation(t_all *all, t_oprs *oprs, int adr_b)
{
	int		adr_a;
	int		dir;

	init_opers(oprs);
	get_rotation(&oprs->rb, &oprs->rrb, all->ps.b[0], adr_b);
	adr_a = get_place_to_put(all->ps.a, all->ps.b[adr_b]);
	oprs->pa = get_rotation(&oprs->ra, &oprs->rra, all->ps.a[0], adr_a);
	get_double_rotation(&oprs->ra, &oprs->rb, &oprs->rr);
	get_double_rotation(&oprs->rra, &oprs->rrb, &oprs->rrr);
	oprs->count = oprs->ra + oprs->rb + oprs->rr
	+ oprs->rra + oprs->rrb + oprs->rrr;
}

static void	rotate_to_finish(t_all *all)
{
	t_info		info;

	get_info(&info, all->ps.a);
	while (all->ps.a[1] != info.max_value)
	{
		if (info.min_adr > all->ps.a[0] / 2)
			make_cmd(all, RA);
		else
			make_cmd(all, RRA);
	}
}

static void	pull_b_stack(t_all *all)
{
	int			delta;
	t_info		info;

	get_info(&info, all->ps.a);
	delta = (info.min_value + info.max_value) / 2;
	while (all->ps.a[0] > 3 && !is_loop_sorted(all->ps.a, info.min_adr))
	{
		if (all->ps.a[all->ps.a[0]] == info.max_value
		|| all->ps.a[all->ps.a[0]] == info.min_value)
			make_cmd(all, RA);
		else
		{
			make_cmd(all, PB);
			if (all->ps.size > 5 && all->ps.b[all->ps.b[0]] > delta)
				make_cmd(all, RB);
		}
		get_info(&info, all->ps.a);
	}
	if (!is_loop_sorted(all->ps.a, info.min_adr))
	{
		if (all->ps.a[1] != info.max_value && all->ps.a[1] != info.min_value)
			make_cmd(all, RA);
		make_cmd(all, SA);
	}
}

void		insert_method(t_all *all)
{
	t_oprs		oprs;
	t_oprs		tmp_oprs;
	t_info		info;
	int			i;

	pull_b_stack(all);
	while (all->ps.b[0])
	{
		i = 0;
		oprs.count = INT32_MAX;
		while (oprs.count != 0 && ++i <= all->ps.b[0])
		{
			better_rotation(all, &tmp_oprs, i);
			if (tmp_oprs.pa && tmp_oprs.count < oprs.count)
				ft_memcpy(&oprs, &tmp_oprs, sizeof(t_oprs));
		}
		solve_operations(all, oprs);
	}
	rotate_to_finish(all);
}
