/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:09:21 by tayeo             #+#    #+#             */
/*   Updated: 2022/07/20 16:21:22 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char			c;
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
t_node	*append(char c, t_node *addr);
char	*glue(t_node *line, ssize_t offset);

#endif
