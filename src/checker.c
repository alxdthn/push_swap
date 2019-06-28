/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:15:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 04:41:16 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	char	*cmd;
	t_ps	ps;

	if (init(&ps, ac, av))
		return (1);
	if (check_matches(ps.a))
		auto_mode(&ps);
	while (get_next_line(0, &cmd) > 0)
	{
		if (!process_cmd(&ps, cmd))
		{
			ft_strdel(&cmd);			
			break ;
		}
		ft_strdel(&cmd);
	}
	if (is_sorted(ps.a))
		ft_printf("%{gre}s\n", "OK");
	else
		ft_printf("%{red}s\n", "KO");
}
