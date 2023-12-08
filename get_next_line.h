/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:24:22 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/08 18:51:46 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE <= 0
#  error "error"
# endif

typedef struct		s_gnl
{
	char			*temp;
	ssize_t			buffer;
	ssize_t			temp_idx;
	ssize_t			len;
	ssize_t			flag;
}					t_gnl;

void	ft_memmove(t_gnl *gnl, ssize_t temp_idx);
char	*make_one_line(t_gnl *gnl, ssize_t temp_idx);
char	*make_temp(char *buf, t_gnl *gnl);
ssize_t	fun_read(int fd, char **buf);
char	*get_one_line(int fd, t_gnl *gnl);
char	*get_next_line(int fd);

#endif
