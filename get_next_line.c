/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:36:09 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/05 19:57:41 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	fun_read(int fd, char **buf)
{
	ssize_t		val;
	ssize_t		i;
	
	i = 0;
	*buf = (char *) malloc(BUFFER_SIZE + 1);
	if (*buf == 0)
		return (0);
	val = read(fd, *buf, BUFFER_SIZE);
	if (val > 0)
	{
		(*buf)[val] = '\0';
		while ((*buf)[i] != '\0')
		{
			if ((*buf)[i] == '\n')
				return (i);
			i++;
		}
		return (i);
	}
	else if (val == 0)
		return (-1);
	else
		return (-2);
	
}

char	*get_one_line(int fd, t_gnl *gnl)
{
	char		*buf;
	char		*one_line;
	ssize_t		i;

	buf = 0;
	while (buf == 0)
	{
		i = fun_read(fd, &buf);
		if (i != BUFFER_SIZE)
		{
			one_line = ft_strjoin(buf, gnl, i);
			make_rem(buf, gnl, i);
			free(buf);
			return (one_line);
		}
		else
		{
			one_line = gnl->temp;
			gnl->temp = make_temp(buf, gnl);
			free(one_line);
			buf = 0;
		}
	}
	one_line = ft_strjoin(buf, gnl, i);
	free(buf);
	return (one_line);
}

char	*get_next_line(int fd)
{
	char				*ret;
	static	t_gnl		gnl_array[4092];

	if (fd < 0 || fd == 1 || fd == 2)
		return (0);
	gnl_array[fd].temp = (char *) malloc(1);
	gnl_array[fd].rem = (char *) malloc(1);
	if (gnl_array[fd].temp == 0 || gnl_array[fd].rem == 0)
		return (0);
	(gnl_array[fd].temp)[0] = '\0';
	(gnl_array[fd].rem)[0] = '\0';
	ret = get_one_line(fd, &gnl_array[fd]);
	return (ret);
}
