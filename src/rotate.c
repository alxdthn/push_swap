/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:35:34 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/29 04:51:32 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *arr, char dir)
{
	int		tmp;

	if (arr[0] < 2)
		return ;
	if (dir == 1)
	{
		tmp = arr[arr[0]];
		ft_memmove(arr + 2, arr + 1, (arr[0] - 1) * sizeof(int));
		arr[1] = tmp;
	}
	else
	{
		tmp = arr[1];
		ft_memmove(arr + 1, arr + 2, (arr[0] - 1) * sizeof(int));
		arr[arr[0]] = tmp;
	}
}

int		solve_rotate(int *a, int *b, t_task *task)
{
	int		dir;

	dir = (task->action == 'v') ? -1 : 1;
	if (task->stack == 'a')
	{
		rotate(a, dir);
		return (4 + dir);
	}
	else if (task->stack == 'b')
	{
		rotate(b, dir);
		return (7 + dir);
	}
	else if (task->stack == 'x')
	{
		rotate(a, dir);
		rotate(b, dir);
		return (14 + dir);
	}
	return (0);
}
