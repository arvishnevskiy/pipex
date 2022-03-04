/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:44:49 by kelisabe          #+#    #+#             */
/*   Updated: 2022/03/04 16:34:05 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	malloc_len(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	n;

	i = start;
	n = 0;
	while (len > 0 && i < ft_strlen(s))
	{
		++i;
		++n;
		--len;
	}
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t				i;
	size_t				j;
	char				*new_s;

	if (!s)
		return (0);
	j = 0;
	i = start;
	new_s = malloc(malloc_len(s, start, len) + 1);
	if (new_s == 0)
		return (0);
	while (len > 0 && i < ft_strlen(s))
	{
		new_s[j++] = s[i++];
		--len;
	}
	new_s[j] = '\0';
	return (new_s);
}

char	*ft_strjoin(char const *s1, char const *s2)

{
	size_t	i;
	size_t	j;
	char	*s3;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (0);
	while (s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}
