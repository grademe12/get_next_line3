/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:43:45 by woosupar          #+#    #+#             */
/*   Updated: 2023/11/26 21:19:29 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE_H"

int		read_value(char	*buf, int fd, int buffer)
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
		i = ft_strchr(buf, list->buffer);
		if (i > 0)
		{
			ret = ft_strjoin(buf, temp, list, i);
			list->remain = move_remain(buf, (list->buffer) - i);
			free(temp);
		}
		else if (i == 0)
			temp = ft_strjoin(buf, temp, list, i);
	}
	if (read_value(list, fd, buffer) == 0)
		ret = ft_strjoin(buf, temp, list, i);
	else
		return (0);
}

t_gnl	*fd_check(t_gnl *list, int fd)
{
	return (0);

	return ();
}

char *get_next_line(int fd)
{
	static t_gnl	**line_list;
	t_gnl			*target_node;
	int				i;
	char			*ret;

	i = 0;
	ret = 0;
	target_node = fd_check(line_list, fd);
	if (target_node)
		ret = get_one_line(target_node, fd, i, ret);
	else
	{
		target_node = make_node_add_back(line_list,fd);
		ret = get_one_line(target_node, fd, i, ret);
	}
	return (ret);
}
