/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:42:43 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:50:31 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t count;

	count = 0;
	while (count < n && src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	while (count < n)
	{
		dst[count] = '\0';
		count++;
	}
	return (dst);
}
