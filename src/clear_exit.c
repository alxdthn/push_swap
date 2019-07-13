/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 05:23:01 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/13 19:12:43 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_clear_exit(t_all *all, char *message)
{
	free(all->ps.a);
	free(all->ps.b);
	free(all->ps.cmds);
	ft_arraydel((void ***)&all->ps.neibs);
	ft_lstdel(&all->ps.lst, ft_lstclear);
	if (all->mlx.ptr)
	{
		if (all->mlx.a.ptr)
			mlx_destroy_image(all->mlx.ptr, all->mlx.a.ptr);
		if (all->mlx.b.ptr)
			mlx_destroy_image(all->mlx.ptr, all->mlx.b.ptr);
		mlx_destroy_window(all->mlx.ptr, all->mlx.win);
	}
	if (message)
		ft_putendl_fd(message, 2);
	exit(0);
}
