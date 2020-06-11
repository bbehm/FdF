/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:07:58 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:51:12 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*hay;

	i = 0;
	hay = (char*)haystack;
	if (needle[0] == '\0')
		return ((char*)hay);
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == needle[j] && hay[i + j] != '\0')
		{
			if (needle[j + 1] == '\0')
				return (&hay[i]);
			j++;
		}
		i++;
	}
	return (0);
}
