/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:09:21 by tayeo             #+#    #+#             */
/*   Updated: 2022/07/18 15:12:44 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct charrr
{
	char c;
	struct charrr *next;
} charrr;

char	*get_next_line(int fd);
charrr	*append(char c, charrr *addr);
char	*glue(charrr *line, ssize_t offset);

#endif
