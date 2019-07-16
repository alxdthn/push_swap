/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:44:40 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 20:00:57 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mark		get_value_mark(t_mark **marks, int value)
{
	int		i;

	i = 0;
	while (marks[i])
	{
		if (marks[i]->value == value)
			break ;
		i++;
	}
	return (*(marks)[i]);
}

void		set_color(t_mark **marks, int size)
{
	int		delta;
	int		i;

	delta = size / 3;
	i = 0;
	while (i < size)
	{
		if (i < delta)
			marks[i]->color = BOT_COLOR;
		else if (i < delta * 2)
			marks[i]->color = MID_COLOR;
		else
			marks[i]->color = TOP_COLOR;
		i++;
	}
}

int			*get_presorted_arr(t_all *all, int *arr)
{
	int		*res;
	int		i;
	int		tmp;

	if (!(res = ft_memdup(arr, sizeof(int) * (arr[0]) + 1)))
		push_swap_clear_exit(all, PS_MEM_ERR);
	i = 1;
	while (i < res[0])
	{
		if (res[i] < res[i + 1])
		{
			tmp = res[i];
			res[i] = res[i + 1];
			res[i + 1] = tmp;
			i = 1;
			continue ;
		}
		i++;
	}
	return (res);
}

void		init_marks_arr(t_all *all, int *arr)
{
	int		i;

	if (!(all->ps.marks = (t_mark **)malloc(sizeof(t_mark *)
	* (all->ps.a[0] + 1))))
	{
		ft_memdel((void **)&arr);
		push_swap_clear_exit(all, PS_MEM_ERR);
	}
	all->ps.marks[all->ps.a[0]] = NULL;
	i = 0;
	while (++i <= arr[0])
	{
		if (!(all->ps.marks[i - 1] = (t_mark *)malloc(sizeof(t_mark))))
			push_swap_clear_exit(all, PS_MEM_ERR);
		all->ps.marks[i - 1]->value = arr[i];
		all->ps.marks[i - 1]->is_section = 0;
	}
}
