/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:35:02 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 14:47:13 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *src, int *dst, char cmd, char flag)
{
	if (src[0])
	{
		dst[0] += 1;
		dst[dst[0]] = src[src[0]];
		src[0] -= 1;
		if (flag)
		{
			if (cmd == PA)
				write(1, "pa\n", 3);
			else if (cmd == PB)
				write(1, "pb\n", 3);
		}
	}
}

char	read_push(t_task *task)
{
	if (task->stack == 'a')
		return (PA);
	else if (task->stack == 'b')
		return (PB);
	return (0);
}
