/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:08:37 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/18 18:37:44 by nalexand         ###   ########.fr       */
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

static void	better_rotation(t_all *all, t_oprs *oprs, int adr_b, int *level)
{
	int		adr_a;
	int		i;

	if (all->ps.size <= LIMIT
	|| get_value_mark(all->ps.marks, all->ps.b[adr_b]).level == *level)
	{
		init_opers(oprs);
		get_rotation(&oprs->rb, &oprs->rrb, all->ps.b[0], adr_b);
		adr_a = get_place_to_put(all->ps.a, all->ps.b[adr_b]);
		oprs->pa = get_rotation(&oprs->ra, &oprs->rra, all->ps.a[0], adr_a);
		get_double_rotation(&oprs->ra, &oprs->rb, &oprs->rr);
		get_double_rotation(&oprs->rra, &oprs->rrb, &oprs->rrr);
		oprs->count = oprs->ra + oprs->rb + oprs->rr
		+ oprs->rra + oprs->rrb + oprs->rrr;
	}
	else
		oprs->count = INT32_MAX;
	i = 0;
	while (++i <= all->ps.b[0])
		if (get_value_mark(all->ps.marks, all->ps.b[i]).level == *level)
			return ;
	(*level)++;
}

static void	rotate_to_finish(t_all *all)
{
	get_info(&all->ps.info, all->ps.a);
	while (all->ps.a[1] != all->ps.info.max_value)
	{
		if (all->ps.info.min_adr > all->ps.a[0] / 2)
			make_cmd(all, RA);
		else
			make_cmd(all, RRA);
	}
}

void		insert_method(t_all *all)
{
	t_oprs		oprs;
	t_oprs		tmp_oprs;
	int			i;
	int			level;

	pull_b_stack(all);
	level = 1;
	while (all->ps.b[0])
	{
		i = 0;
		oprs.count = INT32_MAX;
		while (oprs.count != 0 && ++i <= all->ps.b[0])
		{
			better_rotation(all, &tmp_oprs, i, &level);
			if (tmp_oprs.pa && tmp_oprs.count < oprs.count)
				ft_memcpy(&oprs, &tmp_oprs, sizeof(t_oprs));
		}
		solve_operations(all, oprs);
	}
	rotate_to_finish(all);
}
