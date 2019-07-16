/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 01:29:14 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 20:10:50 by nalexand         ###   ########.fr       */
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
				push_swap_clear_exit(all, (all->prog == PUSH_SWAP)
				? PS_ARG_ERR : CH_ARG_ERR);
			j += ft_intlen(ft_atoi(av[i] + j));
			while (av[i][j] && av[i][j] == ' ')
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
	all->ps.size = all->ps.a[0];
}

static void	get_flag(t_all *all, char **av)
{
	all->ps.flag = 0;
	all->mlx.flag = 0;
	if (av[1][0] == '-' && av[1][1]
	&& ft_isalpha(av[1][1]))
	{
		if (ft_strequ(av[1], "-h") && all->prog == PUSH_SWAP)
			all->ps.flag = 1;
		else if (ft_strequ(av[1], "-v") && all->prog == CHECKER)
			all->ps.flag = 1;
		else if (ft_strequ(av[1], "-vrus") && all->prog == CHECKER)
		{
			all->mlx.flag = 1;
			all->ps.flag = 1;
		}
		else
		{
			push_swap_clear_exit(all, (all->prog == PUSH_SWAP)
			? PS_FLAG_ERR : CH_FLAG_ERR);
		}
	}
}

void		init(t_all *all, int ac, char **av)
{
	if (ac < 2)
	{
		(all->prog == PUSH_SWAP) ? ft_putendl(PS_USAGE)
		: ft_putendl(CH_USAGE);
		exit(EXIT_SUCCESS);
	}
	get_flag(all, av);
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
	all->ps.marks = NULL;
	read_args_to_array(all, ac, av);
}
