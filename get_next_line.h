/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:34:29 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/06 19:39:02 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# elif BUFFER_SIZE <= 0
#  error "error"
# endif

typedef struct		s_gnl
{
	char			*temp;
	size_t			buffer;
	ssize_t			temp_idx;
	ssize_t			len;
}					t_gnl;
#endif
