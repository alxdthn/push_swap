/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:13:31 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/28 02:10:14 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <time.h>
# define USAGE	"usage: push_swap [-h] array\n"\
				"array: non-repeating ints\n"\
				"example: push_swap [-h] 2 5 1 3\n"

typedef struct	s_task
{
	char		stack;
	char		action;
	char		is_valid;
}				t_task;

typedef struct	s_info
{
	int			adr;
	int			value;
}				t_info;

typedef struct	s_ps
{
	t_list		*lst;
	int			*a;
	int			*b;
	int			size;
	char		flag;
}				t_ps;

int		init(t_ps *ps, int ac, char **av);
void			push(int *src, int *dst);
void			swap(int *arr);
void			rotate(int *arr, char dir);
void			solve_push(int *a, int *b, t_task *task);
void			solve_swap(int *a, int *b, t_task *task);
void			solve_rotate(int *a, int *b, t_task *task);
int				process_cmd(t_ps *ps, char *cmd);
void			push_swap_clear_exit(t_ps *ps);
void			handle_mode(t_ps *ps);
void			auto_mode(t_ps *ps);
void	print_arr(int *a, int *b);
int		is_sorted(int *arr);
int		check_matches(int *a);
void		print_lst(t_list **lst);

#endif
