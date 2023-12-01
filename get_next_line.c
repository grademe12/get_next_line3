/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:43:45 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/01 16:11:52 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_value(char	*buf, int fd, int buffer)
{
	int	val;

	buf = (char *) malloc (buffer + 1);
	if (buf == 0)
		return (-1);
	val = read(fd, buf, buffer);
	if (val > 0)
	{
		buf[val] = '\0';
		return (val);
	}
	else if (val == 0)
	{
		buf[val] = '\0';
		return (0);
	}
	else if (val == -1)
		return (-1);
}

char	*get_one_line(t_gnl *list, int fd, int i, char *ret)
{
	char	*buf;
	char	*temp;

	buf = 0;
	temp = "";
	while (read_value(buf, fd, list->buffer) > 0)
	{
		i = ft_strchr(buf);
		if (i > 0)
		{
			ret = ft_strjoin(buf, temp, list, i + 1);
			list->remain = move_remain(buf, (list->buffer) - i, list);
			return (ret);
		}
		else if (i == 0)
		{
			temp = ft_strjoin(buf, temp, list, i);
			buf = 0;
		}
	}
	if (read_value(list, fd, list->buffer) == 0)
	{
		ret = ft_strjoin(buf, temp, list, i);
		return (0);
	}
}

t_gnl	*fd_check(t_gnl **line_list, int fd)
{
	t_gnl	*cur;

	cur = *line_list;
	while (cur != 0)
	{
		if (cur->fd == fd)
			return (cur);
		else
			cur = cur->next;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_gnl	**line_list;
	t_gnl			*target_node;
	int				i;
	int				del_target;
	char			*ret;

	i = 0;
	ret = 0;
	del_target = 1;
	line_list = (t_gnl **) malloc(sizeof(t_gnl));
	if (line_list == 0)
		return (0);
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
	return (ret);
}
