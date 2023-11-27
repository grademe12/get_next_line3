/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:48:57 by woosupar          #+#    #+#             */
/*   Updated: 2023/11/26 21:18:55 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE_H"

t_gnl	*make_node_add_back(t_gnl *list, int fd)
{
	t_gnl	*new_node;

	new_node = (t_gnl *) malloc(sizeof(t_gnl));
	if (new_node == 0)
		return ;
	new_node->remain = 0;
	new_node->remain_len = 0;
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

int	ft_strchr(char *buf)
{
	int	i;

	while (*buf != '\0')
	{
		if (*buf == '\n')
			return (i);
		buf++;
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *buf, char *temp, t_gnl *list, int i)
{
	char	*join;
	int		temp_len;

	temp_len = 0;
	while (*temp++)
		temp_len++;
	join = (char *) malloc(list->remain_len + temp_len + i + 1);
	if (join == 0)
		return (0);
	while (*(list->remain))
		*join++ = *(list->remain)++;
	free(list->remain);
	while (*temp++)
		*join++ = *temp++;
	while (*buf++)
		*join++ = *buf++;
	*join = '\0';
	free(temp);
	if (i == 0)
		list->buffer = (list->buffer) * 2;
	return (join);
}

char	*move_remain(char *buf, int len, t_gnl *list)
{
	char	*move;
	int		count;

	count = 0;
	move = (char *) malloc(len);
	if (move == 0)
		return (-1);
	while (count < len)
	{
		*move++ = *buf++ ;
		count++;
	}
	list->remain_len = len - 1;
	free(buf);
	return (move);
}
