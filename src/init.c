/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 01:29:14 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 04:58:28 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		init_stack_from_all_args(t_ps *ps, int ac, char **av)
{
	size_t	i;

	i = 1 + ps->flag;
	while (i < ac)
	{
		if (!ft_isint(av[i]))
			return (ft_puterr(1, "Invalid argument!\n"));
		i++;
		ps->size++;
	}
	ps->a = (int *)malloc(sizeof(int) * (ps->size + 1));
	ps->b = (int *)malloc(sizeof(int) * (ps->size + 1));
	if (!ps->a || !ps->b)
		push_swap_clear_exit(ps);
	ps->a[0] = ps->size;
	ps->b[0] = 0;
	i = 1;
	while (ac > 1 + ps->flag)
		ps->a[i++] = ft_atoi(av[ac-- - 1]);
	return (0);
}

int		init_stack_from_one_arg(t_ps *ps, char *av)
{
	size_t	i;

	i = 0;
	ps->size = ft_wrdcount(av, ' ');
	ps->a = (int *)malloc(sizeof(int) * (ps->size + 1));
	ps->b = (int *)malloc(sizeof(int) * (ps->size + 1));
	if (!ps->a || !ps->b)
		push_swap_clear_exit(ps);
	ps->a[0] = ps->size;
	ps->b[0] = 0;
	while (av[i])
	{
		if (!ft_isint(av + i))
			return (ft_puterr(1, "Invalid argument!\n"));
		i += ft_strclen(av + i, ' ');
		while (av[i] && av[i] == ' ')
			i++;
	}
	i = ps->size;
	while (*av)
	{
		ps->a[i--] = ft_atoi(av);
		av += ft_strclen(av, ' ');
		while (*av && *av == ' ')
			av++;
	}
	return (0);
}

int		init(t_ps *ps, int ac, char **av)
{
	if (ac < 2)
		return (ft_puterr(1, USAGE));
	ps->flag = (ft_strnequ(av[1], "-h", 3))
	? ft_puterr(1, "Welcome to handle mode!\n") : 0;
	ps->size = 0;
	ps->a = NULL;
	ps->b = NULL;
	ps->lst = NULL;
	if (ac == 2 + ps->flag)
		return (init_stack_from_one_arg(ps, av[1 + ps->flag]));
	return (init_stack_from_all_args(ps, ac, av));
}
