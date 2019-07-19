/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:14:58 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 16:47:24 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_list *lst)
{
	if (lst->next)
		print_lst(lst->next);
	if (*(char *)lst->content == PA)
		write(1, "pa\n", 3);
	else if (*(char *)lst->content == PB)
		write(1, "pb\n", 3);
	else if (*(char *)lst->content == SA)
		write(1, "sa\n", 3);
	else if (*(char *)lst->content == SB)
		write(1, "sb\n", 3);
	else if (*(char *)lst->content == RA)
		write(1, "ra\n", 3);
	else if (*(char *)lst->content == RB)
		write(1, "rb\n", 3);
	else if (*(char *)lst->content == RRA)
		write(1, "rra\n", 4);
	else if (*(char *)lst->content == RRB)
		write(1, "rrb\n", 4);
	else if (*(char *)lst->content == SS)
		write(1, "ss\n", 3);
	else if (*(char *)lst->content == RR)
		write(1, "rr\n", 3);
	else if (*(char *)lst->content == RRR)
		write(1, "rrr\n", 4);
}

void	print_arr(int *a, int *b)
{
	size_t	i;
	size_t	j;
	int		len;

	i = a[0];
	j = b[0];
	len = (a[0] >= b[0]) ? a[0] : b[0];
	ft_putstr("----------------------------------\n");
	while (len)
	{
		(len > a[0]) ? ft_printf("%-12c", ' ') : ft_printf("%-12d", a[i--]);
		(len > b[0]) ? ft_printf("%-12c", ' ') : ft_printf("%-12d", b[j--]);
		ft_putchar('\n');
		len--;
	}
	ft_printf("%-12c%-12c\n%-12c%-12c\n", '-', '-', 'A', 'B');
	ft_putstr("----------------------------------\n");
}
