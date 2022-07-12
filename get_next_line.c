/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:58:31 by tayeo             #+#    #+#             */
/*   Updated: 2022/07/10 23:07:12 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
static char	*append(char c)
{
	static char *line;
	line = malloc(sizeof(char));
	*line = c;
	return (line);
}

char	*glue(char *line, ssize_t offset)
{
	char	*superstring;

	superstring = malloc(sizeof(char) * (offset + 2));
	superstring[offset + 1] = 0;
	while (offset >= 0)
	{
		superstring[offset] = line[offset * 32];
		//free(&line[offset * 32]);
		offset--;
	}
	return (superstring);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	ssize_t	read_bytes;
	int		offset;
	char*	line;

	read_bytes = read(fd, &buf[0], 1);
	printf("Read bytes at start: %ld\n", read_bytes);
	offset = 0;
	if (read_bytes == 0)
		return (NULL);
	while (read_bytes != 0)
	{
		if (offset == 0)
			line = append(buf[0]);
		else
			append(buf[0]);
		if (buf[0] == '\n')
			break;
		read_bytes = read(fd, &buf[0], 1);
		offset++;
	}
	return (glue(line, offset));
}

int	main(void)
{
	int fd = open("./test.txt", O_RDONLY);
	char	*ptr = NULL;
	puts(ptr);
	close(fd);
	return (0);
}
