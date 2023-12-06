/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:36:40 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/06 19:38:57 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*ft_strjoin(char *buf, t_gnl *gnl, ssize_t i)
{
	char	*join;
	int		i1;
	int		i2;
	int		i3;

	i1 = -1;
	i2 = -1;
	i3 = -1;
	join = (char *) malloc(gnl->len + i);
	if (join == 0)
		return (0);
	while ((gnl->len) != 0 && (gnl->rem)[++i1] != '\0')
		join[i1] = (gnl->rem)[i1] ;
	while ((gnl->temp)[++i2] != '\0')
		join[i1 + i2] = (gnl->temp)[i2] ;
	while (++i3 < i)
		join[i1 + i2 + i3] = buf[i3] ;
	join[i1 + i2 + i3] = '\n';
	join[i1 + i2 + i3 + 1] = '\0';
	free(gnl->temp);
	return (join);
}*/

char	*make_temp(char *buf, t_gnl *gnl)
{
	ssize_t	i1;
	ssize_t	i2;
	char	*str;

	i1 = -1;
	i2 = -1;
	str = (char *) malloc(gnl->buffer + 1);
	if (str == 0)
		return (0);
	while ((gnl->temp) != 0 && (gnl->temp)[++i1] != '\0')
		str[i1] = (gnl->temp)[i1];
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
		str[str_idx] = (gnl->temp)[temp_idx];
		str_idx++;
		temp_idx++;
	}
	str[str_idx] = '\0';
	return (str);
}

void	ft_memmove(t_gnl *gnl, ssize_t temp_idx)
{
	char	*dst;
	char	*src;
	ssize_t	a;

	a = 0;
	dst = gnl->temp;
	src = gnl->temp + temp_idx;
	while (temp_idx + a < gnl->len)
	{
		*dst = *src + a;
		a++;
	}
	while (temp_idx + a < buffer + 1)
	{
		*(src + a) = '\0';
		a++;
	}
}
/*
void	make_rem(char *buf, t_gnl *gnl, ssize_t i)
{
	ssize_t	rem_i;
	//char	*temp;

	rem_i = 0;
	//while (buf[i + rem_i] != '\0')
	gnl->rem = 0;
	gnl->rem = (char *) malloc(BUFFER_SIZE - i);
	if (gnl->rem == 0)
		return ;
	(gnl->rem)[BUFFER_SIZE - i - 1] = '\0';
	gnl->len = BUFFER_SIZE - i - 1;
	i++;
	while (i < BUFFER_SIZE)
	{
		(gnl->rem)[rem_i] = buf[i];
		rem_i++;
		i++;
	}
}
*/
