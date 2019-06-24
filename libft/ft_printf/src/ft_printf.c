/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:53:29 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 06:13:10 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_res	solve_task(t_task *task, va_list *args)
{
	if (ft_strchr("cCsS", task->type))
		return (set_arg_string(task, args));
	else if (task->type == 'p')
		return (solve_ptr(task, (unsigned long)va_arg(*args, void *)));
	else if (ft_strchr("dDioOuUxX", task->type))
		return (set_arg_digit(task, args));
	else if (task->type == 'f' || task->type == 'F')
		return (solve_float(task, args));
	else if (task->type == 'b')
		return (solve_bits(task, args));
	return (solve_noconv(task));
}

static int		print_out(t_out *out, va_list *args)
{
	int		ret;

	ret = 0;
	if (out->res.len)
		ret += out->res.len;
	if (out->task.type)
	{
		out->res = solve_task(&out->task, args);
		if (out->res.len == -1)
			return (-1);
		if (out->res.str)
		{
			write(1, out->res.str, out->res.len);
			ret += out->res.len;
			ft_strdel(&out->res.str);
		}
		if (out->task.clr)
		{
			out->task.clr = EOC;
			solve_color(out->task.clr, args);
			out->task.clr = NULL;
		}
	}
	return (ret);
}

int				ft_printf(char *fmt, ...)
{
	t_out	out;
	va_list	args;
	int		ret;
	int		buf;

	if (!fmt)
		return (-1);
	ret = 0;
	va_start(args, fmt);
	out_new(&out);
	while (*fmt && ret != -1)
	{
		if (out.task.type)
			out_new(&out);
		buf = parse(&fmt, &out, &args);
		ret = (buf == -1) ? buf : ret + buf;
		buf = print_out(&out, &args);
		ret = (buf == -1) ? buf : ret + buf;
	}
	va_end(args);
	return (ret);
}
