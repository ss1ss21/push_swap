/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dontgu <dontgu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:30:38 by ssonmez           #+#    #+#             */
/*   Updated: 2023/07/06 22:59:05 by dontgu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;
	
	i = 0;
	a = 0;
	if (!needle[i])
	{
		return ((char *) haystack);
	}
	while (haystack[i] && len > a + i)
	{
		while ((haystack[a + i] == needle[a]) && (len > a + i) && (needle[a]))
			a++;
		if (needle[a] == '\0')
			return ((char *)(haystack + i));
		a = 0;
		i++;
	}
	return (0);
}
