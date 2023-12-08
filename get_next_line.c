/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:36:09 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/08 18:59:58 by woosupar         ###   ########.fr       */
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
	{
		free(*buf);
		return (-1);
	}
	else
	{
		free(*buf);
		return (-2);
	}
}

char	*end_of_file(t_gnl *gnl)
{
	char	*one_line;
	ssize_t	temp_len;

	if (gnl->flag == 1 || gnl->len == 0)
	{
		if (gnl->temp != 0)
		{
			free(gnl->temp);
			gnl->temp = 0;
		}
		gnl->len = 0;
		return (0);
	}
	temp_len = 0;
	gnl->temp_idx = -1;
	while (gnl->temp[++gnl->temp_idx] != '\0')
		if (gnl->temp[gnl->temp_idx] == '\n')
			break ;
	// if (gnl->temp_idx == 0)
	// {
	// 	free(gnl->temp);
	// 	gnl->temp = 0;
	// 	return (NULL);
	// }
	one_line = make_one_line(gnl, gnl->temp_idx);
	ft_memmove(gnl, gnl->temp_idx);
	while (gnl->temp[temp_len])
		temp_len++;
	if (temp_len == 0)
	{
		free(gnl->temp);
		gnl->temp = 0;
		gnl->flag = 1;
	}
	return (one_line);
}

char	*get_one_line(int fd, t_gnl *gnl)
{
	char	*buf;
	char	*one_line;
	ssize_t	check_eof;

	gnl->temp_idx = -1;
	buf = 0;
	check_eof = fun_read(fd, &buf);
	if (check_eof > 0)
	{
		gnl->flag = 0;
		gnl->temp = make_temp(buf, gnl);
		if (gnl->temp == 0)
		{
			free(gnl->temp);
			gnl->temp = 0;
			return (0);
		}
		while (gnl->temp[++gnl->temp_idx] != '\0')
			if (gnl->temp[gnl->temp_idx] == '\n')
				break ;
		// if (gnl->temp_idx == gnl->len)
		// 	gnl->buffer = (gnl->buffer) * 2;
		// else
		if (gnl->temp_idx != gnl->len)
		{
			one_line = make_one_line(gnl, gnl->temp_idx);
			ft_memmove(gnl, gnl->temp_idx);
			return (one_line);
		}
	}
	else if (check_eof == -1)
		return (end_of_file(gnl));
	else if (check_eof == -2)
	{
		free(gnl->temp);
		gnl->temp = 0;
		gnl->len = 0;
		return (NULL);
	}
	else
		return (NULL);
	return ((char *)-1);
}
#include <stdio.h>
char	*get_next_line(int fd)
{
	char				*ret;
	static t_gnl		gnl_array[4092];

	if (fd < 0 || fd == 1 || fd == 2)
		return (0);
	if (gnl_array[fd].buffer < BUFFER_SIZE)
		gnl_array[fd].buffer = BUFFER_SIZE;
	ret = get_one_line(fd, &gnl_array[fd]);
	if (ret == NULL)
		return (NULL);
	//printf("gnl->len : %zd, gnl->buffer : %zd\n", gnl_array[fd].len, gnl_array[fd].buffer);
	while (ret == (char *)-1 && gnl_array[fd].temp_idx == gnl_array[fd].len)
		ret = get_one_line(fd, &gnl_array[fd]);
	if (ret == 0)
		return (0);
	return (ret);
}
