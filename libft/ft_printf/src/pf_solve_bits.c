/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 04:28:23 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 02:25:55 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_res	solve_bits(t_task *task, va_list *args)
{
	t_res	res;

	res.len = 0;
	if ((res.str = ft_btoa((unsigned long)va_arg(*args, unsigned long),
	(task->prc == -1) ? task->size.value * 8 : task->prc, task->flags.sharp)))
	{
		res.len = ft_strlen(res.str);
		if (task->width > res.len)
			set_width(&res, task, ' ');
	}
	else
		res.len = -1;
	return (res);
}
