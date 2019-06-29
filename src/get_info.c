/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 23:03:31 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 23:33:51 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_info(t_info *info, int *a)
{
	int		i;

	info->min_adr = 1;
	info->max_adr = 1;
	info->min_value = a[1];
	info->max_value = a[1];
	i = 1;
	while (i <= a[0])
	{
		if (a[i] < info->min_value)
		{
			info->min_value = a[i];
			info->min_adr = i;
		}
		if (a[i] > info->max_value)
		{
			info->max_value = a[i];
			info->max_adr = i;
		}
		i++;
	}
}
