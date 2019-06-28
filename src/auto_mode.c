/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 04:31:21 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 04:53:49 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint(t_list *lst)
{
	t_list *tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		write(1, (char *)tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
}

void	get_info(t_info *info, int *a)
{
	int		i;

	info->adr = 1;
	info->value = a[1];
	i = 1;
	while (i <= a[0])
	{
		if (a[i] < info->value)
		{
			info->value = a[i];
			info->adr = i;
		}
		i++;
	}

}

int		is_sorted(int *arr)
{
	int		i;
	int		tmp;

	i = 1;
	while (i < arr[0])
	{
		tmp = arr[i];
		if (tmp > arr[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	auto_mode(t_ps *ps)
{
	t_info	info;
	char	*cmd;

	if (ps->flag)
	{
		ft_putstr("Init arrs:\n");
		print_arr(ps->a, ps->b);
	}
	while (ps->b[0] || !is_sorted(ps->a))
	{
		while (ps->a[0] != 1 && !is_sorted(ps->a))
		{
			get_info(&info, ps->a);
			if (info.adr == ps->a[0])
				cmd = "pb\n";
			else
				cmd = (ps->a[0] / 2 - info.adr < 0) ? "ra\n" : "rra\n";
			process_cmd(ps, cmd);
			ft_lstadd(&ps->lst, ft_lstnew(cmd, ft_strlen(cmd)));
		}
		while (ps->b[0])
		{
			cmd = "pa\n";
			process_cmd(ps, cmd);
			ft_lstadd(&ps->lst, ft_lstnew(cmd, ft_strlen(cmd)));
		}
	}
}
