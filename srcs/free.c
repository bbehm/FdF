/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:57:32 by bbehm             #+#    #+#             */
/*   Updated: 2020/03/02 15:03:35 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_int_elems(int **array)
{
	int		i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
}

static void	free_char_elems(char **array)
{
	int		i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
}

void		free_int_array(int ***array)
{
	free_int_elems(*array);
	free(*array);
	*array = NULL;
}

void		free_char_array(char ***array)
{
	free_char_elems(*array);
	free(*array);
	*array = NULL;
}
