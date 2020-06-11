/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:14:53 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:50:40 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (n == (size_t)i)
		return (1);
	while (s1 && s2 && s1[i] == s2[i] && n > 0)
	{
		if ((n - 1) == 0)
			return (1);
		i++;
		n--;
	}
	return (0);
}
