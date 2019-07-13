/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:06:49 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/13 19:14:40 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_cmd(t_all *all, char cmd)
{
	process_cmd(&all->ps, cmd);
	ft_lstadd(&all->ps.lst, ft_lstnew(&cmd, sizeof(char)));
	if (!all->ps.lst)
		push_swap_clear_exit(all, PS_MEM_ERR);
}

static void	first_shit(t_all *all)
{
	t_info	info;
	char	cmd;

	while (all->ps.b[0] || !is_sorted(all->ps.a))
	{
		while (all->ps.a[0] != 1 && !is_sorted(all->ps.a))
		{
			get_info(&info, all->ps.a);
			if (info.min_adr == all->ps.a[0])
				cmd = PB;
			else
				cmd = (all->ps.a[0] / 2 - info.min_adr < 0) ? RA : RRA;
			make_cmd(all, cmd);
		}
		while (all->ps.b[0])
			make_cmd(all, PA);
	}
}

static void get_a_rotate(int *arr, int value, t_oprs *oprs, int min)
{
	size_t	i;

	i = 1;
	while (i < arr[0])
	{
		if (value < arr[i] && value > arr[(i == 1) ? arr[0] : i + 1])
			break ;
		if (value > arr[(i == 1) ? arr[0] : i + 1] && arr[i] == min)
			break ;
		i++;
	}
	//ft_printf("left: %d value: %d right: %d min: %d\n", arr[(i == 1) ? arr[0] : i - 1], value, arr[i], min);
	oprs->ra = i - 1;
	oprs->rra = 0;
	//ft_printf("ra: %d\n", oprs->ra);
	//oprs->rra = arr[0] - i + 1;
	//if (oprs->ra < oprs->rra)
	//	oprs->rra = 0;
	//else
	//	oprs->ra = 0;
}

static void	find_better_rotation(t_all *all, t_oprs *oprs)
{
	t_info	info;

	//oprs->rb = adr - 1;
	//oprs->rrb = all->ps.b[0] - adr + 1;

	oprs->ra = 0;
	oprs->rb = 0;
	oprs->rr = 0;
	oprs->rb = 0;
	oprs->rrb = 0;
	oprs->rrr = 0;
	get_info(&info, all->ps.a);
}

static void	solve_operations(t_all *all, t_oprs oprs)
{
	while (oprs.rr--)
		make_cmd(all, RR);
	while (oprs.rrr--)
		make_cmd(all, RRR);
	while (oprs.ra--)
		make_cmd(all, RA);
	while (oprs.rb--)
		make_cmd(all, RB);
	while (oprs.rra--)
		make_cmd(all, RRA);
	while (oprs.rrb--)
		make_cmd(all, RRB);
}

static void	find_neibs(t_all *all)
{
	int		*tmp_sort;

	if (!(tmp_sort = ft_memdup(all->ps.a, all->ps.a[0] * sizeof(int))))
		push_swap_clear_exit(all, PS_MEM_ERR);
	if (!(all->ps.neibs = (t_neibs **)malloc(sizeof(t_neibs *) * (all->ps.a[0] + 1))))
	{
		free(tmp_sort);
		push_swap_clear_exit(all, PS_MEM_ERR);
	}
	all->ps.neibs[all->ps.a[0]] = NULL;
}

static void	next_shit(t_all *all)
{
	t_info			info;
	t_oprs			tmp_oprs;
	t_oprs			oprs;
	int				ret;
	int				i;
	t_neibs			*neibs;

	find_neibs(all);
	get_info(&info, all->ps.a);
	while (all->ps.a[0] > 2)
	{
		if (all->ps.a[all->ps.a[0]] == info.min_value)
			make_cmd(all, RA);
		make_cmd(all, PB);
	}
	while (!is_sorted(all->ps.a))
		make_cmd(all, RA);
	while (all->ps.b[0])
	{
		//find_better_rotation(all, &oprs);
		//solve_operations(all, oprs);
		make_cmd(all, PA);
	}
	/*
	while (all->ps.b[0])
	{
		i = 1;
		oprs.count = INT32_MAX;
		while (i - 1 < all->ps.b[0])
		{
			find_better_rotation(all, &tmp_oprs, i++);
			if (tmp_oprs.count < oprs.count)
				ft_memcpy(&oprs, &tmp_oprs, sizeof(t_oprs));
		}
		//ft_printf("-------------------------\n");
		solve_operations(all, oprs);
		//print_lst(all->ps.lst);
		//push_swap_clear_exit(all, NULL);
	}
	 */
	//while (!is_sorted(all->ps.a))
	//	make_cmd(all, RA);
}

static void	auto_mode(t_all *all)
{
	first_shit(all);
	//next_shit(all);
}

void		solve_and_print(t_all *all, t_list *tmp, size_t count)
{
	if (count > 1)
		solve_and_print(all, tmp->next, count - 1);
	if (*(char *)tmp->content == QUIT)
	{
		print_lst(all->ps.lst);
		push_swap_clear_exit(all, NULL);
	}
	process_cmd(&all->ps, *(char *)tmp->content);
	print_arr(all->ps.a, all->ps.b);
}

static void	handle_mode(t_all *all)
{
	int		ret;
	t_list	*tmp;
	char	*line;
	size_t	count;

	ft_putendl("Init stacks:");
	print_arr(all->ps.a, all->ps.b);
	tmp = NULL;
	while (42)
	{
		ret = get_next_line(0, &line);
		if (ret < 0)
			push_swap_clear_exit(all, PS_INPUT_ERR);
		count = get_cmd(all, &line);
		tmp = all->ps.lst;
		solve_and_print(all, tmp, count);
	}
}

int		main(int ac, char **av)
{
	t_all	all;

	all.prog = PUSH_SWAP;
	init(&all, ac, av);
	if (all.ps.flag == 'h')
		ft_putendl(SALUT);
	else if (all.ps.flag && all.ps.flag != 'h')
		all.ps.flag = ft_puterr(0, PS_FLAG_ERR);
	check_matches(&all);
	(all.ps.flag) ? handle_mode(&all) : auto_mode(&all);
	print_lst(all.ps.lst);
	push_swap_clear_exit(&all, NULL);
	return (0);
}
