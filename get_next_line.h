/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:34:29 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/06 16:28:47 by woosupar         ###   ########.fr       */
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
	ssize_t			len;
}					t_gnl;

ssize_t	fun_read(int fd, char **buf);
char	*get_one_line(int fd, t_gnl *gnl);
char	*get_next_line(int fd);
char	*ft_strjoin(char *buf, t_gnl *gnl, ssize_t i);
char	*make_temp(char *buf, t_gnl *gnl);
void	make_rem(char *buf, t_gnl *gnl, ssize_t i);

#endif
