/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:34:29 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/02 11:54:02 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# elif BUFFER_SIZE <= 0
#  error "error"
# endif

typedef struct s_gnl
{
	char			*remain;
	ssize_t			remain_len;
	ssize_t			buffer;
	ssize_t			fd;
	struct s_gnl	*next;
}					t_gnl;

ssize_t		read_value(char **buf, int fd);
char		*get_one_line(t_gnl *list, int fd, ssize_t i, char *ret);
t_gnl		*fd_check(t_gnl **line_list, int fd);
char		*get_next_line(int fd);
t_gnl		*make_node_add_back(t_gnl **line_list, int fd);
void		delete_target_node(t_gnl **line_list, t_gnl *target_node);
ssize_t		ft_strchr(char *buf);
char		*ft_strjoin(char *buf, char *temp, t_gnl *list, ssize_t i);
char		*move_remain(char *buf, ssize_t len, t_gnl *list);

#endif
