/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:46:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 14:56:07 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_cmd_p2(t_all *all, char cmd)
{
	if (cmd == SS)
	{
		swap(all->ps.a, 0, 0);
		swap(all->ps.b, cmd, all->is_print);
	}
	else if (cmd == RR)
	{
		rotate(all->ps.a, 1, 0, 0);
		rotate(all->ps.b, 1, cmd, all->is_print);
	}
	else if (cmd == RRR)
	{
		rotate(all->ps.a, -1, 0, 0);
		rotate(all->ps.b, -1, cmd, all->is_print);
	}
}

void		make_cmd(t_all *all, char cmd)
{
	if (cmd == PA)
		push(all->ps.b, all->ps.a, cmd, all->is_print);
	else if (cmd == PB)
		push(all->ps.a, all->ps.b, cmd, all->is_print);
	else if (cmd == SA)
		swap(all->ps.a, cmd, all->is_print);
	else if (cmd == SB)
		swap(all->ps.b, cmd, all->is_print);
	else if (cmd == RA)
		rotate(all->ps.a, 1, cmd, all->is_print);
	else if (cmd == RB)
		rotate(all->ps.b, 1, cmd, all->is_print);
	else if (cmd == RRA)
		rotate(all->ps.a, -1, cmd, all->is_print);
	else if (cmd == RRB)
		rotate(all->ps.b, -1, cmd, all->is_print);
	else
		make_cmd_p2(all, cmd);
}
