/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 08:29:45 by nalexand          #+#    #+#             */
/*   Updated: 2019/05/27 07:30:40 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_COLORS_H
# define PF_COLORS_H
# define CLR_COUNT 10
# define EOC "\033[0m"
# define BLC "\033[30m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define CYN "\033[36m"
# define WHI "\033[37m"
# include "pf_out.h"

int		parse_color(char **fmt, t_task *task, va_list *args);
int		solve_color(char *clr, va_list *args);
void	get_color(char **fmt, char **clr);

#endif
