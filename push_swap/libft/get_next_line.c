/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:09:25 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/16 09:41:49 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(t_line *lst)
{
	int	ret;

	if ((ret = read(lst->fd, lst->rest, BUFF_SIZE)) < 0)
		return (ret);
	lst->rest[ret] = '\0';
	lst->ret = ret;
	return (1);
}

t_line	*search_lst(int const fd, t_line **lst)
{
	t_line	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_line	*create_lst(int const fd, t_line **lst)
{
	t_line *new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	new->fd = fd;
	if (!(new->rest = malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	if (read_line(new) < 0)
		return (NULL);
	new->next = *lst;
	new->ret = -1;
	*lst = new;
	return (*lst);
}

int		line_len(char *rest)
{
	int i;

	i = 0;
	while (rest[i] != '\n')
		i++;
	return (i);
}

int		get_next_line(int const fd, char **line)
{
	static t_line	*lst;
	char			*ptr;
	t_line			*tmp;

	if (line == NULL || BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	while ((tmp = search_lst(fd, &lst)) == NULL)
		if ((lst = create_lst(fd, &lst)) == NULL)
			return (-1);
	*line = ft_strnew(0);
	while (ft_strchr(tmp->rest, '\n') == NULL && tmp->ret != 0)
		if ((*line = ft_strjoin(*line, tmp->rest)))
			read_line(tmp);
	if ((ptr = ft_strchr(tmp->rest, '\n')) != NULL && tmp->ret != 0)
	{
		*line = ft_strjoin(*line, ft_strsub(tmp->rest, 0, line_len(tmp->rest)));
		if (ptr[1] == '\0')
			read_line(tmp);
		else
			tmp->rest = &ptr[1];
		return (1);
	}
	tmp->ret = -1;
	return (0);
}
