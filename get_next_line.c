/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:58:31 by tayeo             #+#    #+#             */
/*   Updated: 2022/07/18 16:12:24 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>
char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	ssize_t	read_bytes;
	int		offset;
	charrr*	line;
	charrr* first;

	read_bytes = read(fd, &buf[0], 1);
	offset = 0;
	if (read_bytes == 0)
		return (NULL);
	while (read_bytes != 0)
	{
		if (offset == 0)
		{
			line = append(buf[0], NULL);
			first = line;
		}
		else
			line = append(buf[0], line);
		if (buf[0] == '\n')
			break;
		read_bytes = read(fd, &buf[0], 1);
		offset++;
	}
	return (glue(first, offset));
}
