/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 01:29:14 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/19 17:44:19 by nalexand         ###   ########.fr       */
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
				all->exit_function(all, ERROR);
			ft_satoi(av[i], &j);
			while (av[i][j] && av[i][j] == ' ')
				j++;
			size++;
		}
	}
	return (size);
}

static void	get_arr_from_args(t_all *all, int ac, char **av, int i)
{
	size_t	j;
	int		k;

	k = all->ps.a[0];
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			all->ps.a[k] = ft_satoi(av[i], &j);
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

	arg_ofset = (all->u.is_flag) ? 1 : 0;
	if (arg_ofset && ac == 2)
		all->exit_function(all, NULL);
	size = get_arr_size(all, ac, av, arg_ofset);
	all->ps.a = (int *)malloc(sizeof(int) * (size + 1));
	all->ps.b = (int *)malloc(sizeof(int) * (size + 1));
	if (!all->ps.a || !all->ps.b)
		all->exit_function(all, ERROR);
	all->ps.a[0] = size;
	all->ps.b[0] = 0;
	get_arr_from_args(all, ac, av, arg_ofset);
	all->ps.size = all->ps.a[0];
}

static void	get_flag(t_all *all, char **av)
{
	if (av[1][0] == '-' && av[1][1]
	&& ft_isalpha(av[1][1]))
	{
		if (ft_strnequ(av[1], "-h", 3) && all->prog == PUSH_SWAP)
			all->u.flags.handle = 1;
		else if (ft_strnequ(av[1], "-v", 3) && all->prog == CHECKER)
			all->u.flags.visu = 1;
		else if (ft_strnequ(av[1], "-vrus", 6) && all->prog == CHECKER)
		{
			all->u.flags.visu = 1;
			all->u.flags.rus = 1;
		}
		else if (ft_strnequ(av[1], "-g", 3) && all->prog == CHECKER)
			all->u.flags.good_out = 1;
		else
			all->exit_function(all, ERROR);
	}
}

void		init(t_all *all, int ac, char **av)
{
	if (ac < 2)
	{
		(all->prog == PUSH_SWAP) ? ft_putendl(PS_USAGE)
		: ft_putendl(CH_USAGE);
		exit(EXIT_FAILURE);
	}
	get_flag(all, av);
	read_args_to_array(all, ac, av);
}
