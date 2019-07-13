/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 06:41:10 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/13 20:03:44 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_back(char *res, char cmd)
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

int		deal_key(int key, t_all *all)
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

int		loop_hook(t_all *all)
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
		process_cmd(&all->ps, cmd);
		render(&all->ps, &all->mlx, cmd);
	}
	return (0);
}

int		key_press(int key, t_all *all)
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
		if (cmd)
		{
			process_cmd(&all->ps, cmd);
			render(&all->ps, &all->mlx, cmd);
		}
		//ft_printf("point: %d\ncmd: %s\n", all->ps.point, tmp);
		all->mlx.working = 0;
	}
	return (0);
}

static void		put_line(int value, t_mlx *mlx, ssize_t *i, int color, int *data)
{
	size_t	tmp_width;
	size_t	box;
	size_t	x;
	ssize_t	ofset;
	int		line_color;

	box = mlx->a.size_line * mlx->elem_height;
	line_color = (value >= 0) ? POS_LINE_COLOR : NEG_LINE_COLOR;
	x = 0;
	while (*i >= 0 && box)
	{
		if (!x)
		{
			tmp_width = mlx->elem_width * ABS(value);
			ofset = (mlx->a.size_line - tmp_width) / 2 + 0.5;
			x = mlx->a.size_line;
		}
		if (tmp_width && ofset <= 0)
		{
			data[(*i)--] = line_color;
			tmp_width--;
		}
		else
		{
			data[(*i)--] = color;
			ofset--;
		}
		x--;
		box--;
	}
}

void	render(t_ps *ps, t_mlx *mlx, char cmd)
{
	ssize_t	i;
	int		j;

	if (cmd > 9 || cmd == SA || cmd == RA || cmd == RRA)
	{
		j = 0;
		i = mlx->a.size_line * mlx->height - 1;
		while (i >= 0)
			put_line((j < ps->a[0]) ? ps->a[j++ + 1] : 0, mlx, &i, LEFT_BACKGROUND, mlx->a.data);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->a.ptr, 0, 0);
	}
	if (cmd > 9 || cmd == SB || cmd == RB || cmd == RRB)
	{
		j = 0;
		i = mlx->b.size_line * mlx->height - 1;
		while (i >= 0)
			put_line((j < ps->b[0]) ? ps->b[j++ + 1] : 0, mlx, &i, RIGHT_BACKGROUND, mlx->b.data);		
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->b.ptr, mlx->width / 2, 0);
	}
}

void		visualisation_init(t_all *all)
{
	t_info	info;

	all->mlx.working = 0;
	all->mlx.dir = 1;
	all->mlx.width = 2560;
	all->mlx.height = 1314;
	all->mlx.ptr = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.ptr,
	all->mlx.width, all->mlx.height, "push_swap by nalexand");
	all->mlx.a.ptr = mlx_new_image(all->mlx.ptr, all->mlx.width / 2, all->mlx.height);
	all->mlx.a.data = (int *)mlx_get_data_addr(all->mlx.a.ptr,
	&all->mlx.a.bpp, &all->mlx.a.size_line, &all->mlx.a.endian);
	all->mlx.a.size_line /= 4;
	all->mlx.b.ptr = mlx_new_image(all->mlx.ptr, all->mlx.width / 2, all->mlx.height);
	all->mlx.b.data = (int *)mlx_get_data_addr(all->mlx.b.ptr,
	&all->mlx.b.bpp, &all->mlx.b.size_line, &all->mlx.b.endian);
	all->mlx.b.size_line /= 4;
	mlx_key_hook(all->mlx.win, deal_key, all);
	mlx_loop_hook(all->mlx.ptr, loop_hook, all);
	mlx_hook(all->mlx.win, 2, 0, key_press, all);
	get_info(&info, all->ps.a);
	all->mlx.elem_height = (double)all->mlx.height / (double)all->ps.a[0] + 0.5;
	if (all->mlx.elem_height * all->ps.a[0] > all->mlx.height)
		all->mlx.elem_height -= 1; 
	all->mlx.elem_width = (double)all->mlx.a.size_line / (double)info.max_value + 0.5;
	if (all->mlx.elem_width * info.max_value > all->mlx.a.size_line)
		all->mlx.elem_width--;
}
