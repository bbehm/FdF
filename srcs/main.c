/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:12:31 by bbehm             #+#    #+#             */
/*   Updated: 2020/03/02 15:08:56 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** The initialize map function saves the basic info to the struct
*/

t_info	*initialize_map(t_info *info)
{
	info->height = 1200;
	info->width = 1200;
	info->color = 0x00FFFFFF;
	info->length_x = 32;
	info->length_y = 16;
	info->z = 3;
	info->place_x = 400;
	info->place_y = 400;
	return (info);
}

/*
** The artist function draws x and y lines
*/

void	artist(t_info *info)
{
	print_menu(info);
	draw_x(info);
	draw_y(info);
}

/*
** Calculates number of lines to be utilized in mallocing of map
*/

t_info	*max_south_dist(int fd, t_info *info)
{
	char	*line;
	int		south;

	south = 0;
	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		south++;
		free(line);
	}
	info->max_south = south;
	return (info);
}

/*
** Creates map windows, draws, and checks events
*/

void	map(t_info *info)
{
	info->ptr_mlx = mlx_init();
	info->ptr_win =
		mlx_new_window(info->ptr_mlx, info->width, info->height, "FdF");
	artist(info);
	mlx_key_hook(info->ptr_win, key_events, info);
	mlx_loop(info->ptr_mlx);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_info	*info;

	if (argc != 2)
		return (usage());
	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (error());
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	info = initialize_map(info);
	info = max_south_dist(fd, info);
	close(fd);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error());
	info = set_info(fd, info);
	map(info);
	return (0);
}
