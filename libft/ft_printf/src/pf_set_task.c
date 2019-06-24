/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_task.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:47:20 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 04:01:56 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flags_new(t_flags *flags)
{
	flags->sharp = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
}

static void	task_new(t_task *task)
{
	flags_new(&task->flags);
	task->clr = NULL;
	task->size.chr = 0;
	task->size.value = sizeof(int);
	task->width = 0;
	task->prc = -1;
	task->type = '\0';
}

void		out_new(t_out *out)
{
	task_new(&out->task);
	out->res.str = NULL;
	out->res.len = 0;
}
