/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:06:49 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 20:02:34 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	auto_mode(t_all *all)
{
	if (!is_sorted(all->ps.a))
	{
		get_info(&all->ps.info, all->ps.a);
		all->ps.max_value = all->ps.info.max_value;
		all->ps.min_value = all->ps.info.min_value;
		insert_method(all);
	}
}

int			main(int ac, char **av)
{
	t_all	all;

	all.prog = PUSH_SWAP;
	init(&all, ac, av);
	all.is_print = 1;
	if (all.ps.flag == 'h')
		ft_putendl(SALUT);
	check_matches(&all);
	(all.ps.flag) ? handle_mode(&all) : auto_mode(&all);
	if (all.ps.flag && all.ps.lst)
		print_lst(all.ps.lst);
	push_swap_clear_exit(&all, NULL);
	return (0);
}
