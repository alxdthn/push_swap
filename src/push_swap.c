/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:06:49 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/19 18:02:18 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	auto_mode(t_all *all)
{
	int		*tmp_arr;

	if (!is_sorted(all->ps.a))
	{
		tmp_arr = get_presorted_arr(all, all->ps.a);
		init_marks_arr(all, tmp_arr);
		set_marks(all->ps.marks, tmp_arr[0]);
		ft_memdel((void **)&tmp_arr);
		get_info(&all->ps.info, all->ps.a);
		all->ps.max_value = all->ps.info.max_value;
		all->ps.min_value = all->ps.info.min_value;
		insert_method(all);
	}
}

int			main(int ac, char **av)
{
	t_all	all;

	ft_bzero(&all, sizeof(t_all));
	all.exit_function = &push_swap_clear_exit;
	all.prog = PUSH_SWAP;
	init(&all, ac, av);
	all.u.flags.print_cmds = 1;
	check_matches(&all);
	(all.u.flags.handle) ? handle_mode(&all) : auto_mode(&all);
	if (all.u.flags.handle && all.ps.lst)
		print_lst(all.ps.lst);
	all.exit_function(&all, NULL);
	return (0);
}
