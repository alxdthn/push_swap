/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:34:04 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 14:49:02 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *arr, char cmd, char flag)
{
	int		tmp;

	if (arr[0] > 1)
	{
		tmp = arr[arr[0]];
		arr[arr[0]] = arr[arr[0] - 1];
		arr[arr[0] - 1] = tmp;
		if (flag)
		{
			if (cmd == SA)
				write(1, "sa\n", 3);
			else if (cmd == SB)
				write(1, "sb\n", 3);
			else if (cmd == SS)
				write(1, "ss\n", 3);
		}
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
