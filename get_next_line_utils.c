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
	while (buf[i2] != '\0' || buf[i2] != '\n')
