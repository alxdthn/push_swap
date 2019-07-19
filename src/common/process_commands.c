/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:46:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/19 17:49:45 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_cmd_p2(t_all *all, char cmd)
{
	if (cmd == SS)
	{
		swap(all->ps.a, 0, 0);
		swap(all->ps.b, cmd, all->u.flags.print_cmds);
	}
	else if (cmd == RR)
	{
		rotate(all->ps.a, 1, 0, 0);
		rotate(all->ps.b, 1, cmd, all->u.flags.print_cmds);
	}
	else if (cmd == RRR)
	{
		rotate(all->ps.a, -1, 0, 0);
		rotate(all->ps.b, -1, cmd, all->u.flags.print_cmds);
	}
}

void		make_cmd(t_all *all, char cmd)
{
	if (cmd == PA)
		push(all->ps.b, all->ps.a, cmd, all->u.flags.print_cmds);
	else if (cmd == PB)
		push(all->ps.a, all->ps.b, cmd, all->u.flags.print_cmds);
	else if (cmd == SA)
		swap(all->ps.a, cmd, all->u.flags.print_cmds);
	else if (cmd == SB)
		swap(all->ps.b, cmd, all->u.flags.print_cmds);
	else if (cmd == RA)
		rotate(all->ps.a, 1, cmd, all->u.flags.print_cmds);
	else if (cmd == RB)
		rotate(all->ps.b, 1, cmd, all->u.flags.print_cmds);
	else if (cmd == RRA)
		rotate(all->ps.a, -1, cmd, all->u.flags.print_cmds);
	else if (cmd == RRB)
		rotate(all->ps.b, -1, cmd, all->u.flags.print_cmds);
	else
		make_cmd_p2(all, cmd);
}
