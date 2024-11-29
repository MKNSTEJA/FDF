/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:04:13 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/24 14:29:11 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 1500
# define HEIGHT 1000
# define CELLS 40

typedef struct point
{
	int x;
	int y;
	int z;
} t_point;

typedef struct mesh
{
	int x_start;
	int y_start;
	int z;
	int y_end;
	int x_end;
	int rows;
	int columns;	
	u_int32_t color;
} t_mesh;

typedef struct dimensions
{
	int	width;
	int	height;
	int	**values;
}		t_dim;

t_dim	*setup_dim(int fd, char *file);
mlx_image_t	*initialize_window(t_dim *dim);
void	draw_line(mlx_image_t *image, int x0, int y0, int x1, int y1,
		uint32_t color);
void	draw_grid(mlx_image_t *image, t_dim *dim);
void draw_fdf_on_mesh(mlx_image_t *image, t_dim *dim, t_mesh *mesh);
#endif
