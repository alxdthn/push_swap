/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:35:02 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/29 04:27:06 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *src, int *dst)
{
	if (src[0])
	{
		dst[0] += 1;
		dst[dst[0]] = src[src[0]];
		src[0] -= 1;
	}
}

int		solve_push(int *a, int *b, t_task *task)
{
	if (task->stack == 'a')
	{
		push(b, a);
		return (PA);
	}
	else if (task->stack == 'b')
	{
		push(a, b);
		return (PB);
	}
	return (0);
}
