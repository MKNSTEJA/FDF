/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:04:13 by kmummadi          #+#    #+#             */
/*   Updated: 2024/12/20 17:17:11 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define _USE_MATH_DEFINES

# include "./MLX42/include/MLX42/MLX42.h"
# include "./ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1700
# define HEIGHT 1700
# define CELLS 35
# define COLOR1 0xE0E0E055
# define COLOR2 0xFF7619FF

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}			t_point;

typedef struct s_algo
{
	int		xacc;
	int		yacc;
	int		dx;
	int		dy;
	int		step;
}			t_algo;

typedef struct s_line
{
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
	double	z_start;
	double	z_end;
	int		max_z;
}			t_line;

typedef struct s_dimensions
{
	int		width;
	int		height;
	int		**values;
	int		max_z;
	int		min_z;
	int		cells;
}			t_dim;

typedef struct s_i_or_j
{
	int		i;
	int		j;
}			t_ij;

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}			t_color;

t_dim		*setup_dim(int fd, char *file);
void		initialize_window(t_dim *dim);
void		draw_line(mlx_image_t *image, t_line *pos, uint32_t color);
void		dda_algorithm(t_line *pos, t_algo *dda, t_line *line);
void		draw_fdf(mlx_image_t *image, t_dim *dim);
int			find_step(int dx, int dy);
void		isometric_projection(int *x, int *y, int z, t_dim *dim);
void		draw_pixel(mlx_image_t *image, uint32_t x, uint32_t y,
				uint32_t color);
uint32_t	ft_atoi_base(const char *str);
void	free_all(t_dim **dim);

#endif
