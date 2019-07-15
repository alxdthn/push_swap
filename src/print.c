/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:14:58 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/15 21:48:47 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	rewrite(t_list **lst, char *res, size_t mem, size_t ofset)
{
	if ((*lst)->next)
		rewrite(&(*lst)->next, res, mem, ofset + (*lst)->next->content_size);
	ft_memcpy(res + (mem - ofset), (char *)(*lst)->content, (*lst)->content_size);
	ft_memdel((void **)&(*lst)->content);
	ft_memdel((void **)lst);
}

void		print_lst(t_list **lst)
{
	size_t	mem;
	t_list	*tmp;
	char	*res;

	if (*lst)
	{
		tmp = *lst;
		mem = 0;
		while (tmp)
		{
			mem += tmp->content_size;
			tmp = tmp->next;
		}
		if ((res = (char *)ft_strnew(sizeof(char) * mem)))
		{
			rewrite(lst, res, mem, (*lst)->content_size);
			ft_putstr(res);
			ft_strdel(&res);
		}
	}
}
*/

void	print_lst(t_list *lst)
{
	if (lst->next)
		print_lst (lst->next);
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
	size_t	len;

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
