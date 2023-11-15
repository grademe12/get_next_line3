/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:43:45 by woosupar          #+#    #+#             */
/*   Updated: 2023/11/15 21:49:02 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE_H"

char	*get_one_line(t_gnl *list, int fd)
{
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = list->line;
	buffer = (char *) malloc(BUFFER_SIZE);
	if (buffer == 0)
		return (0);
	while (*buffer != '\n' || i < BUFFER_SIZE)
	{
		buffer++;
		i++;
	}
	list->line_len = i;
	if (*buffer == '\n')
		return (buffer - i);
	else

}

t_gnl	*fd_check(int fd, t_gnl *list)
{
	return (0);

	return (list);
}

char *get_next_line(int fd)
{
	static t_gnl	*line_list;
	t_gnl			*temp;

	line_list = 0;
	if (fd_check(fd, line_list) != 0)
	{
		temp = fd_check(fd, line_list);
		if (temp->line == 0)
		{
			read(fd, temp->line, BUFFER_SIZE);
			return (temp->line);
		}
		else
			some_function_line()
	}
	if (rea
}
