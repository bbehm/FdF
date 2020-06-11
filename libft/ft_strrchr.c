/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:30:41 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:50:59 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int res;

	i = 0;
	res = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			res = i;
		i++;
	}
	if (s[i] == c)
		return ((char*)s + i);
	if (res == -1)
		return (NULL);
	else
		return ((char*)s + res);
}
