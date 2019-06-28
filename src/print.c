/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:14:58 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 02:10:11 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		count;

	count = 0;
	if (*lst)
	{
		tmp = *lst;
		mem = 0;
		while (tmp)
		{
			mem += tmp->content_size;
			tmp = tmp->next;
			count++;
		}
		if ((res = (char *)ft_strnew(sizeof(char) * mem)))
		{
			rewrite(lst, res, mem, (*lst)->content_size);
			ft_putstr(res);
			ft_strdel(&res);
		}
	}
	ft_printf("Operations: %d\n", count);
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
