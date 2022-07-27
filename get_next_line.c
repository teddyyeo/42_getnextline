/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:12:07 by tayeo             #+#    #+#             */
/*   Updated: 2022/07/27 15:43:19 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_bytes;
	static char	*safe;

	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		buf[read_bytes] = '\0';
		safe = ft_strjoin(safe, buf, 1);
		if (ft_strchr(safe, '\n'))
			return (saver(&safe));
		if (read_bytes == 0)
			return (end_of_file(&safe));
	}
}

char	*saver(char **safe)
{
	char	*line;
	char	*linebreak;
	char 	*temp;

	linebreak = ft_strchr(*safe, '\n');
	*linebreak = '\0';
	line = ft_strjoin(*safe, "\n", 0);
	temp = *safe;
	*safe = ft_strjoin(NULL, linebreak + 1, 0);
	free(temp);
	return (line);
}

char	*end_of_file(char **safe)
{
	char	*line;

	if (**safe == '\0' || *safe == NULL)
		return (NULL);
	line = *safe;
	*safe = NULL;
	return (line);
}
