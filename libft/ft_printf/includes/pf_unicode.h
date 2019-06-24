/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unicode.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 02:35:34 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 04:16:16 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_UNICODE_H
# define PF_UNICODE_H
# include "pf_includes.h"

typedef union		u_unicode
{
	int				bits;
	struct			s_parts
	{
		uint32_t	a : 6;
		uint32_t	b : 6;
		uint32_t	c : 6;
		uint32_t	d : 6;
	}				parts;
}					t_unic;

size_t				unicode_len(wchar_t *u_str, int count, int prc);
char				*get_uchar(char *buf, int uchar, int size);

#endif
