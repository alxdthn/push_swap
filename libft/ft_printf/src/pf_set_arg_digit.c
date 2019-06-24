/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_arg_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:51:16 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 04:02:46 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	set_unsigned_arg(t_task *task, va_list *args)
{
	long	arg;

	if (task->type == 'U' || task->type == 'O' || task->size.chr == 'l')
		arg = (long)va_arg(*args, unsigned long);
	else if (task->size.chr == 'L' || task->size.chr == 'j')
		arg = (long)va_arg(*args, unsigned long long);
	else if (task->size.chr == 'z')
		arg = (long)va_arg(*args, size_t);
	else
		arg = (long)va_arg(*args, unsigned int);
	if (task->size.chr == 'h')
		arg = (long)((unsigned short)arg);
	else if (task->size.chr == 'H')
		arg = (long)((unsigned char)arg);
	return (arg);
}

t_res		set_arg_digit(t_task *task, va_list *args)
{
	long	arg;

	if (task->type == 'd' || task->type == 'i' || task->type == 'D')
	{
		if (task->type == 'D' || task->size.chr == 'l')
			arg = (long)va_arg(*args, long);
		else if (task->size.chr == 'L' || task->size.chr == 'j')
			arg = (long)va_arg(*args, long long);
		else if (task->size.chr == 'z')
			arg = (long)va_arg(*args, ssize_t);
		else
			arg = (long)va_arg(*args, int);
		if (task->size.chr == 'h')
			arg = (long)((short)arg);
		else if (task->size.chr == 'H')
			arg = (long)((char)arg);
	}
	else
		arg = set_unsigned_arg(task, args);
	return (solve_digit(task, arg));
}
