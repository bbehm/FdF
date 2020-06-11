/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:46:12 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:51:06 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_delim(char const *s, char c)
{
	int i;
	int delim;

	i = 0;
	delim = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			delim++;
		i++;
	}
	if (s[0] != '\0')
		delim++;
	return (delim);
}

static char	*ft_string(char const *str, char c, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char*)malloc(sizeof(char) * (ft_strleni(str, c, *i) + 1))))
		return (NULL);
	k = 0;
	while (str[*i] && str[*i] != c)
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		amount;
	int		i;
	int		j;

	i = 0;
	j = 0;
	amount = ft_delim(s, c);
	if (!(split = (char**)malloc(sizeof(char*) * (amount + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < amount && s[i])
	{
		split[j] = ft_string(s, c, &i);
		j++;
	}
	split[j] = NULL;
	return (split);
}
