/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:43:45 by woosupar          #+#    #+#             */
/*   Updated: 2023/11/20 00:59:35 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE_H"

char	*get_one_line(t_gnl *list, int fd, char *one_line)
{
	size_t	val;
	size_t	i;

	i = 0;
	while (1)
	{
		val = read(fd, list->line, BUFFER_SIZE);
		if (val == -1)
			return (-1);
		while (*(list->line) != '\n' || i < BUFFER_SIZE)
		{
			*(list->line)++;
			i++;
		}
		list->line_len = list->line_len + i;
		if (*(list->line) == '\n')
		{
			one_line = (char *) malloc(i + 1);
			if (one_line == 0)
				return (0);
			ft_memmove(one_line, list->line_first, i);
			one_line[i] = '\0';
			(list->line)++;
			ft_memmove(list->line_first, list->line, BUFFER_SIZE - i);
			return (one_line);
		}
		else
			BUFFER_SIZE = (BUFFER_SIZE * 2);
	}
}

t_gnl	*fd_check(t_gnl *list, int fd)
{
	return (0);

	return (list);
}

char *get_next_line(int fd)
{
	static t_gnl	*line_list;
	t_gnl			*temp;
	char			*one_line;

	if (fd_check != 0)
	{
		temp = fd_check(line_list, fd);
		return (get_one_line(temp, fd, one_line));
	}
	else
	{
		make_node_add_back(line_list, fd);
		temp = make_node_add_back(line, list, fd);
		return (get_one_line(temp, fd, one_line));
	}
}
