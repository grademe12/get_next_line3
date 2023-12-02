/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:48:57 by woosupar          #+#    #+#             */
/*   Updated: 2023/12/02 12:16:45 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*make_node_add_back(t_gnl **line_list, int fd)
{
	t_gnl	*new_node;
	t_gnl	*temp;

	temp = *line_list;
	new_node = (t_gnl *) malloc(sizeof(t_gnl));
	if (new_node == 0)
		return (0);
	new_node->remain = 0;
	new_node->remain_len = 0;
	new_node->fd = fd;
	new_node->buffer = BUFFER_SIZE;
	new_node->next = 0;
	if (*line_list == 0)
	{
		*line_list = new_node;
		return (new_node);
	}
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new_node;
	return (new_node);
}

void	delete_target_node(t_gnl **line_list, t_gnl *target_node)
{
	t_gnl	*prev_node;

	if (*line_list == NULL || target_node == NULL)
		return ;
	prev_node = NULL;
	if (*line_list == target_node)
		*line_list = target_node->next;
	else
	{
		prev_node = *line_list;
		while (prev_node->next != target_node)
			prev_node = prev_node->next;
	}
	if (prev_node == 0)
		return ;
	prev_node->next = target_node->next;
	free(target_node);
}		

ssize_t	ft_strchr(char *buf)
{
	ssize_t	i;

	i = 0;
	while (*buf != '\0')
	{
		if (*buf == '\n')
			return (i);
		buf++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *buf, char *temp, t_gnl *list, ssize_t i)
{
	char		*join;
	ssize_t		temp_len;
	int			idx;
	int			idx2;
	int			idx3;

	idx = -1;
	idx2 = -1;
	idx3 = 0;
	temp_len = 0;
	while (*temp && temp++)
		temp_len++;
	join = (char *) malloc(list->remain_len + temp_len + i + 1);
	if (join == 0)
		return (0);
	while (list->remain && *(list->remain + idx3))
	{
		*(join + idx3) = *(list->remain + idx3);
		idx3++;
	}
	free(list->remain);
	list->remain_len = 0;
	while (*(temp + ++idx))
		*(join + idx + idx3) = *(temp + idx);
	while (*(buf + ++idx2))
		*(join + idx + idx2 + idx3) = *(buf + idx2);
	*(join + idx + idx2 + idx3) = '\0';
	free(temp);
	if (i == BUFFER_SIZE)
		list->buffer = (list->buffer) * 2;
	if (i > 0 && i != BUFFER_SIZE)
		list->remain = move_remain(buf, (list->buffer) - i - 1, list);
	free(buf);
	return (join);
}

char	*move_remain(char *buf, ssize_t len, t_gnl *list)
{
	char		*move;
	ssize_t		count;

	count = 0;
	move = (char *) malloc(len);
	if (move == 0)
		return (0);
	while (count < len)
	{
		*move++ = *buf++ ;
		count++;
	}
	*move = '\0';
	list->remain_len = len - 1;
	return (move);
}
