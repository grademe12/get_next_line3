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

t_gnl	*new_node(char *str, int fd)
{
	t_gnl	*new_node;

	new_node = (t_gnl *) malloc(sizeof(t_gnl));
	if (new_node == 0)
		return (0);
	new_node->line = str;
	new_node->fd = fd;
	new_node->next = 0;
	return (new_node);
}
