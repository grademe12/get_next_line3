/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:36:40 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/02 19:49:51 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *buf, t_gnl *gnl, ssize_t i)
{
	char	*join;

	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	join = (char *) malloc(gnl->len + i + 1);
	if (join == 0)
		return (0);
	while ((gnl->rem)[i1++] != '\0')
		join[i1] = (gnl->rem)[i1] ;

	return (join);
}

char *make_rem(char *buf, t_gnl *gnl, ssize_t i, char *rem_free)
{
	char *temp;

	if (gnl->len == 0)
	{
		gnl->rem = (char *) malloc(BUFFER_SIZE - i);
		if (gnl->rem == 0)
			return (-1);
		while (*buf != '\0')
			*(gnl->rem)++ = *buf++ + i + 1;
		*(gnl->rem) = '\0';
		return (0);
	}
	else
	{
		temp = (char *) malloc(gnl->len + BUFFER_SIZE + 1);
		if (temp == 0)
			return (0);
		while (*(gnl->rem))
			*temp++ = *(gnl->rem)++;
		while (*buf)
			*temp++ = *buf;
		*temp = '\0';
		free(rem_free);
		return (temp);
	}
}
