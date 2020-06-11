/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:26:33 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:51:24 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	if (!s)
		return ((char*)s);
	while (s && ft_isspace(s[i]))
		i++;
	if (i == len)
		return ("");
	len = len - 1;
	while (s && ft_isspace(s[len]))
		len--;
	if (i == 0 && len == 0)
		return ((char*)s);
	if (!(new = (char*)malloc(sizeof(char) * (len - i + 2))))
		return (NULL);
	while (i <= len)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
