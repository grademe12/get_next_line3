/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:48:57 by woosupar          #+#    #+#             */
/*   Updated: 2023/11/06 12:52:51 by woosupar         ###   ########.fr       */
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
	new_node->fd = fd;
	new_node->next = 0;
	list->next = new_node;
}

void	ft_del(void *ptr)
{
}

void	ft_lstclear(t_list *gnl, void *del(void))
{
}

char	*ft_join(char *s1, char *s2)
{
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	i = 0;
	while (*src != '\0')

