/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:49:48 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:50:53 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*hay;

	i = 0;
	hay = (char*)haystack;
	if (needle[0] == '\0')
		return ((char*)hay);
	while (hay[i] != '\0' && i < (int)len)
	{
		j = 0;
		while (hay[i + j] == needle[j] && hay[i + j] != '\0' &&
				(i + j) < (int)len)
		{
			if (needle[j + 1] == '\0')
				return (&hay[i]);
			j++;
		}
		i++;
	}
	return (0);
}
