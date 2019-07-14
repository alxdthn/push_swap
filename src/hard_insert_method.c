/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_insert_method.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:18:08 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/14 20:29:01 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_value_adr(int *arr, int value)
{
	int		adr;

	adr = 1;
	while (adr <= arr[0])
	{
		if (arr[adr] == value)
			return (adr);
		adr++;
	}
	return (0);
}

static int	count_rotations(int size, int adr, int dir)
{
	int		count;
	int		ra;
	int		rra;

	count = 0;
	if (adr)
	{
		if ((ra = size - adr + dir) > size / 2)
		{
			rra = adr - dir;
			ra = 0;
		}
		count = ra + rra;
	}
	return (count);
}

static void	sort(int *arr)
{
	size_t	i;
	size_t	size;
	int		tmp;

	i = 1;
	while (i < arr[0])
	{
		if (arr[i] < arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 1;
			continue ;
		}
		i++;
	}
}

static void	get_neibs(t_all *all, t_neibs *cur, int value)
{
	int		i;

	i = 0;
	while (all->ps.neibs[i]->value != value)
		i++;
	cur->down = all->ps.neibs[i]->down;
	cur->up = all->ps.neibs[i]->up;
	cur->value = all->ps.neibs[i]->value;
}

static void	find_neibs(t_all *all)
{
	int		*tmp_sort;
	int		i;

	if (!(tmp_sort = ft_memdup(all->ps.a, sizeof(int) * (all->ps.a[0]) + 1)))
		push_swap_clear_exit(all, PS_MEM_ERR);
	if (!(all->ps.neibs = (t_neibs **)ft_memalloc(sizeof(t_neibs *) * (all->ps.a[0] + 1))))
	{
		ft_memdel((void **)&tmp_sort);
		push_swap_clear_exit(all, PS_MEM_ERR);
	}
	all->ps.neibs[all->ps.a[0]] = NULL;
	sort(tmp_sort);
	i = 0;
	while (++i <= all->ps.a[0])
	{
		if (!(all->ps.neibs[i - 1] = (t_neibs *)malloc(sizeof(t_neibs))))
			push_swap_clear_exit(all, PS_MEM_ERR);
		all->ps.neibs[i - 1]->value = tmp_sort[i];
		all->ps.neibs[i - 1]->down = (i == 1) ? tmp_sort[tmp_sort[0]] : tmp_sort[i - 1];
		all->ps.neibs[i - 1]->up = (i == tmp_sort[0]) ? tmp_sort[1] : tmp_sort[i + 1];
	}
	ft_memdel((void **)&tmp_sort);
}

static void	find_better_rotation(t_all *all, t_oprs *oprs, int adr_b)
{
	t_neibs	neibs;
	int		adr_a_up;
	int		adr_a_down;
	int		up_rot;
	int		down_rot;

	init_opers(oprs);
	get_neibs(all, &neibs, all->ps.b[adr_b]);
	get_rotation(&oprs->rb, &oprs->rrb, all->ps.b[0], adr_b, 0);
	adr_a_up = get_value_adr(all->ps.a, neibs.up);
	adr_a_down = get_value_adr(all->ps.a, neibs.down);
	if (adr_a_up && adr_a_down)
	{
		up_rot = count_rotations(all->ps.a[0], adr_a_up, 1);
		down_rot = count_rotations(all->ps.a[0], adr_a_down, 0);
		if (up_rot < down_rot)
			oprs->pa = get_rotation(&oprs->ra, &oprs->rra, all->ps.a[0], adr_a_up, 1);
		else
			oprs->pa = get_rotation(&oprs->ra, &oprs->rra, all->ps.a[0], adr_a_down, 0);
	}
	else
	{
		if (adr_a_up)
			oprs->pa = get_rotation(&oprs->ra, &oprs->rra, all->ps.a[0], adr_a_up, 1);
		else
			oprs->pa = get_rotation(&oprs->ra, &oprs->rra, all->ps.a[0], adr_a_down, 0);
	}
	get_double_rotation(&oprs->ra, &oprs->rb, &oprs->rr);
	get_double_rotation(&oprs->rra, &oprs->rrb, &oprs->rrr);
	oprs->count = oprs->ra + oprs->rb + oprs->rr + oprs->rra + oprs->rrb + oprs->rrr;
}

void	hard_insert_method(t_all *all)
{
	t_neibs			neibs;
	t_oprs			tmp_oprs;
	t_oprs			oprs;
	t_info			info;
	int				i;

	find_neibs(all);
	while (all->ps.a[0] > 2)
		make_cmd(all, PB);
	while (all->ps.b[0])
	{
		i = 0;
		oprs.count = INT32_MAX;
		while (++i <= all->ps.b[0])
		{
			find_better_rotation(all, &tmp_oprs, i);
			if (tmp_oprs.pa && tmp_oprs.count < oprs.count)
				ft_memcpy(&oprs, &tmp_oprs, sizeof(t_oprs));
		}
		solve_operations(all, oprs);
	}
	get_info(&info, all->ps.a);
	while (!is_sorted(all->ps.a))
	{
		if (info.min_adr > all->ps.a[0] / 2)
			make_cmd(all, RA);
		else
			make_cmd(all, RRA);
	}
}
