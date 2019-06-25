/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:06:49 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 02:27:49 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# define QUIT 1
# define SA 2
# define SB 3
# define SS 4
# define PA 5
# define PB 6
# define RA 7
# define RB 8
# define RR 9
# define RRA 10
# define RRB 11
# define RRR 12

void	print_arr(int **a, int **b)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = (*a)[0];
	j = (*b)[0];
	len = ((*a)[0] >= (*b)[0]) ? (*a)[0] : (*b)[0];
	ft_putstr("----------------------------------\n");
	while (len)
	{
		(len > (*a)[0]) ? ft_printf("%-5c", ' ') : ft_printf("%-5d", (*a)[i--]);
		(len > (*b)[0]) ? ft_printf("%-5c", ' ') : ft_printf("%-5d", (*b)[j--]);
		ft_putchar('\n');
		len--;
	}
	ft_printf("%-5c%-5c\n%-5c%-5c\n", '-', '-', 'A', 'B');
	ft_putstr("----------------------------------\n");
}

void	init(int **a, int **b, int ac, char **av)
{
	size_t	i;
	size_t	size;

	size = ac - 1;
	*a = (int *)malloc(sizeof(int) * (size + 1));
	*b = (int *)malloc(sizeof(int) * (size + 1));
	(*a)[0] = size;
	(*b)[0] = 0;
	i = 1;
	while (i <= (*a)[0])
		(*a)[i++] = ft_atoi(av[ac-- - 1]);
}

void	push(int **src, int **dst)
{
	size_t	i;
	size_t	j;

	if ((*src)[0])
	{
		(*dst)[0] += 1;
		(*dst)[(*dst)[0]] = (*src)[(*src)[0]];
		(*src)[0] -= 1;
	}
}

void	swap(int **arr)
{
	int		tmp;

	if ((*arr)[0] > 1)
	{
		tmp = (*arr)[(*arr)[0]];
		(*arr)[(*arr)[0]] = (*arr)[(*arr)[0] - 1];
		(*arr)[(*arr)[0] - 1] = tmp;
	}
}

void	rotate(int **arr, char dir)
{
	size_t	i;
	size_t	j;
	int		*tmp;

	if ((*arr)[0] < 2)
		return ;
	tmp = (int *)malloc(sizeof(int) * ((*arr)[0] + 1));
	tmp[0] = (*arr)[0];
	j = 2;
	i = 1;
	if (dir == -1)
	{
		tmp[tmp[0]] = (*arr)[1];
		while (i < tmp[0])
			tmp[i++] = (*arr)[j++];
	}
	else
	{
		tmp[1] = (*arr)[(*arr)[0]];
		while (i < tmp[0])
			tmp[j++] = (*arr)[i++];
	}
	ft_memdel((void **)arr);
	*arr = tmp;
}

int		get_cmd(char **cmd)
{
	int		res;

	res = 0;
	if (ft_strnequ(*cmd, "sa", 2) && (*(*cmd + 2) == ' ' || *(*cmd + 2) == '\0'))
		res = SA;
	else if (ft_strnequ(*cmd, "sb", 2) && (*(*cmd + 2) == ' ' || *(*cmd + 2) == '\0'))
		res = SB;
	else if (ft_strnequ(*cmd, "ss", 2) && (*(*cmd + 2) == ' ' || *(*cmd + 2) == '\0'))
		res = SS;
	else if (ft_strnequ(*cmd, "pa", 2) && (*(*cmd + 2) == ' ' || *(*cmd + 2) == '\0'))
		res = PA;
	else if (ft_strnequ(*cmd, "pb", 2) && (*(*cmd + 2) == ' ' || *(*cmd + 2) == '\0'))
		res = PB;
	else if (ft_strnequ(*cmd, "ra", 2) && (*(*cmd + 2) == ' ' || *(*cmd + 2) == '\0'))
		res = RA;
	else if (ft_strnequ(*cmd, "rb", 2) && (*(*cmd + 2) == ' ' || *(*cmd + 2) == '\0'))
		res = RB;
	else if (ft_strnequ(*cmd, "rr", 2) && (*(*cmd + 2) == ' ' || *(*cmd + 2) == '\0'))
		res = RR;
	else if (ft_strnequ(*cmd, "rra", 3) && (*(*cmd + 3) == ' ' || *(*cmd + 3) == '\0'))
		res = RRA;
	else if (ft_strnequ(*cmd, "rrb", 3) && (*(*cmd + 3) == ' ' || *(*cmd + 3) == '\0'))
		res = RRB;
	else if (ft_strnequ(*cmd, "rrr", 3) && (*(*cmd + 3) == ' ' || *(*cmd + 3) == '\0'))
		res = RRR;
	else if (ft_strnequ(*cmd, "q", 1) && (*(*cmd + 1) == ' ' || *(*cmd + 1) == '\0'))
		return (QUIT);
	if (res)
	{
		while (*cmd && ft_isalpha(**cmd))
			(*cmd)++;
		while (*cmd && **cmd == ' ')
			(*cmd)++;
	}
	return (res);
}

int		process_cmd(int **a, int **b, char **cmd)
{
	int		ret;
	char	*tmp;

	tmp = *cmd;
	while (*tmp)
	{
		ret = get_cmd(&tmp);
		if (ret == SA)
			swap(a);
		else if (ret == SB)
			swap(b);
		else if (ret == SS)
		{
			swap(a);
			swap(b);
		}
		else if (ret == PA)
			push(b, a);
		else if (ret == PB)
			push(a, b);
		else if (ret == RA)
			rotate(a, 1);
		else if (ret == RB)
			rotate(b, 1);
		else if (ret == RR)
		{
			rotate(a, 1);
			rotate(b, 1);
		}
		else if (ret == RRA)
			rotate(a, -1);
		else if (ret == RRB)
			rotate(b, -1);
		else if (ret == RRR)
		{
			rotate(a, -1);
			rotate(b, -1);
		}
		else if (ret == QUIT)
			return (1);
		else if (ret == 0)
		{
			ft_putstr("Unknown command!\n");
			return (0);
		}
	}
	ft_strdel(cmd);
	return (0);
}

int		main(int ac, char **av)
{
	int		*a;//{2, 1, 3, 6, 5, 8};
	int		*b;
	char	*cmd;

	if (ac < 2)
	{
		ft_putstr("usage: push_swap int_values...\n");
		return (1);
	}
	cmd = NULL;
	init(&a, &b, ac, av);
	print_arr(&a, &b);
	while (get_next_line(0, &cmd) > 0)
	{
		if (process_cmd(&a, &b, &cmd))
			break ;
		print_arr(&a, &b);
	}
	ft_memdel((void **)&a);
	ft_memdel((void **)&b);
	return (0);
}
