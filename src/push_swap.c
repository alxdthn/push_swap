/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:06:49 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/15 16:20:06 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	auto_mode(t_all *all)
{
	if (!is_sorted(all->ps.a))
	{
		insert_method(all);
	}
}

int		main(int ac, char **av)
{
	t_all	all;

	all.prog = PUSH_SWAP;
	init(&all, ac, av);

/*
	t_info info;
	get_info(&info, all.ps.a);
	ft_printf("%d\n", is_loop_sorted(all.ps.a, info.min_adr));
*/

	if (all.ps.flag == 'h')
		ft_putendl(SALUT);
	else if (all.ps.flag && all.ps.flag != 'h')
		all.ps.flag = ft_puterr(0, PS_FLAG_ERR);
	check_matches(&all);
	(all.ps.flag) ? handle_mode(&all) : auto_mode(&all);
	if (all.ps.lst)
		print_lst(all.ps.lst);
	push_swap_clear_exit(&all, NULL);

	return (0);
}
