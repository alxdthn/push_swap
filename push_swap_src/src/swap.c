/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:34:04 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 04:51:30 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int **arr)
{
	int		tmp;

	if ((*arr)[0] > 1)
	{
		tmp = (*arr)[(*arr)[0]];
		(*arr)[(*arr)[0]] = (*arr)[(*arr)[0] - 1];
		(*arr)[(*arr)[0] - 1] = tmp;
	}
}

void	solve_swap(int **a, int **b, t_task *task)
{
	if (task->stack == 'a')
		swap(a);
	else if (task->stack == 'b')
		swap(b);
	else if (task->stack == 'x')
	{
		swap(a);
		swap(b);
	}
}
