/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:13:31 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/13 16:49:46 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>
# define PS_USAGE		"usage: push_swap [-h] array\n"\
						"array: non-repeating ints\n"\
						"example: push_swap [-h] 2 5 1 3"
# define CH_USAGE		"usage: checker [-v] array\n"\
						"array: non-repeating ints\n"\
						"example: checker [-h] 2 5 1 3"
# define PS_MEM_ERR		"push_swap: Mem alocate failture!"
# define CH_MEM_ERR		"checker: Mem alocate failture!"
# define PS_ARG_ERR		"push_swap: Invalid argument!"
# define CH_ARG_ERR		"checker: Invalid argument!"
# define PS_MATCH_ERR	"push_swap: Matches forbidden!"
# define CH_MATCH_ERR	"checker: Matches forbidden!"
# define PS_CMD_ERR		"push_swap: Invalid command!"
# define CH_CMD_ERR		"checker: Invalid command!"
# define PS_FLAG_ERR	"push_swap: Unknown flag"
# define CH_FLAG_ERR	"checker: Unknown flag"
# define PS_INPUT_ERR	"push_swap: Uncknown input error"
# define CH_INPUT_ERR	"checker: Uncknown input error"
# define SALUT			"push_swap: Welcome to handle mode"

# define LEFT_BACKGROUND 0x252526
# define RIGHT_BACKGROUND 0x1E1E1E
# define POS_LINE_COLOR 0xC3C39D
# define NEG_LINE_COLOR 0x8FBBD7

# define ESC 53
# define ENTER 36
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125

# define PUSH_SWAP 22
# define CHECKER 21
# define QUIT -1
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

typedef struct	s_oprs
{
	int			rr;
	int			ra;
	int			rb;
	int			rrr;
	int			rra;
	int			rrb;
	int			count;
}				t_oprs;

typedef struct	s_neibs
{
	int			value;
	int			up;
	int			down;
}				t_neibs;

typedef struct	s_ps
{
	t_list		*lst;
	t_neibs		**neibs;
	size_t		point;
	char		*cmds;
	size_t		commands_count;
	int			*a;
	int			*b;
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
	char		dir;
	char		working;
	int			width;
	int			height;
	int			elem_width;
	int			elem_height;
}				t_mlx;

typedef struct	s_all
{
	t_ps		ps;
	t_mlx		mlx;
	char		prog;
}				t_all;

void	init(t_all *all, int ac, char **av);
void	push(int *src, int *dst);
void	swap(int *arr);
void	rotate(int *arr, char dir);
char	read_cmd(char *cmd,  size_t *ofset);
char	read_push(t_task *task);
char	read_swap(t_task *task);
char	read_rotate(t_task *task);
void	process_cmd(t_ps *ps, char cmd);
void	push_swap_clear_exit(t_all *all, char *message);
void	print_arr(int *a, int *b);
int		is_sorted(int *arr);
int		is_loop_sorted(int *arr, int adr);
void	check_matches(t_all *all);
void	print_lst(t_list *lst);
void	get_info(t_info *info, int *a);
void		visualisation_init(t_all *all);
void	render(t_ps *ps, t_mlx *mlx, char cmd);
size_t	get_cmd(t_all *all, char **line);

#endif
