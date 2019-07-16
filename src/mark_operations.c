/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:44:40 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 16:51:42 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_value_adr(int *arr, int value)
{
	int		adr;

	adr = 1;
	while (adr <= arr[0])
	{
		if (arr[adr] == value)
			return (adr);
		adr++;
	}
	return (0);
}

static void	sort(int *arr)
{
	int		i;
	int		tmp;

	i = 1;
	while (i < arr[0])
	{
		if (arr[i] < arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 1;
			continue ;
		}
		i++;
	}
}

static void	set_color(int size, int *color, int i)
{
	int		delta;

	delta = size / 3;
	if (i < delta)
		*color = BOT_COLOR;
	else if (i < delta * 2)
		*color = MID_COLOR;
	else
		*color = TOP_COLOR;
}

void		find_marks(t_all *all)
{
	int		*tmp_sort;
	int		i;

	if (!(tmp_sort = ft_memdup(all->ps.a, sizeof(int) * (all->ps.a[0]) + 1)))
		push_swap_clear_exit(all, PS_MEM_ERR);
	if (!(all->ps.marks = (t_mark **)ft_memalloc(sizeof(t_mark *)
	* (all->ps.a[0] + 1))))
	{
		ft_memdel((void **)&tmp_sort);
		push_swap_clear_exit(all, PS_MEM_ERR);
	}
	all->ps.marks[all->ps.a[0]] = NULL;
	sort(tmp_sort);
	i = 0;
	while (++i <= all->ps.a[0])
	{
		if (!(all->ps.marks[i - 1] = (t_mark *)malloc(sizeof(t_mark))))
			push_swap_clear_exit(all, PS_MEM_ERR);
		all->ps.marks[i - 1]->value = tmp_sort[i];
		set_color(all->ps.a[0], &all->ps.marks[i - 1]->color, i);
	}
	ft_memdel((void **)&tmp_sort);
}
