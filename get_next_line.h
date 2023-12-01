/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:34:29 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/01 15:38:55 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	char			*remain;
	size_t			remain_len;
	size_t			buffer;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

int		read_value(char *buf, int fd, int buffer);
char	*get_one_line(t_gnl *list, int fd, int i, char *ret);
t_gnl	*fd_check(t_gnl **line_list, int fd);
char	*get_next_line(int fd);
t_gnl	*make_node_add_back(t_gnl *list, int fd);
void	delete_target_node(t_gnl **line_list, t_gnl *target_node);
int		ft_strchr(char *buf);
char	*ft_strjoin(char *buf, char *temp, t_gnl *list, int i);
char	*move_remain(char *buf, int len, t_gnl *list);

#endif
