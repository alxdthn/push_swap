/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_stack_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:13:26 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/14 20:15:23 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_cmd(t_all *all, char cmd)
{
	process_cmd(&all->ps, cmd);
	ft_lstadd(&all->ps.lst, ft_lstnew(&cmd, sizeof(char)));
	if (!all->ps.lst)
		push_swap_clear_exit(all, PS_MEM_ERR);
}

void	solve_operations(t_all *all, t_oprs oprs)
{
	while (oprs.rr--)
		make_cmd(all, RR);
	while (oprs.rrr--)
		make_cmd(all, RRR);
	while (oprs.ra--)
		make_cmd(all, RA);
	while (oprs.rb--)
		make_cmd(all, RB);
	while (oprs.rra--)
		make_cmd(all, RRA);
	while (oprs.rrb--)
		make_cmd(all, RRB);
	while (oprs.pa--)
		make_cmd(all, PA);
}

void get_double_rotation(int *a, int *b, int *rr)
{
	if (*a && *b)
	{
		while (*a && *b)
		{
			(*a)--;
			(*b)--;
			(*rr)++;
		}
	}
}

int get_rotation(int *r, int *rr, int size, int adr, int dir)
{
	if (adr)
	{
		if ((*r = size - adr + dir) > size / 2)
		{
			*rr = adr - dir;
			*r = 0;
		}
		return (1);
	}
	return (0);
}

void init_opers(t_oprs *oprs)
{
	oprs->ra = 0;
	oprs->rb = 0;
	oprs->rr = 0;
	oprs->rra = 0;
	oprs->rrb = 0;
	oprs->rrr = 0;
	oprs->pa = 0;
}