/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:09:44 by tayeo             #+#    #+#             */
/*   Updated: 2022/07/22 17:09:51 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	if (s == NULL)
		return (0);
	while (*s)
		s++;
	return (s - start);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*new;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (1 + l1 + l2));
	if (new == NULL)
		return (NULL);
	ft_memmove(new, s1, l1);
	ft_memmove(new + l1, s2, l2);
	*(new + l1 + l2) = '\0';
	return (new);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src || src == NULL)
		return (dest);
	if (s < d)
	{
		while (n--)
			*(d + n) = *(s + n);
		return (dest);
	}
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}
