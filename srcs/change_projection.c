/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:25:01 by bbehm             #+#    #+#             */
/*   Updated: 2020/03/02 15:34:48 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_pixelate_parallel(t_info *info, t_coord start, t_coord end)
{
	int err2;

	info->dir_x = abs(end.x - start.x);
	info->increase_x = start.x < end.x ? 1 : -1;
	info->dir_y = -abs(end.y - start.y);
	info->increase_y = start.y < end.y ? 1 : -1;
	info->err = info->dir_x + info->dir_y;
	while (start.x != end.x || start.y != end.y)
	{
		mlx_pixel_put(info->ptr_mlx, info->ptr_win, info->place_x + start.x, \
		info->place_y + start.y, info->color);
		if (start.x == end.x && start.y == end.y)
			break ;
		err2 = 2 * info->err;
		if (err2 >= info->dir_y)
		{
			info->err += info->dir_y;
			start.x += info->increase_x;
		}
		if (err2 <= info->dir_x)
		{
			info->err += info->dir_y;
			start.y += info->increase_y;
		}
	}
}

static void		draw_the_lines(t_info *info, t_coord start, t_coord end)
{
	t_coord	*hold;

	if (!(hold = (t_coord*)malloc(sizeof(t_coord))))
		exit(-1);
	hold->z = info->tab[start.y][start.x] * info->z;
	hold->z2 = info->tab[end.y][end.x] * info->z;
	hold->x = start.x * info->length_x;
	hold->x2 = end.x * info->length_x;
	hold->y = start.y * info->length_x;
	hold->y2 = end.y * info->length_x;
	start.x = hold->x;
	start.y = hold->y;
	end.x = hold->x2;
	end.y = hold->y2;
	ft_pixelate_parallel(info, start, end);
	free(hold);
}

static void		set_the_coordinates(t_info *info, int x, int y)
{
	t_coord	coordinates[2];

	coordinates[0].x = x;
	coordinates[0].y = y;
	if (x < info->max_east[1] - 1)
	{
		coordinates[1].x = x + 1;
		coordinates[1].y = y;
		draw_the_lines(info, coordinates[0], coordinates[1]);
	}
	if (y < info->max_south - 1)
	{
		coordinates[1].x = x;
		coordinates[1].y = y + 1;
		draw_the_lines(info, coordinates[0], coordinates[1]);
	}
}

/*
** Converts map to a parallel perception.
*/

void			draw_parallel(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(info->ptr_mlx, info->ptr_win);
	print_menu(info);
	while (y < info->max_south)
	{
		x = 0;
		while (x < info->max_east[1])
		{
			set_the_coordinates(info, x, y);
			x++;
		}
		y++;
	}
}

/*
** Converts map back to Isometric projection
*/

void			iso_projection(t_info *info)
{
	mlx_clear_window(info->ptr_mlx, info->ptr_win);
	initialize_map(info);
	artist(info);
}
