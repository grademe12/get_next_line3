/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:36:09 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/02 19:49:53 by woosupar         ###   ########.fr       */
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
	val = read(fd, &buf, BUFFER_SIZE);
	if (val > 0)
	{
		*buf[val] = '\0';
		while (*buf[i] != '\0')
		{
			if (*buf[i] == '\n')
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
	ssize_t		i;

	buf = 0;
	i = fun_read(fd, &buf);
	while (i > 0)
	{
		if (i != BUFFER_SIZE)
			return (ft_strjoin(buf, gnl, i + 1);
		else
			ft_strjoin(buf, gnl, i);
	}
	if (ret_fun_read == 0)
		return ;
}

char	*get_next_line(int fd)
{
	char				*ret;
	static	t_gnl		gnl_array[49152];

	i = 0;
	if (fd < 0)
		return (0);
	ret = get_one_line(fd, &gnl_array[fd]);

	return (ret);
}
