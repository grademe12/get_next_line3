/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:36:40 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/08 18:21:36 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_temp(char *buf, t_gnl *gnl)
{
	ssize_t	i1;
	ssize_t	i2;
	char	*str;

	i1 = 0;
	i2 = -1;
	if (gnl->len + BUFFER_SIZE > gnl->buffer)
		gnl->buffer = (gnl->buffer) * 2;
	str = (char *) malloc(gnl->buffer + 1);
	if (str == 0)
		return (0);
	while ((gnl->temp) != 0 && (gnl->temp)[i1] != '\0')
	{
		str[i1] = (gnl->temp)[i1];
		i1++;
	}
	while (buf[++i2] != '\0')
		str[i1 + i2] = buf[i2];
	str[i1 + i2] = '\0';
	gnl->len = i1 + i2 ;
	free(buf);
	return (str);
}

char	*make_one_line(t_gnl *gnl, ssize_t temp_idx)
{
	char	*str;
	ssize_t	str_idx;

	str_idx = 0;
	str = (char *) malloc(temp_idx + 2);
	if (str == 0)
		return (0);
	while (str_idx < temp_idx + 1)
	{
		str[str_idx] = (gnl->temp)[str_idx];
		str_idx++;
	}
	str[str_idx] = '\0';
	return (str);
}

void	ft_memmove(t_gnl *gnl, ssize_t temp_idx)
{
	char	*dst;
	char	*src;
	ssize_t	a;
	ssize_t	len;

	a = 0;
	len = 0;
	dst = gnl->temp;
	src = gnl->temp + temp_idx + 1;
	if (temp_idx == gnl->len)
		temp_idx = 0;
	while (temp_idx + a < gnl->len)
	{
		dst[a] = src[a];
		a++;
	}
	while (temp_idx + a < gnl->buffer + 1)
	{
		*(src + a) = '\0';
		a++;
	}
	while (gnl->temp[len] != '\0')
		len++;
	gnl->len = len;
}
