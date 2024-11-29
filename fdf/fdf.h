/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:04:13 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/29 20:58:10 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1500
# define HEIGHT 1000
# define CELLS 40
# define COLOR1 0xFFFFFFFF
# define COLOR2 0x9F99FFFF

typedef struct point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct algo
{
	int	xacc;
	int	yacc;
	int	dx;
	int	dy;
	int	step;
}		t_algo;

typedef struct line
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;
}		t_line;

typedef struct dimensions
{
	int	width;
	int	height;
	int	**values;
}		t_dim;

typedef struct i_or_j
{
	int	i;
	int	j;
}		t_ij;

t_dim	*setup_dim(int fd, char *file);
void	initialize_window(t_dim *dim);
void	draw_line(mlx_image_t *image, t_line pos, uint32_t color);
void	dda_algorithm(t_line *pos, t_algo *dda);
void	draw_fdf(mlx_image_t *image, t_dim *dim);
int		find_step(int dx, int dy);
void	isometric_projection(int *x, int *y, int z);
#endif
