/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:39:04 by kelisabe          #+#    #+#             */
/*   Updated: 2022/03/04 17:07:18 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**clr(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
	return (NULL);
}

static int	len_s(char const *s, char a)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			break ;
		i++;
	}
	return (i);
}

static int	cnt(char const *s, char a)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if ((s[i] != a && s[i + 1] && s[i + 1] == a)
			|| (s[i] != a && !s[i + 1]))
			c++;
		i++;
	}
	return (c);
}

static char	**malloc_check(char const *s, char c)
{
	char	**str;

	if (!s)
		return (0);
	str = malloc(sizeof(char *) * (cnt(s, c) + 1));
	if (!str)
		return (0);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		begin;
	char	**str;

	i = 0;
	begin = 0;
	str = malloc_check(s, c);
	if (!str)
		return (0);
	while (s[i++] == c)
		begin++;
	i = -1;
	while (++i < cnt(s, c))
	{
		str[i] = ft_substr(s, begin, len_s(&s[begin], c));
		if (!str[i])
			return (clr(str));
		begin += len_s(&s[begin], c);
		while (s[begin] == c)
			begin++;
	}
	str[i] = NULL;
	return (str);
}
