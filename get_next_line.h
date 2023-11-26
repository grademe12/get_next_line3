/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:43:22 by woosupar          #+#    #+#             */
/*   Updated: 2023/11/26 17:24:58 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#define BUFFER_SIZE 10

typedef				s_gnl
{
	char			*remain;
	size_t			remain_len;
	size_t			buffer;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

#endif
