/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:48:57 by woosupar          #+#    #+#             */
/*   Updated: 2023/11/21 17:02:50 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE_H"

t_gnl	*make_node_add_back(t_gnl *list, int fd)
{
	t_gnl	*new_node;

	new_node = (t_gnl *) malloc(sizeof(t_gnl));
	if (new_node == 0)
		return (0);
	new_node->line_len = 0;
	new_node->fd = fd;
	new_node->next = 0;
	new_node->buffer = BUFFER_SIZE;
	if (list == 0)
		return (new_node);
	while (list->next != 0)
		list = list->next;
	list->next = new_node;
	return (new_node);
}

void	delete_node(t_list **gnl, int fd)
{
}

size_t	ft_strchr(char *buf, size_t buffer)
{
	size_t	i;

	i = 0;
	while (*buffer != '\0')
	{
		if (*buf == '\n')
			return (i);
		str++;
		i++;
	}
	return (0)
}

char	*ft_strjoin(char *buf, char *temp, t_gnl *list, size_t i)
{
	char	*join;

	join = (char *) malloc(list->line_len + list->buffer + i + 1);
	if (join == 0)
		return (0);
	while (*temp != '\0')
		*join++ = *temp++;
	while (*buf != '\0')
		*join++ = *buf++;
	*join = '\0';
	if (i > 0)
	return (join);
}
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cd;
	const unsigned char	*cs;

	cd = (unsigned char *)dst;
	cs = (const unsigned char *)src;

	if (cd == NULL && cs == NULL)
		return (0);

	if (src < dst && src + len >= dst)
	{
		*(cd + len + 1) = '\0';
		while (len-- > 0)
			*(cd + len) = *(cs + len);
	}
	else
	{
		while (len-- > 0)
			*cd++ = *cs++;
		*cd = '\0';
	}
	return (dst);
}
