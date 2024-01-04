/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssonmez <ssonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:38:35 by ssonmez           #+#    #+#             */
/*   Updated: 2022/11/28 16:53:08 by ssonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*t;

	if (!s)
		return (NULL);
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	i = 0;
	while (start < ft_strlen(s) && (len--))
		t[i++] = s[start++];
	t[i] = '\0';
	return (t);
}
