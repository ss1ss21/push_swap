/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dontgu <dontgu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:46:23 by ssonmez           #+#    #+#             */
/*   Updated: 2023/05/03 15:23:49 by dontgu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	counter(char const *s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			return (word_count);
		while (s[i] != c && s[i])
			i++;
		word_count++;
	}
	return (word_count);
}

char	*str_maker(char const *s, char c)
{
	size_t	i;
	char	*k;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	k = (char *)malloc(sizeof(char) * (i + 1));
	if (!k)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		k[i] = s[i];
		i++;
	}
	k[i] = '\0';
	return (k);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	y;
	char	**t;

	y = 0;
	i = 0;
	if (!s)
		return (0);
	t = (char **)malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!t)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			t[y] = str_maker(s + i, c);
			y++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	t[y] = 0;
	return (t);
}

