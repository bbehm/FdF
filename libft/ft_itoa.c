/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:36:22 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:46:06 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = NULL;
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	i = ft_intlen(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
