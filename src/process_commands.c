/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:46:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/15 22:13:33 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_cmd(int ret, int cmd)
{
	if (cmd == PA)
		write(1, "pa\n", 3);
	else if (cmd == PB)
		write(1, "pb\n", 3);
	else if (cmd == SA)
		write(1, "sa\n", 3);
	else if (cmd == SB)
		write(1, "sb\n", 3);
	else if (cmd == RA)
		write(1, "ra\n", 3);
	else if (cmd == RB)
		write(1, "rb\n", 3);
	else if (cmd == RRA)
		write(1, "rra\n", 4);
	else if (cmd == RRB)
		write(1, "rrb\n", 4);
	else if (cmd == SS)
		write(1, "ss\n", 3);
	else if (cmd == RR)
		write(1, "rr\n", 3);
	else if (cmd == RRR)
		write(1, "rrr\n", 4);
}

static void	make_cmd_p2(t_all *all, char cmd)
{
	if (cmd == SS)
	{
		swap(all->ps.a);
		write_cmd(swap(all->ps.b), SS);
	}
	else if (cmd == RR)
	{
		rotate(all->ps.a, 1);
		write_cmd(rotate(all->ps.b, 1), RR);
	}
	else if (cmd == RRR)
	{
		rotate(all->ps.a, -1);
		write_cmd(rotate(all->ps.b, -1), RRR);
	}
}

void		make_cmd(t_all *all, char cmd)
{
	if (cmd == PA)
		write_cmd(push(all->ps.b, all->ps.a), PA);
	else if (cmd == PB)
		write_cmd(push(all->ps.a, all->ps.b), PB);
	else if (cmd == SA)
		write_cmd(swap(all->ps.a), SA);
	else if (cmd == SB)
		write_cmd(swap(all->ps.b), SB);
	else if (cmd == RA)
		write_cmd(rotate(all->ps.a, 1), RA);
	else if (cmd == RB)
		write_cmd(rotate(all->ps.b, 1), RB);
	else if (cmd == RRA)
		write_cmd(rotate(all->ps.a, -1), RRA);
	else if (cmd == RRB)
		write_cmd(rotate(all->ps.b, -1), RRB);
	else
		make_cmd_p2(all, cmd);
}
