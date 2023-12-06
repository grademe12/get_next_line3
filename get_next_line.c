/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:36:09 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/06 17:31:44 by woosupar         ###   ########.fr       */
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
		return (val);
	}
	else if (val == 0)
		return (-1);
	else
		return (-2);
	
}

/*char	*get_one_line(int fd, t_gnl *gnl)
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
			free(buf);
			return (one_line);
		}
		else if (i == BUFFER_SIZE)
		{
			gnl->temp = make_temp(buf, gnl);
			buf = 0;
		}
		break ;
	}
	return (0);
}
*/

char	*get_one_line(int fd, t_gnl *gnl)
{
	char	*buf;
	char	*one_line;
	ssize_t	temp_idx;

	temp_idx = -1;
	buf = 0;
	fun_read(fd, &buf);
	gnl->temp = make_temp(buf, gnl);
	while (gnl->temp[++temp_idx] != '\0')
		if (gnl->temp[temp_idx] == '\n')
			break;
	if (temp_idx == gnl->len)
		gnl->buffer = (gnl->buffer) * 2;
	else
	{
		one_line = make_one_line(gnl, temp_idx);
		ft_memmove(gnl, temp_idx);

	return (one_line);
}

char	*get_next_line(int fd)
{
	char				*ret;
	static	t_gnl		gnl_array[4092];

	if (fd < 0 || fd == 1 || fd == 2)
		return (0);
	gnl_array[fd].buffer = BUFFER_SIZE;
	ret = get_one_line(fd, &gnl_array[fd]);
	if (ret == 0)
		return (0);
	return (ret);
}
