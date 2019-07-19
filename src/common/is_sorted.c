/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 06:21:55 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/30 05:49:14 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_loop_sorted(int *arr, int adr)
{
	int		i;

	i = 1;
	while (i < arr[0])
	{
		if (adr == 1)
		{
			if (arr[adr] < arr[arr[0]])
				adr = arr[0];
			else
				return (0);
		}
		else if (arr[adr] < arr[adr - 1])
			adr--;
		else
			return (0);
		i++;
	}
	return (1);
}

int		is_sorted(int *arr)
{
	int		i;

	i = 1;
	while (i < arr[0])
	{
		if (arr[i] > arr[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
