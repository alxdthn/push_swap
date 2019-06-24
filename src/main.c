/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:15:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/24 22:26:47 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_match(t_list *values, int value)
{
	while (values)
	{
		if (*(int *)values->content == value)
			return (0);
		values = values->next;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_list		*values;
	size_t		i;
	int			value;
	int			min;
	int			max;
	int			size;

	if (ac != 3)
	{
		ft_putstr("usage: randomizer min_value max_value\n");
		return (0);
	}
	min = ft_atoi(av[1]);
	max = ft_atoi(av[2]);
	size = max - min;
	srand(time(NULL));
	values = NULL;
	i = 0;
	while (i < size)
	{
		value = rand() % max - min;
		if (check_match(values, value))
		{
			ft_lstadd(&values, ft_lstnew(&value, sizeof(int)));
			i++;
		}
	}
	while (values)
	{
		ft_printf("%d", *(int *)values->content);
		if (values->next)
			ft_putchar(' ');
		values = values->next;
	}
	return (0);
}
