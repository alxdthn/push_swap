/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:44:40 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/19 17:52:53 by nalexand         ###   ########.fr       */
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

void		set_marks(t_mark **marks, int size)
{
	int		delta;
	int		i;

	delta = size / 3;
	i = 0;
	while (i < size)
	{
		if (i < delta)
		{
			marks[i]->level = 1;
			marks[i]->color = BOT_COLOR;
		}
		else if (i < delta * 2)
		{
			marks[i]->level = 2;
			marks[i]->color = MID_COLOR;
		}
		else
		{
			marks[i]->level = 3;
			marks[i]->color = TOP_COLOR;
		}
		i++;
	}
}

int			*get_presorted_arr(t_all *all, int *arr)
{
	int		*res;
	int		i;
	int		tmp;

	if (!(res = ft_memdup(arr, sizeof(int) * (arr[0] + 1))))
		all->exit_function(all, ERROR);
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
		all->exit_function(all, ERROR);
	}
	all->ps.marks[all->ps.a[0]] = NULL;
	i = 0;
	while (++i <= arr[0])
	{
		if (!(all->ps.marks[i - 1] = (t_mark *)malloc(sizeof(t_mark))))
			all->exit_function(all, ERROR);
		all->ps.marks[i - 1]->value = arr[i];
	}
}
