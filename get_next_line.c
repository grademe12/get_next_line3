/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:36:09 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/02 16:23:50 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	fun_read(int fd, char **buf)
{
	ssize_t		val;
	
	*buf = (char *) malloc(BUFFER_SIZE + 1);
	if (*buf == 0)
		return (0);
	val = read(fd, &buf, BUFFER_SIZE);
	if (val > 0)
	{
		*buf[val] = '\0';
		return (val);
	}
	else if (val == 0)
		return (0);
	else
		return (-1);
	
}

char	*get_one_line(int fd, t_gnl *gnl)
{
	char		*buf;
	ssize_t		ret_fun_read;

	buf = 0;
	ret_fun_read = fun_read(fd, &buf);
	while (ret_fun_read > 0)
	{

	}
	if (ret_Fun_read == 0)
		return ;
}

char	*get_next_line(int fd)
{
	char				*ret;
	ssize_t				read_v;
	static	t_gnl		gnl_array[49152];

	if (fd < 0)
		return (0);
	ret = get_one_line(fd, &gnl_array[fd]);

	return (ret);
}
