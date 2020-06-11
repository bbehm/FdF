/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:59:23 by bbehm             #+#    #+#             */
/*   Updated: 2020/03/02 15:39:07 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Zooms in and out by pressing the + and - keys (numpad)
*/

void			print_menu(t_info *info)
{
	mlx_string_put(info->ptr_mlx, info->ptr_win, 50, 50, 0x1FFC0CB, "Options:");
	mlx_string_put(info->ptr_mlx, info->ptr_win, 50, 70, 0x1FFC0CB,
			"ESC for Exit");
	mlx_string_put(info->ptr_mlx, info->ptr_win, 50, 90, 0x1FFC0CB,
			"I for Isometric perspective");
	mlx_string_put(info->ptr_mlx, info->ptr_win, 50, 110, 0x1FFC0CB,
			"P for Parallel perspective");
	mlx_string_put(info->ptr_mlx, info->ptr_win, 50, 130, 0x1FFC0CB,
			"'B' & 'R' to change colors");
	mlx_string_put(info->ptr_mlx, info->ptr_win, 50, 150, 0x1FFC0CB,
			"'+' and '-' on numpad to zoom");
}

static int		zoom(int keycode, t_info *info)
{
	if (keycode == 78)
	{
		if (info->length_y > 1)
		{
			info->length_x = info->length_x / 2;
			info->length_y = info->length_y / 2;
		}
		mlx_clear_window(info->ptr_mlx, info->ptr_win);
		if (info->projection == 0)
			artist(info);
		else
			draw_parallel(info);
	}
	if (keycode == 69)
	{
		info->length_x = info->length_x * 2;
		info->length_y = info->length_y * 2;
		mlx_clear_window(info->ptr_mlx, info->ptr_win);
		if (info->projection == 0)
			artist(info);
		else
			draw_parallel(info);
	}
	return (0);
}

/*
** Colors changes the color of the output. 5 = 'G' --> green
** 11 = 'B' --> purple, 15 = 'R' --> orange
*/

static int		colors(int keycode, t_info *info)
{
	if (keycode == 11)
	{
		info->color = 0x802080;
		mlx_clear_window(info->ptr_mlx, info->ptr_win);
		if (info->projection == 0)
			artist(info);
		else
			draw_parallel(info);
	}
	if (keycode == 15)
	{
		info->color = 0xff7f00;
		mlx_clear_window(info->ptr_mlx, info->ptr_win);
		if (info->projection == 0)
			artist(info);
		else
			draw_parallel(info);
	}
	return (0);
}

/*
** Key-events allows the program to check for "events" from the keyboard and
** mouse. It can catch the keycode and then call a function associated to this
** event.
*/

int				key_events(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(info->ptr_mlx, info->ptr_win);
		exit(0);
	}
	if (keycode == 35)
	{
		info->projection = 1;
		draw_parallel(info);
	}
	if (keycode == 34)
	{
		info->projection = 0;
		iso_projection(info);
	}
	zoom(keycode, info);
	colors(keycode, info);
	return (0);
}
