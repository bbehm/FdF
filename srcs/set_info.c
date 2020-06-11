/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:12:24 by bbehm             #+#    #+#             */
/*   Updated: 2020/03/02 15:06:15 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Takes a line and makes an int tab of coordinaates
*/

static int	*get_coordinates(char *line)
{
	char	**tab;
	int		i;
	int		*one_line;
	int		max_east;

	i = 0;
	tab = ft_strsplit(line, ' ');
	max_east = size_array(tab);
	if (!(one_line = (int*)malloc(sizeof(int) * max_east)))
		return (NULL);
	while (tab[i] && (i < max_east))
	{
		one_line[i] = ft_atoi(tab[i]);
		i++;
	}
	free_char_array(&tab);
	return (one_line);
}

static int	bad_array(char **array)
{
	int i;
	int j;

	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != '\0')
			if (array[i][j] == '-')
			{
				j++;
				while (array[i][j] != '\0')
				{
					if (array[i][j] < '0' || array[i][j] > '9')
						return (1);
					j++;
				}
			}
			else if (array[i][j] >= '0' && array[i][j] > 9)
				j++;
			else
				return (1);
		i++;
	}
	return (0);
}

/*
** Calculates the max distance we can go to the east (x-axis)
*/

static int	max_east_dist(char *line, t_info *info, int south)
{
	int		i;
	char	**array;

	i = 0;
	array = ft_strsplit(line, ' ');
	if (bad_array(array) == 1)
		return (-1);
	while (array[i])
		i++;
	info->max_east[south] = size_array(array);
	free_char_array(&array);
	return (i);
}

/*
** For debugging
*/

static void	print_coordinates(t_info info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < info.max_south)
	{
		ft_putstr("Line ");
		ft_putnbr(i);
		ft_putstr(": ");
		while (j < info.max_east[i])
		{
			ft_putnbr(info.tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
	}
}

/*
** Malloc memory and store lines in a tab
*/

t_info		*set_info(int fd, t_info *info)
{
	char	*line;
	int		south;

	if (!(info->tab = (int**)malloc(sizeof(int*) * (info->max_south + 1))))
		exit_error();
	if (!(info->max_east = (int*)malloc(sizeof(int) * (info->max_south + 1))))
		exit_error();
	line = NULL;
	south = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((max_east_dist(line, info, south)) == -1)
			exit_error();
		if (south != 0)
			if (info->max_east[south] != info->max_east[south - 1])
				exit_error();
		if ((info->tab[south] = get_coordinates(line)) == NULL)
			exit_error();
		south++;
		free(line);
	}
	print_coordinates(*info);
	return (info);
}
