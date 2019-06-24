/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:27:31 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 07:49:06 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "# 0-+"
# define TYPES "cCsSpdDioOuUxXfF"
# define ALL_PARAM "# 0-+lhLzj.123456789*"
# define N_SIZE 16383
# define ACC 20
# include "pf_fun.h"
# include "pf_out.h"
# include "pf_float.h"
# include "pf_unicode.h"

void	get_size(char **fmt, t_size *size);
void	get_prc(char **fmt, int *prc, va_list *args);
void	get_width(char **fmt, t_task *task, va_list *args);
int		get_flags(char fmt, t_task *task);

void	set_sign(t_res *res, t_task *task, long nbr);
void	set_prc(t_res *res, int prc);
void	set_width(t_res *res, t_task *task, char filler);
void	set_zero(t_res *res, int width);

t_res	pf_ltoa_base(unsigned long nbr, char base, t_task *task);

t_res	set_arg_digit(t_task *task, va_list *args);
t_res	set_arg_string(t_task *task, va_list *args);
t_res	solve_digit(t_task *task, long arg);
t_res	solve_uchar(t_task *task, wchar_t uchar);
t_res	solve_ustr(t_task *task, wchar_t *ustr);
t_res	solve_noconv(t_task *task);
t_res	solve_ptr(t_task *task, unsigned long ptr);
t_res	solve_bits(t_task *task, va_list *args);

int		find_type(char *fmt);
int		parse(char **fmt, t_out *out, va_list *args);
int		ft_printf(char *fmt, ...);

void	print_lnbr(t_lnbr nbr);
char	*show_lnbr(t_lnbr nbr);
int		print_ldbl_ems(t_ems ems, char param);

#endif
