/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:29:04 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 05:29:55 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_arr(int **a, int **b)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = (*a)[0];
	j = (*b)[0];
	len = ((*a)[0] >= (*b)[0]) ? (*a)[0] : (*b)[0];
	ft_putstr("----------------------------------\n");
	while (len)
	{
		(len > (*a)[0]) ? ft_printf("%-5c", ' ') : ft_printf("%-5d", (*a)[i--]);
		(len > (*b)[0]) ? ft_printf("%-5c", ' ') : ft_printf("%-5d", (*b)[j--]);
		ft_putchar('\n');
		len--;
	}
	ft_printf("%-5c%-5c\n%-5c%-5c\n", '-', '-', 'A', 'B');
	ft_putstr("----------------------------------\n");
}

static void	handle_init(int **a, int **b, int ac, char **av)
{
	size_t	i;
	size_t	size;

	size = ac - 2;
	if (!(*a = (int *)malloc(sizeof(int) * (size + 1))))
		return ;
	if (!(*b = (int *)malloc(sizeof(int) * (size + 1))))
		return ;
	(*a)[0] = size;
	(*b)[0] = 0;
	i = 1;
	while (i <= (*a)[0])
		(*a)[i++] = ft_atoi(av[ac-- - 1]);
}

void		handle_mode(int **a, int **b, int ac, char **av)
{
	char	*cmd;

	handle_init(a, b, ac, av);
	if (!a && !b)
		push_swap_clear_exit(a, b);
	cmd = NULL;
	print_arr(a, b);
	while (get_next_line(0, &cmd) > 0)
	{
		if (process_cmd(a, b, &cmd))
			break ;
		print_arr(a, b);
	}
}
