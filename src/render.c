/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:13:55 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/18 18:56:09 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_box(t_all *all, int value)
{
	all->mlx.line_box_size = all->mlx.a.size_line * all->mlx.elem_height;
	all->mlx.line_box_width = all->mlx.elem_width * ABS(value);
	all->mlx.ofset = (all->mlx.a.size_line - all->mlx.line_box_width) / 2 + 0.5;
	if (value && all->mlx.flag)
		all->mlx.line_color = get_value_mark(all->ps.marks, value).color;
	else
		all->mlx.line_color = (value > 0) ? POS_LINE_COLOR : NEG_LINE_COLOR;
}

static void	put_box(t_all *all, int value, ssize_t *i, int *data)
{
	size_t	tmp_width;
	size_t	x;
	ssize_t	ofset;

	x = 0;
	init_box(all, value);
	while (*i >= 0 && all->mlx.line_box_size--)
	{
		if (!x)
		{
			tmp_width = all->mlx.line_box_width;
			ofset = all->mlx.ofset;
			x = all->mlx.a.size_line;
		}
		if (tmp_width && --ofset <= 0)
		{
			data[(*i)--] = all->mlx.line_color;
			tmp_width--;
		}
		else
			data[(*i)--] = all->mlx.bckg_color;
		--x;
	}
}

static void	put_logo(t_all *all)
{
	if (all->mlx.logo.ptr)
		mlx_put_image_to_window(all->mlx.ptr,
		all->mlx.win, all->mlx.logo.ptr, 10, 10);
}

void		render(t_all *all, char cmd)
{
	ssize_t	i;
	int		j;

	if ((cmd > 9 || cmd == SA || cmd == RA || cmd == RRA) && !(j = 0))
	{
		i = all->mlx.a.size_line * all->mlx.height - 1;
		all->mlx.bckg_color = LEFT_BACKGROUND;
		while (i >= 0)
			put_box(all, (j < all->ps.a[0])
			? all->ps.a[++j] : 0, &i, all->mlx.a.data);
		mlx_put_image_to_window(all->mlx.ptr,
		all->mlx.win, all->mlx.a.ptr, 0, 0);
	}
	if ((cmd > 9 || cmd == SB || cmd == RB || cmd == RRB) && !(j = 0))
	{
		i = all->mlx.b.size_line * all->mlx.height - 1;
		all->mlx.bckg_color = RIGHT_BACKGROUND;
		while (i >= 0)
			put_box(all, (j < all->ps.b[0])
			? all->ps.b[++j] : 0, &i, all->mlx.b.data);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win,
		all->mlx.b.ptr, all->mlx.width / 2, 0);
	}
	put_logo(all);
}
