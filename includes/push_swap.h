/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:13:31 by nalexand          #+#    #+#             */
/*   Updated: 2019/06/29 04:46:44 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>
# define PS_USAGE	"usage: push_swap [-h] array\n"\
					"array: non-repeating ints\n"\
					"example: push_swap [-h] 2 5 1 3\n"
# define CH_USAGE	"usage: checker [-v] array\n"\
					"array: non-repeating ints\n"\
					"example: checker [-h] 2 5 1 3\n"
# define LEFT_BACKGROUND 0x7791d1
# define POS_LINE_COLOR 0xdc78f0
# define NEG_LINE_COLOR 0xdfacfa
# define RIGHT_BACKGROUND 0x99f0d1
# define ESC 53
# define ENTER 36
# define QUIT 0
# define SA 1
# define SB 2
# define RRA 3
# define RA 5
# define RRB 6
# define RB 8
# define SS 10
# define PA 11
# define PB 12
# define RRR 13
# define RR 15
# define START 42
# define ABS(x) ((x) > 0 ? (x) : -(x))

typedef struct	s_task
{
	char		stack;
	char		action;
	char		is_valid;
}				t_task;

typedef struct	s_info
{
	int			min_adr;
	int			min_value;
	int			max_adr;
	int			max_value;
}				t_info;

typedef struct	s_ps
{
	t_list		*lst;
	int			*a;
	int			*b;
	int			size;
	char		flag;
}				t_ps;

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	t_img		a;
	t_img		b;
	void		*ptr;
	void		*win;
	size_t		time;
	int			width;
	int			height;
	int			elem_width;
	int			elem_height;
}				t_mlx;

typedef struct	s_all
{
	t_ps		ps;
	t_mlx		mlx;
}				t_all;

int		init(t_ps *ps, int ac, char **av, char *usage);
void	push(int *src, int *dst);
void	swap(int *arr);
void	rotate(int *arr, char dir);
int		solve_push(int *a, int *b, t_task *task);
int		solve_swap(int *a, int *b, t_task *task);
int		solve_rotate(int *a, int *b, t_task *task);
int		process_cmd(t_ps *ps, char *cmd);
void	push_swap_clear_exit(t_ps *ps);
void	print_arr(int *a, int *b);
int		is_sorted(int *arr);
int		check_matches(int *a);
void	print_lst(t_list **lst);
void	get_info(t_info *info, int *a);

#endif
