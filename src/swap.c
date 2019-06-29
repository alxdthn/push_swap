/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:34:04 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/29 23:03:59 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *arr)
{
	int		tmp;

	if (arr[0] > 1)
	{
		tmp = arr[arr[0]];
		arr[arr[0]] = arr[arr[0] - 1];
		arr[arr[0] - 1] = tmp;
	}
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
