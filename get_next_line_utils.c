/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:48:57 by woosupar          #+#    #+#             */
/*   Updated: 2023/11/15 21:46:08 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE_H"

void	*make_node_add_back(t_gnl *list, int fd)
{
	t_gnl	*new_node;

	new_node = (t_gnl *) malloc(sizeof(t_gnl));
	if (new_node == 0)
		return (0);
	if (list == 0)
		return (0);
	while (list->next != 0)
		list = list->next;
	new_node->line = 0;
	read(fd, new_node->line, BUFFER_SIZE);
	get_one_line(new_node, fd?);
	new_node->fd = fd;
	new_node->next = 0;
	list->next = new_node;
}

void	delete_node(t_list *gnl, void *del(void))
{
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*cd;
	char	*cs;
	size_t	num;

	if (dst == 0 && src == 0)
		return ;
	cd = (char *)dst;
	cs = (char *)src;
	num = 0;
	while (num < n)
	{
		*cd = *cs;
		cd++;
		cs++;
		num++;
	}
	return (dst);
}
