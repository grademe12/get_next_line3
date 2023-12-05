/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:36:40 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/05 16:39:10 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *buf, t_gnl *gnl, ssize_t i)
{
	char	*join;

	int		i1;
	int		i2;
	int		i3;

	i1 = 0;
	i2 = 0;
	i3 = 0;
	join = (char *) malloc(gnl->len + i + 1);
	if (join == 0)
		return (0);
	while ((gnl->rem)[i1++] != '\0')
		join[i1] = (gnl->rem)[i1] ;
	while ((gnl->temp)[i2++] != '\0')
		join[i1 + i2] = (gnl-temp)[i2] ;
	while (buf[i3++] != '\0')
		join[i1 + i2 + i3] = buf[i3] ;
	join[i1 + i2 + i3] = '\0';
	free(buf);
	free(gnl->temp);
	free(gnl->rem);
	return (join);
}

char	*make_temp(char *buf, t_gnl *gnl, ssize_t i)
{
	ssize_t	temp_len;
	char	*str;
	char	*temp_add;

	temp_len = 0;
	temp_add = gnl->temp;
	while (gnl->temp[temp_len] != '\0')
		temp_len++;
	str = (char *) malloc(temp_len + BUFFER_SIZE + 1);
	if (str == 0)
		return (0);
	while (*(gnl->temp) != '\0')
		*str++ = *(gnl->temp)++;
	while (*buf != '\0')
		*str++ = *buf++;
	*str = '\0';
	free(temp_add);
	free(buf);
	return (str);	
}


void	make_rem(char *buf, t_gnl *gnl, ssize_t i)
{
	ssize_t	rem_i;

	rem_i = 0;
	gnl->rem = (char *) malloc(BUFFER_SIZE - i);
	if (gnl->rem == 0)
		return (0);
	(gnl->rem)[BUFFER_SIZE - i - 1] = '\0';
	gnl->len = BUFFER_SIZE - i;
	while ((gnl->rem)[rem_i] != '\0')
		(gnl->rem)[rem_i++] = buf[i++ + 1];
	free(buf);
}
