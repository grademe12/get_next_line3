/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:43:45 by woosupar          #+#    #+#             */
/*   Updated: 2023/11/21 17:02:47 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE_H"

int		read_value(char	*buf, int fd, size_t buffer)
{
	size_t	val;

	buf = (char *) malloc (buffer);
	if (buf == 0)
		return (0);
	val = read(fd, buf, buffer;
	if (val > 0)
		return (val);
	else if (val == 0)
		return (0);
	else if (val == -1)
		return (-1);
}

char	*get_one_line(t_gnl *list, int fd, size_t i)
{
	char	*buf;
	char	*temp;

	buf = 0;
	temp = 0;
	while (read_value(buf, fd, list->buffer) > 0)
	{
		i = ft_strchr(buf, list->buffer)
		if (i > 0)
		{
			list->line = ft_strjoin(buf, temp, list, i);
			temp = ft_memmove(temp, buf, (list->buffer) - i + 1);
			list->line_len = (list->buffer) - i + 1;
		}
		if (i == 0)
		{
			temp = ft_strjoin(buf, temp, list, i);
			free(buf);
			list->buffer = (list->buffer) * 2;
		}
	}
	if (read_value(list, fd, buffer) == 0)
		fun_read_value_is_zero(buf, temp, list, i);
}

t_gnl	*fd_check(t_gnl *list, int fd)
{
	return (0);

	return (list);
}

char *get_next_line(int fd)
{
	static t_gnl	**line_list;
	t_gnl			*temp;
	size_t			i;

	i = 0;
	if (fd_check != 0)
	{
		temp = fd_check(*line_list, fd);
		return (get_one_line(temp, fd, i));
	}
	else
	{
		make_node_add_back(*line_list, fd);
		temp = make_node_add_back(*line_list, fd);
		return (get_one_line(temp, fd, i);
	}
}
