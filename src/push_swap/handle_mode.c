/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:59:11 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/19 17:53:42 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_and_print(t_all *all, t_list *tmp, size_t count)
{
	if (count > 1)
		solve_and_print(all, tmp->next, count - 1);
	if (*(char *)tmp->content == QUIT)
	{
		print_lst(all->ps.lst);
		push_swap_clear_exit(all, NULL);
	}
	make_cmd(all, *(char *)tmp->content);
	print_arr(all->ps.a, all->ps.b);
}

void		handle_mode(t_all *all)
{
	int		ret;
	t_list	*tmp;
	char	*line;
	size_t	count;

	all->u.flags.print_cmds = 0;
	ft_putendl(SALUT);
	print_arr(all->ps.a, all->ps.b);
	tmp = NULL;
	while (42)
	{
		ret = get_next_line(0, &line);
		if (ret < 0)
			all->exit_function(all, ERROR);
		count = get_cmd(all, &line);
		tmp = all->ps.lst;
		solve_and_print(all, tmp, count);
	}
}
