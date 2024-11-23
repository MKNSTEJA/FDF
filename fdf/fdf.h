/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:04:13 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/23 20:48:28 by kmummadi         ###   ########.fr       */
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

# define WIDTH 1000
# define HEIGHT 800
# define CELLS 20

typedef struct cordinates
{
	int	x;
	int	y;
	int	z;
}		t_cord;

typedef struct dimensions
{
	int	width;
	int	height;
	int	**values;
}		t_dim;

t_dim	*setup_dim(int fd, char *file);
int	initialize_window(void);
void	draw_line(mlx_image_t *image, int x0, int y0, int x1, int y1,
		uint32_t color);
void	draw_grid(mlx_image_t *image);
#endif
