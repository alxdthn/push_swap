/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:15:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/29 04:47:00 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		put_line(int value, t_mlx *mlx, ssize_t *i, int color, int *data)
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

static void	render(t_ps *ps, t_mlx *mlx, int cmd)
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

int		deal_key(int key, t_all *all)
{
	char	*cmd;

	if (key == ESC)
	{
		ft_memdel((void **)&all->ps.a);
		ft_memdel((void **)&all->ps.b);
		exit(0);
	}
	return (0);
}

int		loop_hook(t_all *all)
{
	t_list	*tmp;
	int		cmd;

	if (all->ps.lst)
	{
		if (!(cmd = process_cmd(&all->ps, (char *)all->ps.lst->content)))
		{
			ft_lstdel(&all->ps.lst, ft_lstclear);
			return (0);
		}
		render(&all->ps, &all->mlx, cmd);
		tmp = all->ps.lst->next;
		ft_lstdelone(&all->ps.lst, ft_lstclear);
		all->ps.lst = tmp;
	}
	return (0);
}

void		visualisation_init(t_all *all)
{
	t_info	info;

	all->mlx.time = 0;
	all->mlx.width = 2000;
	all->mlx.height = 1000;
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
	get_info(&info, all->ps.a);
	all->mlx.elem_height = (double)all->mlx.height / (double)all->ps.a[0] + 0.5;
	all->mlx.elem_width = (double)all->mlx.a.size_line / (double)info.max_value + 0.5;
}

static void	check_mode(t_ps *ps)
{
	t_list	*tmp;
	int		count;

	count = 0;
	while (ps->lst)
	{
		if (!process_cmd(ps, (char *)ps->lst->content))
		{
			ft_lstdel(&ps->lst, ft_lstclear);
			return ;
		}
		tmp = ps->lst->next;
		ft_lstdelone(&ps->lst, ft_lstclear);
		ps->lst = tmp;
		count++;
	}
	if (!ps->b[0] && is_sorted(ps->a))
		ft_printf("%{gre}s\nOperations: %d\n", "OK", count);
	else
		ft_printf("%{red}s\nOperations: %d\n", "KO", count);
}

void		ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while ((*alst)->next)
		*alst = (*alst)->next;
	(*alst)->next = new;
	*alst = tmp;
}

int			main(int ac, char **av)
{
	t_all	all;
	char	*cmd;

	if (init(&all.ps, ac, av, CH_USAGE))
		return (1);
	while (get_next_line(0, &cmd) > 0)
	{
		ft_lstpushback(&all.ps.lst, ft_lstnew(cmd, ft_strlen(cmd)));
		ft_strdel(&cmd);
	}
	if (all.ps.flag)
	{
		if (all.ps.flag == 'v')
		{
			visualisation_init(&all);
			render(&all.ps, &all.mlx, START);
			mlx_loop(&all.mlx.ptr);
		}
		else
			all.ps.flag = ft_puterr(0, "checker: Unknown flag\n");
	}
	if (check_matches(all.ps.a))
		check_mode(&all.ps);
	return (0);
}
