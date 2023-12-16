/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:19:10 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/17 00:19:17 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE <= 0
#  error "error"
# endif

typedef struct s_gnl
{
	char	*temp;
	ssize_t	nl_index;
	ssize_t	len;
	ssize_t	buffer;
}				t_gnl;

char	*make_temp(char *buf, t_gnl *gnl);
char	*make_one_line(t_gnl *gnl, ssize_t nl_index, ssize_t flag);
void	ft_memmove(t_gnl *gnl, ssize_t temp_idx);
char	*get_next_line(int fd);
char	*get_one_line(int fd, t_gnl *gnl, ssize_t idx);
ssize_t	ft_read(int fd, char **buf, t_gnl *gnl);
ssize_t	check_nl_temp(t_gnl *gnl);
void	clear_gnl(t_gnl *gnl, ssize_t flag);

#endif
