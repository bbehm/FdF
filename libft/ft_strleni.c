/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strleni.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:40:07 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:49:58 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strleni(const char *s, char c, int i)
{
	size_t	len;
	int		index;

	len = 0;
	index = i;
	while (s[index] && s[index++] != c)
		len++;
	return (len);
}
