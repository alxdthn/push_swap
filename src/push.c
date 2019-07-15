/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:35:02 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/15 22:04:21 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push(int *src, int *dst)
{
	if (src[0])
	{
		dst[0] += 1;
		dst[dst[0]] = src[src[0]];
		src[0] -= 1;
		return (1);
	}
	return (0);
}

char	read_push(t_task *task)
{
	if (task->stack == 'a')
		return (PA);
	else if (task->stack == 'b')
		return (PB);
	return (0);
}
