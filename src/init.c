/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 01:29:14 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/14 21:41:59 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_arr_size(t_all *all, int ac, char **av, int i)
{
	size_t	j;
	int		size;

	size = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(ft_isint(av[i] + j)))
				push_swap_clear_exit(all, (all->prog == PUSH_SWAP) ? PS_ARG_ERR : CH_ARG_ERR);
			j += ft_intlen(ft_atoi(av[i] + j));
			while (av[i][j] && !ft_isdigit(av[i][j]))
				j++;
			size++;
		}
	}
	return (size);
}

static void	get_arr_from_args(t_all *all, int ac, char **av, int i)
{
	int		j;
	int		k;

	k = all->ps.a[0];
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			all->ps.a[k] = ft_atoi(av[i] + j);
			j += ft_intlen(all->ps.a[k]);
			while (av[i][j] && av[i][j] != '-'
			&& av[i][j] != '+' && !ft_isdigit(av[i][j]))
				j++;
			k--;
		}
	}
}

static void	read_args_to_array(t_all *all, int ac, char **av)
{
	size_t	i;
	int		size;
	int		arg_ofset;

	arg_ofset = ((int)all->ps.flag) ? 1 : 0;
	size = get_arr_size(all, ac, av, arg_ofset);
	all->ps.a = (int *)malloc(sizeof(int) * (size + 1));
	all->ps.b = (int *)malloc(sizeof(int) * (size + 1));
	if (!all->ps.a || !all->ps.b)
		push_swap_clear_exit(all, (all->prog == PUSH_SWAP)
		? PS_MEM_ERR : CH_MEM_ERR);
	all->ps.a[0] = size;
	all->ps.b[0] = 0;
	get_arr_from_args(all, ac, av, arg_ofset);
}

void		init(t_all *all, int ac, char **av)
{
	if (ac < 2)
	{
		(all->prog == PUSH_SWAP) ? ft_putendl(PS_USAGE)
		: ft_putendl(CH_USAGE);
		exit(EXIT_SUCCESS);
	}
	all->ps.flag = (av[1][0] == '-' && av[1][1]
	&& ft_isalpha(av[1][1])) ? av[1][1] : 0;
	all->ps.commands_count = 0;
	all->ps.point = 0;
	all->ps.a = NULL;
	all->ps.b = NULL;
	all->ps.lst = NULL;
	all->ps.cmds = NULL;
	all->mlx.ptr = NULL;
	all->mlx.win = NULL;
	all->mlx.a.ptr = NULL;
	all->mlx.b.ptr = NULL;
	all->ps.neibs = NULL;
	read_args_to_array(all, ac, av);
}
