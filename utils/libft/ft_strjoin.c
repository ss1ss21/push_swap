/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssonmez <ssonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:20:01 by ssonmez           #+#    #+#             */
/*   Updated: 2022/11/28 15:46:32 by ssonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(ft_strlen((char *)str1) + ft_strlen((char *)str2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (str1[++j])
		str[++i] = str1[j];
	j = -1;
	while (str2[++j])
		str[++i] = str2[j];
	str[++i] = '\0';
	return (str);
}
