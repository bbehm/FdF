/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:32:53 by bbehm             #+#    #+#             */
/*   Updated: 2020/03/02 15:23:17 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include <math.h>
# include "mlx.h"

typedef struct		s_info
{
	void			*ptr_mlx;
	void			*ptr_win;
	int				height;
	int				width;
	int				z;
	int				length_x;
	int				length_y;
	int				max_south;
	int				*max_east;
	unsigned long	color;
	int				**tab;
	int				x_start;
	int				x_end;
	int				y_start;
	int				y_end;
	int				dir_x;
	int				dir_y;
	int				increase_x;
	int				increase_y;
	int				pos;
	int				place_x;
	int				place_y;
	int				projection;
	int				err;
}					t_info;

typedef struct		s_coord
{
	int				x;
	int				x2;
	int				y;
	int				y2;
	int				z;
	int				z2;
}					t_coord;

int					exit_error(void);
int					error(void);
int					usage(void);
int					size_array(char **tab);
int					key_events(int code, t_info *info);

t_info				*set_info(int fd, t_info *info);
t_info				*initialize_map(t_info *info);

void				draw_y(t_info *info);
void				draw_x(t_info *info);
void				artist(t_info *info);
void				draw_parallel(t_info *info);
void				iso_projection(t_info *info);
void				ft_free(t_info *info);
void				print_menu(t_info *info);
void				ft_pixelate(t_info *info);
void				free_int_array(int ***array);
void				free_char_array(char ***array);

#endif
