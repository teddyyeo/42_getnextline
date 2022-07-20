/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:48:58 by tayeo             #+#    #+#             */
/*   Updated: 2022/07/18 15:12:29 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

charrr	*append(char c, charrr *addr)
{
	static charrr *text;
	//printf("Character to append: %c\n", c);
	text = malloc(sizeof(charrr));
	//printf("Current addr: %p\n", text);
	if (text == NULL)
		return (NULL);
	if (addr != NULL)
		addr -> next = text;
	text -> c = c;
	//if (addr != NULL)
	//	printf("Pointing address: %p\n\n", addr -> next);
	return (text);
}

char	*glue(charrr *line, ssize_t offset)
{
	char	*superstring;
	int		idx;
	charrr	*temp;

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
