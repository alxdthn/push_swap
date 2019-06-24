/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 02:27:14 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/28 11:02:15 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_FLOAT_H
# define PF_FLOAT_H
# include "pf_includes.h"

typedef	union			u_ems
{
	long double			ldbl;
	__int128_t			bits;
	struct				s_ems
	{
		unsigned long	m : 64;
		uint16_t		e : 15;
		uint8_t			s : 1;
	}					ems;
}						t_ems;

typedef struct			s_lnbr
{
	size_t				len;
	int					vls[N_SIZE];
}						t_lnbr;

t_res					solve_float(t_task *task, va_list *args);
void					get_ldbl(t_res *res, t_task *task, t_ems *uni);
void					get_float_div(t_lnbr *div, t_ems uni);
void					get_float_mod(t_lnbr *mod, t_ems uni, int prc);

t_lnbr					set_lnbr(char *str);
void					clear_lnbr(t_lnbr *lnbr);
void					multi_lnbr(t_lnbr *a, t_lnbr *b);
void					add_lnbr(t_lnbr *a, t_lnbr *b);
void					values_to_chars(char **data, size_t size);
void					pos_pow_of_two(t_lnbr *pow, t_lnbr *factor,
						int *max, char p);
void					neg_pow_of_two(t_lnbr *pow, t_lnbr *factor,
						int *max, char p);

#endif
