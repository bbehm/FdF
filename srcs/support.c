/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:06:49 by bbehm             #+#    #+#             */
/*   Updated: 2020/03/02 15:08:34 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Error functions, with exit and without
*/

int	exit_error(void)
{
	ft_putstr_fd("error\n", 1);
	exit(-1);
}

int	error(void)
{
	ft_putstr_fd("error\n", 1);
	return (-1);
}

/*
** Displays usage when user is doing something wrong
*/

int	usage(void)
{
	ft_putstr_fd("usage: fdf file\n", 2);
	return (0);
}

/*
** Tells us how many elements the tab has.
*/

int	size_array(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}
