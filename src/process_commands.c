/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:46:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/13 21:27:57 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		process_cmd_p2(t_ps *ps, char cmd)
{
	if (cmd == SS)
	{
		swap(ps->a);
		swap(ps->b);
	}
	else if (cmd == RR)
	{
		rotate(ps->a, 1);
		rotate(ps->b, 1);
	}
	else if (cmd == RRR)
	{
		rotate(ps->a, -1);
		rotate(ps->b, -1);
	}
}

void		process_cmd(t_ps *ps, char cmd)
{
	if (cmd == PA)
		push(ps->b, ps->a);
	else if (cmd == PB)
		push(ps->a, ps->b);
	else if (cmd == SA)
		swap(ps->a);
	else if (cmd == SB)
		swap(ps->b);
	else if (cmd == RA)
		rotate(ps->a, 1);
	else if (cmd == RB)
		rotate(ps->b, 1);
	else if (cmd == RRA)
		rotate(ps->a, -1);
	else if (cmd == RRB)
		rotate(ps->b, -1);
	else
		process_cmd_p2(ps, cmd);
}
