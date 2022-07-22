/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:58:31 by tayeo             #+#    #+#             */
/*   Updated: 2022/07/22 17:03:33 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> //TODO! remove


char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	char	buf[BUFFER_SIZE + 1];
	ssize_t	read_bytes;
	static char	*safe;
	char		*line;

	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		buf[read_bytes] = '\0';
		if (read_bytes == 0)
		{
			line = safe;
			safe = NULL;
			return (line);
		}
		if (ft_strchr(buf, '\n') != NULL)
		{
			*ft_strchr(buf, '\n') = '\0';
			line = ft_strjoin(safe, buf);
			line = ft_strjoin(line, "\n");
			safe = ft_strjoin(NULL, ft_strchr(buf, '\0') + 1);
			if ('\0' == buf[read_bytes - 1])
				safe = NULL;
			return (line);
		}
		safe = ft_strjoin(safe, buf);
	}
}
