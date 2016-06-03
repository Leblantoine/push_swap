/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:55:47 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/16 10:16:25 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_line
{
	char			*rest;
	int				fd;
	int				ret;
	struct s_line	*next;
}				t_line;

int				get_next_line(int const fd, char **line);
#endif
