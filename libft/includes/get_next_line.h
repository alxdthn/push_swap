/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:01:17 by nalexand          #+#    #+#             */
/*   Updated: 2019/04/25 17:39:42 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define CONT (*elem)->content
# define SIZE (*elem)->content_size
# ifndef BUFF_SIZE
#  define BUFF_SIZE 7
# endif
# include "libft.h"

int	get_next_line(int fd, char **line);

#endif
