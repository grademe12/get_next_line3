/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:43:45 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/02 12:32:14 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	read_value(char	**buf, int fd)
{
	ssize_t	val;

	*buf = (char *) malloc (BUFFER_SIZE + 1);
	if (*buf == 0)
		return (-1);
	val = read(fd, *buf, BUFFER_SIZE);
	if (val > 0)
	{
		(*buf)[val] = '\0';
		return (val);
	}
	else if (val == 0)
	{
		*(buf)[val] = '\0';
		return (0);
	}
	else
		return (-1);
}

char	*get_one_line(t_gnl *list, int fd, ssize_t i, char *ret)
{
	char	*buf;
	char	*temp;

	buf = 0;
	temp = (char *)malloc(1);
	temp[0] = '\0';
	while (read_value(&buf, fd) > 0)
	{
		i = ft_strchr(buf);
		if (i > 0 && i != BUFFER_SIZE)
		{
			ret = ft_strjoin(buf, temp, list, i + 1);
			return (ret);
		}
		else if (i == BUFFER_SIZE)
		{
			temp = ft_strjoin(buf, temp, list, i);
			buf = 0;
		}
	}
	if (read_value(&buf, fd) == 0)
	{
		ret = ft_strjoin(buf, temp, list, i);
		return (0);
	}
	return (ret);
}

t_gnl	*fd_check(t_gnl **line_list, int fd)
{
	t_gnl	*cur;

	cur = *line_list;
	if (line_list == 0 || *line_list == 0)
		return (0);
	while (cur != 0)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_gnl	**line_list;
	t_gnl			*target_node;
	ssize_t			i;
	char			*del_target;
	char			*ret;

	i = 0;
	ret = 0;
	del_target = 0;
	if (fd < 0)
		return (0);
	if (line_list == 0)
		line_list = (t_gnl **) malloc(sizeof(t_gnl *));
	*line_list = 0;
	target_node = fd_check(line_list, fd);
	if (target_node)
		del_target = get_one_line(target_node, fd, i, ret);
	else
	{
		target_node = make_node_add_back(line_list, fd);
		del_target = get_one_line(target_node, fd, i, ret);
	}
	if (del_target == 0)
		delete_target_node(line_list, target_node);
	return (del_target);
}
