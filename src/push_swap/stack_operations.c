/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:13:26 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/19 17:46:52 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	get_double_rotation(int *a, int *b, int *rr)
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

int		get_rotation(int *r, int *rr, int size, int adr)
{
	if (adr)
	{
		if ((*r = size - adr) > size / 2)
		{
			*rr = adr;
			*r = 0;
		}
		return (1);
	}
	return (0);
}
