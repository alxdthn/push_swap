/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 01:29:14 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/29 08:08:24 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack_from_all_args(t_all *all, int ac, char **av)
{
	size_t	i;

	i = 1 + ((all->ps.flag) ? 1 : 0);
	while (i < ac)
	{
		if (!ft_isint(av[i]))
			push_swap_clear_exit(all, (all->prog == PUSH_SWAP)
			? PS_ARG_ERR : CH_ARG_ERR);
		i++;
		all->ps.size++;
	}
	all->ps.a = (int *)malloc(sizeof(int) * (all->ps.size + 1));
	all->ps.b = (int *)malloc(sizeof(int) * (all->ps.size + 1));
	if (!all->ps.a || !all->ps.b)
		push_swap_clear_exit(all, (all->prog == PUSH_SWAP)
		? PS_MEM_ERR : CH_MEM_ERR);
	i = 1;
	while (ac > 1 + ((all->ps.flag) ? 1 : 0))
		all->ps.a[i++] = ft_atoi(av[ac-- - 1]);
}

static void	check_ints_from_one_arg(t_all *all, char *av)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (!ft_isint(av + i))
			push_swap_clear_exit(all, (all->prog == PUSH_SWAP)
			? PS_ARG_ERR : CH_ARG_ERR);
		i += ft_strclen(av + i, ' ');
		while (av[i] && av[i] == ' ')
			i++;
	}
}

static void	init_stack_from_one_arg(t_all *all, char *av)
{
	size_t	i;

	all->ps.size = ft_wrdcount(av, ' ');
	all->ps.a = (int *)malloc(sizeof(int) * (all->ps.size + 1));
	all->ps.b = (int *)malloc(sizeof(int) * (all->ps.size + 1));
	if (!all->ps.a || !all->ps.b)
		push_swap_clear_exit(all, (all->prog == PUSH_SWAP)
		? PS_MEM_ERR : CH_MEM_ERR);
	check_ints_from_one_arg(all, av);
	i = all->ps.size;
	while (*av)
	{
		all->ps.a[i--] = ft_atoi(av);
		av += ft_strclen(av, ' ');
		while (*av && *av == ' ')
			av++;
	}
}

void		init(t_all *all, int ac, char **av)
{
	if (ac < 2)
	{
		(all->prog == PUSH_SWAP) ? ft_puterr(1, PS_USAGE)
		: ft_puterr(1, CH_USAGE);
		exit(EXIT_FAILURE);
	}
	all->ps.flag = (av[1][0] == '-' && av[1][1]
	&& ft_isalpha(av[1][1])) ? av[1][1] : 0;
	all->ps.size = 0;
	all->ps.point = 0;
	all->ps.a = NULL;
	all->ps.b = NULL;
	all->ps.lst = NULL;
	all->ps.arr = NULL;
	all->mlx.ptr = NULL;
	all->mlx.win = NULL;
	all->mlx.a.ptr = NULL;
	all->mlx.b.ptr = NULL;
	if (ac == 2 + ((all->ps.flag) ? 1 : 0))
		init_stack_from_one_arg(all, av[1 + ((all->ps.flag) ? 1 : 0)]);
	else
		init_stack_from_all_args(all, ac, av);
	all->ps.a[0] = all->ps.size;
	all->ps.b[0] = 0;
}
