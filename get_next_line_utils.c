/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:48:58 by tayeo             #+#    #+#             */
/*   Updated: 2022/07/20 16:22:04 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

t_node	*append(char c, t_node *addr)
{
	static t_node	*text;

	text = malloc(sizeof(t_node));
	if (text == NULL)
		return (NULL);
	if (addr != NULL)
		addr -> next = text;
	text -> c = c;
	return (text);
}

char	*glue(t_node *line, ssize_t offset)
{
	char	*superstring;
	int		idx;
	t_node	*temp;

	superstring = malloc(sizeof(char) * (offset + 2));
	idx = 0;
	if (superstring == NULL)
		return (NULL);
	superstring[offset + 1] = 0;
	while (idx <= offset)
	{
		superstring[idx] = line -> c;
		temp = line -> next;
		free(line);
		line = temp;
		idx++;
	}
	return (superstring);
}
