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

char *join(char *s1, char *s2)
{
}

char	*get_one_line(t_gnl *list, int fd, char *one_line)
{
	size_t	val;
	size_t	i;
	size_t	buffer;

	i = 1;
	val = 1;
	buffer = BUFFER_SIZE;
	while (val > 0)
	{
		list->line = (char *) malloc(buffer);
		if (list->line == 0)
			return (0);
		val = read(fd, list->line, buffer);
		while (*(list->line) != '\n' || i < buffer)
		{
			(list->line)++;
			i++;
		}
		if (*(list->line) == '\n')
		{
			

	}
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
	char			*one_line;

	if (fd_check != 0)
	{
		temp = fd_check(*line_list, fd);
		return (get_one_line(temp, fd, one_line));
	}
	else
	{
		make_node_add_back(*line_list, fd);
		temp = make_node_add_back(*line_list, fd);
		return (get_one_line(temp, fd, one_line));
	}
}
