/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve_pcsn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:40:15 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 07:43:43 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_res	solve_ptr(t_task *task, unsigned long ptr)
{
	t_res	res;
	t_res	nbr;

	res.str = NULL;
	res.len = 0;
	if (ptr == 0 && task->prc == 0)
		nbr.len = 0;
	else
		nbr = pf_ltoa_base(ptr, 16, task);
	res.len = nbr.len + 2;
	if (nbr.len != -1 && (res.str = (char *)malloc(sizeof(char) * res.len)))
	{
		res.str[0] = '0';
		res.str[1] = 'x';
		ft_memcpy(res.str + 2, nbr.str, nbr.len);
		if (task->prc == -1 && task->flags.zero && task->width > res.len)
			set_zero(&res, task->width);
		else if (task->width > res.len)
			set_width(&res, task, ' ');
	}
	else
		res.len = -1;
	if (nbr.len)
		ft_strdel(&nbr.str);
	return (res);
}

t_res	solve_str(t_task *task, char *str)
{
	t_res	res;

	res.str = NULL;
	res.len = 0;
	if (task->prc)
	{
		if (str == NULL)
		{
			res.len = (task->prc > 0 && task->prc < 6) ? task->prc : 6;
			res.str = (char *)ft_memdup("(null)", res.len);
		}
		else
		{
			res.len = ft_strlen(str);
			res.len = (task->prc > 0 && task->prc < res.len)
			? task->prc : res.len;
			res.str = (char *)ft_memdup(str, res.len);
		}
		if (!res.str)
			res.len = -1;
	}
	if (task->width > res.len)
		set_width(&res, task, (task->flags.zero) ? '0' : ' ');
	return (res);
}

t_res	solve_char(t_task *task, unsigned char c)
{
	t_res	res;

	res.str = NULL;
	res.len = (task->width) ? task->width : 1;
	if ((res.str = (char *)malloc(sizeof(char) * res.len)))
	{
		if (task->width)
		{
			(task->flags.zero) ? ft_memset(res.str, '0', res.len)
			: ft_memset(res.str, ' ', res.len);
			if (task->flags.minus)
				res.str[0] = c;
			else
				res.str[res.len - 1] = c;
		}
		else
			res.str[0] = c;
	}
	else
		res.len = -1;
	return (res);
}

t_res	solve_noconv(t_task *task)
{
	t_res	res;

	res.str = NULL;
	res.len = 1;
	if ((res.str = (char *)malloc(sizeof(char) * res.len)))
	{
		res.str[0] = task->type;
		if (task->flags.zero && task->width > res.len)
			set_zero(&res, task->width);
		else if (task->width > res.len)
			set_width(&res, task, ' ');
	}
	else
		res.len = -1;
	return (res);
}

t_res	set_arg_string(t_task *task, va_list *args)
{
	if ((task->type == 'c' && task->size.chr == 'l') || task->type == 'C')
		return (solve_uchar(task, va_arg(*args, wchar_t)));
	else if (task->type == 'c')
		return (solve_char(task, va_arg(*args, int)));
	else if ((task->type == 's' && task->size.chr == 'l') || task->type == 'S')
		return (solve_ustr(task, va_arg(*args, wchar_t *)));
	return (solve_str(task, va_arg(*args, char *)));
}
