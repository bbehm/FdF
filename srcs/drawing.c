/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:43:55 by bbehm             #+#    #+#             */
/*   Updated: 2020/03/02 15:22:05 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		below_true_line(t_info *info)
{
	int e;
	int	i;

	i = 0;
	e = info->dir_y / 2;
	while (i < info->dir_y)
	{
		info->y_start += info->increase_y;
		e += info->dir_x;
		if (e > info->dir_y)
		{
			e -= info->dir_y;
			info->x_start += info->increase_x;
		}
		mlx_pixel_put(info->ptr_mlx, info->ptr_win, info->x_start,
				info->y_start, info->color);
		i++;
	}
}

static void		above_true_line(t_info *info)
{
	int e;
	int i;

	i = 0;
	e = info->dir_x / 2;
	while (i < info->dir_x)
	{
		info->x_start += info->increase_x;
		e += info->dir_y;
		if (e > info->dir_x)
		{
			e -= info->dir_x;
			info->y_start += info->increase_y;
		}
		mlx_pixel_put(info->ptr_mlx, info->ptr_win, info->x_start,
				info->y_start, info->color);
		i++;
	}
}

/*
** Define the increase value to get the direction coefficients
*/

void			ft_pixelate(t_info *info)
{
	info->increase_x = (info->x_end > info->x_start) ? 1 : -1;
	info->increase_y = (info->y_end > info->y_start) ? 1 : -1;
	info->dir_x = abs(info->x_end - info->x_start);
	info->dir_y = abs(info->y_end - info->y_start);
	if (info->dir_x > info->dir_y)
	{
		above_true_line(info);
	}
	else
		below_true_line(info);
	mlx_pixel_put(info->ptr_mlx, info->ptr_win, info->x_start,
			info->y_start, info->color);
	mlx_pixel_put(info->ptr_mlx, info->ptr_win, info->x_end, info->y_end,
			info->color);
}

/*
** Using the Bresenham's algorithm to draw the correct picture.
** First we are inserting the right information into the struct.
** The program will first execute the horizontal drawing and then vertical.
*/

void			draw_y(t_info *info)
{
	int i;

	i = 0;
	info->pos = 0;
	while (i < info->max_south - 1)
	{
		while (info->pos < info->max_east[i])
		{
			info->x_start = info->place_x + (info->pos - i) * info->length_x;
			info->y_start = info->place_y + (info->pos + i) * info->length_y
				- (info->tab[i][info->pos] * info->z);
			info->x_end = info->place_x + ((info->pos) - (i + 1)) *
				info->length_x;
			info->y_end = info->place_y + ((info->pos) + (i + 1)) *
				info->length_y - (info->tab[i + 1][info->pos] * info->z);
			ft_pixelate(info);
			info->pos++;
		}
		i++;
		info->pos = 0;
	}
}

void			draw_x(t_info *info)
{
	int i;

	i = 0;
	info->pos = 0;
	while (i < info->max_south)
	{
		while (info->pos < info->max_east[i] - 1)
		{
			info->x_start = info->place_x + (info->pos - i) * info->length_x;
			info->y_start = info->place_y + (info->pos + i) * info->length_y
				- (info->tab[i][info->pos] * info->z);
			info->x_end = info->place_x + ((info->pos + 1) - i) *
				info->length_x;
			info->y_end = info->place_y + ((info->pos + 1) + i) * info->length_y
				- (info->tab[i][info->pos + 1] * info->z);
			ft_pixelate(info);
			info->pos++;
		}
		i++;
		info->pos = 0;
	}
}
