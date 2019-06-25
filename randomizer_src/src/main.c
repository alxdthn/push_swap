/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:15:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/25 17:11:15 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_match(t_list *values, int value)
{
	while (values)
	{
		if (*(int *)values->content == value)
			return (0);
		values = values->next;
	}
	return (1);
}

static int	check_arg(char *av)
{
	size_t		i;

	i = 0;
	while (av[i])
	{
		if (!(ft_isdigit(av[i])) && av[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

static int	validation(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr("usage: randomizer min_value max_value\n");
		return (1);
	}
	if (check_arg(av[1]))
	{
		ft_putstr("min_value is not valid\n");
		return (1);
	}
	if (check_arg(av[2]))
	{
		ft_putstr("max_value is not valid\n");
		return (1);
	}
	return (0);
}

static void	randomize(t_list **values, int min, int max)
{
	size_t		i;
	int			size;
	int			value;

	srand(time(NULL));
	size = max - min;
	i = 0;
	while (i < size)
	{
		value = min + rand() % size;
		if (check_match(*values, value))
		{
			ft_lstadd(values, ft_lstnew(&value, sizeof(int)));
			if (!(*values))
			{
				ft_lstdel(values, ft_lstclear);
				ft_putstr("memory for list is not alocated\n");
				exit(EXIT_FAILURE);		
			}
			i++;
		}
	}
}

int			main(int ac, char **av)
{
	t_list		*values;
	t_list		*tmp;
	int			min;
	int			max;

	if (validation(ac, av))
		return (0);
	min = ft_atoi(av[1]);
	max = ft_atoi(av[2]);
	values = NULL;
	randomize(&values, min, max);
	tmp = values;
	while (tmp)
	{
		ft_printf("%d", *(int *)tmp->content);
		if (tmp->next)
			ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
	ft_lstdel(&values, ft_lstclear);
	return (0);
}
