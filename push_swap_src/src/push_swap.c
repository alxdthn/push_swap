/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:06:49 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 05:23:13 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validation(int ac, char **av, char *flag)
{
	if (ft_strnequ(av[1], "-h", 3))
	{
		ft_putstr("Welcome to handle mode!w\n");
		*flag = 1;
		ac -= 1;
	}
	if (ac < 2)
	{
		ft_putstr("usage: push_swap [-h] int_values...\n");
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		*a;
	int		*b;
	char	flag;

	a = NULL;
	b = NULL;
	if (validation(ac, av, &flag))
		return (1);
	if (flag)
		handle_mode(&a, &b, ac, av);
	else
		auto_mode(&a, &b, ac, av);
	ft_memdel((void **)&a);
	ft_memdel((void **)&b);
	return (0);
}
