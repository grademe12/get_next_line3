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
	new_node->line = 0;
	new_node->line_first = new_node->line;
	new_node->line_len = 0;
	new_node->fd = fd;
	new_node->next = 0;
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;

	while (*s1 != '\0')


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
