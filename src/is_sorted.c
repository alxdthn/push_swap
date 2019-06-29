/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 06:21:55 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 06:22:28 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(int *arr)
{
	int		i;
	int		tmp;

	i = 1;
	while (i < arr[0])
	{
		tmp = arr[i];
		if (tmp > arr[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
