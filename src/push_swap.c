/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:06:49 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 02:09:54 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_ps	ps;

	if (init(&ps, ac, av))
		return (1);
	if (check_matches(ps.a))
		(ps.flag) ? handle_mode(&ps) : auto_mode(&ps);
	print_lst(&ps.lst);
	print_arr(ps.a, ps.b);
	ft_memdel((void **)&ps.a);
	ft_memdel((void **)&ps.b);
	return (0);
}
