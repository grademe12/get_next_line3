/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:43:22 by woosupar          #+#    #+#             */
/*   Updated: 2023/11/20 00:59:37 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 30

typedef				s_gnl
{
	char			*line;
	char			*line_first;
	size_t			line_len;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

#endif
