/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_clear_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 05:23:01 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/19 16:22:17 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_clear_exit(t_all *all, char *message)
{
	free(all->ps.a);
	free(all->ps.b);
	free(all->ps.cmds);
	ft_arraydel((void ***)&all->ps.marks);
	ft_lstdel(&all->ps.lst, ft_lstclear);
	free(all->mlx.ptr);
	if (message)
		ft_putendl_fd(message, 2);
	exit(0);
}
