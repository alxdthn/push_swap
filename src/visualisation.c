/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 06:41:10 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 16:11:25 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mlx_init_params(t_all *all)
{
	all->mlx.working = 0;
	all->mlx.dir = 1;
	all->mlx.width = 2560;
	all->mlx.height = 1314;
	all->mlx.ptr = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.ptr,
	all->mlx.width, all->mlx.height, "push_swap by nalexand");
	all->mlx.a.ptr = mlx_new_image(all->mlx.ptr,
	all->mlx.width / 2, all->mlx.height);
	all->mlx.a.data = (int *)mlx_get_data_addr(all->mlx.a.ptr,
	&all->mlx.a.bpp, &all->mlx.a.size_line, &all->mlx.a.endian);
	all->mlx.a.size_line /= 4;
	all->mlx.b.ptr = mlx_new_image(all->mlx.ptr,
	all->mlx.width / 2, all->mlx.height);
	all->mlx.b.data = (int *)mlx_get_data_addr(all->mlx.b.ptr,
	&all->mlx.b.bpp, &all->mlx.b.size_line, &all->mlx.b.endian);
	all->mlx.b.size_line /= 4;
}

void		visualisation_init(t_all *all)
{
	t_info	info;

	mlx_init_params(all);
	mlx_key_hook(all->mlx.win, deal_key, all);
	mlx_loop_hook(all->mlx.ptr, loop_hook, all);
	mlx_hook(all->mlx.win, 2, 0, key_press, all);
	get_info(&info, all->ps.a);
	if (all->ps.flag && all->ps.a[0] > 1275)
		push_swap_clear_exit(all,
		"checker: For visualisation mode maximum 1275 values");
	all->mlx.elem_height = (double)all->mlx.height
	/ (double)all->ps.a[0] + 0.5;
	if (all->mlx.elem_height * all->ps.a[0] > all->mlx.height)
		all->mlx.elem_height -= 1;
	all->mlx.elem_width = (double)all->mlx.a.size_line
	/ (double)info.max_value + 0.5;
	if (all->mlx.elem_width * info.max_value > all->mlx.a.size_line)
		all->mlx.elem_width--;
}
