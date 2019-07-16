/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:11:09 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 15:45:48 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_back(char *res, char cmd)
{
	if (cmd == PA)
		*res = PB;
	else if (cmd == PB)
		*res = PA;
	else if (cmd == RA)
		*res = RRA;
	else if (cmd == RB)
		*res = RRB;
	else if (cmd == RRA)
		*res = RA;
	else if (cmd == RRB)
		*res = RB;
	else if (cmd == RRR)
		*res = RR;
	else if (cmd == RR)
		*res = RRR;
	else if (cmd == SA || cmd == SB || cmd == SS)
		*res = cmd;
}

int			deal_key(int key, t_all *all)
{
	char	*cmd;

	if (key == ESC)
		push_swap_clear_exit(all, NULL);
	else if (key == ENTER)
		all->mlx.working = (all->mlx.working) ? 0 : 1;
	else if (key == UP)
		all->mlx.dir = 1;
	else if (key == DOWN)
		all->mlx.dir = 0;
	return (0);
}

int			loop_hook(t_all *all)
{
	char	cmd;

	if (!all->mlx.working)
		return (0);
	if (all->mlx.dir && all->ps.cmds[all->ps.point])
		cmd = all->ps.cmds[all->ps.point++];
	else if (!all->mlx.dir && all->ps.point)
		get_back(&cmd, all->ps.cmds[all->ps.point-- - 1]);
	if (cmd)
	{
		make_cmd(all, cmd);
		render(all, cmd);
	}
	return (0);
}

int			key_press(int key, t_all *all)
{
	char	cmd;

	cmd = all->ps.cmds[all->ps.point];
	if (key == RIGHT || key == LEFT)
	{
		if (key == RIGHT)
		{
			if (!cmd)
				return (0);
			all->ps.point++;
		}
		else
		{
			if (all->ps.point == 0)
				return (0);
			get_back(&cmd, all->ps.cmds[all->ps.point - 1]);
			all->ps.point--;
		}
		make_cmd(all, cmd);
		render(all, cmd);
		all->mlx.working = 0;
	}
	return (0);
}
