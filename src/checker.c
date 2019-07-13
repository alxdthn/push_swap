/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:15:03 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/13 21:32:16 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_mode(t_all *all)
{
	int		count;

	count = 0;
	while (all->ps.cmds[all->ps.point])
	{
		process_cmd(&all->ps, all->ps.cmds[all->ps.point++]);
		count++;
	}
	if (!all->ps.b[0] && is_sorted(all->ps.a))
		ft_printf("%{gre}s\nOperations: %d\n", "OK", count);
	else
		ft_printf("%{red}s\nOperations: %d\n", "KO", count);
}

static void		read_input(t_all *all)
{
	t_list	*tmp;
	char	*line;
	size_t	count;
	int		ret;

	count = 0;
	//int fd = open("cmds.txt", O_RDONLY);
	while ((ret = get_next_line(0, &line)))
	{
		if (ret < 0)
			push_swap_clear_exit(all, CH_INPUT_ERR);
		count += get_cmd(all, &line);
	}
	if (!(all->ps.cmds = (char *)malloc(sizeof(char) * (count + 1))))
		push_swap_clear_exit(all, CH_MEM_ERR);
	all->ps.cmds[count] = 0;
	tmp = all->ps.lst;
	while (tmp)
	{
		all->ps.cmds[count-- - 1] = *(char *)tmp->content;
		tmp = tmp->next;
	}
	//push_swap_clear_exit(all, "DEBUG END\n");
}

int			main(int ac, char **av)
{
	t_all	all;

	all.prog = CHECKER;
	init(&all, ac, av);
	check_matches(&all);
	read_input(&all);
	if (all.ps.flag)
	{
		if (all.ps.flag == 'v')
		{
			visualisation_init(&all);
			render(&all.ps, &all.mlx, START);
			mlx_loop(&all.mlx.ptr);
		}
		else
			all.ps.flag = ft_puterr(0, CH_FLAG_ERR);
	}
	else
		check_mode(&all);
	return (0);
}
