/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:34:04 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/15 22:05:14 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap(int *arr)
{
	int		tmp;

	if (arr[0] > 1)
	{
		tmp = arr[arr[0]];
		arr[arr[0]] = arr[arr[0] - 1];
		arr[arr[0] - 1] = tmp;
		return (1);
	}
	return (0);
}

char	read_swap(t_task *task)
{
	if (task->stack == 'a')
		return (SA);
	else if (task->stack == 'b')
		return (SB);
	else if (task->stack == 'x')
		return (SS);
	return (0);
}
