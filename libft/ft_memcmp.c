/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:31:15 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:47:13 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	int				i;

	string1 = (unsigned char*)s1;
	string2 = (unsigned char*)s2;
	i = 0;
	while (n > 0)
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
		n--;
	}
	return (0);
}
