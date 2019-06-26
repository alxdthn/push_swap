/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:13:31 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/26 05:24:40 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <time.h>

typedef struct	s_task
{
	char		stack;
	char		action;
	char		is_valid;
}				t_task;

void	push(int **src, int **dst);
void	swap(int **arr);
int		rotate(int **arr, char dir);
void	solve_push(int **a, int **b, t_task *task);
void	solve_swap(int **a, int **b, t_task *task);
int		solve_rotate(int **a, int **b, t_task *task);
int		process_cmd(int **a, int **b, char **cmd);
void	push_swap_clear_exit(int **a, int **b);
void	handle_mode(int **a, int **b, int ac, char **av);
void	auto_mode(int **a, int **b, int ac, char **av);

#endif
