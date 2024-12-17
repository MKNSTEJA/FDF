/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:23:21 by kmummadi          #+#    #+#             */
/*   Updated: 2024/12/17 22:04:56 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(int *x, int *y, int z, t_dim *dim);
void	draw_fdf(mlx_image_t *image, t_dim *dim);

void	draw_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	if ((x >= 0 && x < image->width) && (y >= 0 && y < image->height))
	{
		mlx_put_pixel(image, x, y, color);
	}
}

void	draw_line(mlx_image_t *image, t_line pos, uint32_t color)
{
	t_algo	dda;

	dda.dx = abs(pos.x_start - pos.x_end);
	dda.dy = abs(pos.y_end - pos.y_start);
	dda.xacc = 0;
	dda.yacc = 0;
	dda.step = find_step(dda.dx, dda.dy);
	while (1)
	{
		draw_pixel(image, pos.x_start, pos.y_start, color);
		if (pos.x_end == pos.x_start && pos.y_start == pos.y_end)
			break ;
		dda.xacc += dda.dx;
		dda.yacc += dda.dy;
		dda_algorithm(&pos, &dda);
	}
}

void	isometric_projection(int *x, int *y, int z, t_dim *dim)
{
	int	pre_x;
	int	pre_y;
	int z_height;
	int	offset_x;
	int	offset_y;

	offset_x = (WIDTH - dim->width) / 2;
	offset_y = (HEIGHT - dim->height) / 2;
	z_height = 3;
	pre_x = *x;
	pre_y = *y;
	*x = ((pre_x - pre_y) * cos(M_PI / 5));
	*y = ((pre_x + pre_y) * sin(M_PI / 5)) - (z_height * z);
	*x += offset_x - 100;
	*y += offset_y/2 - 50;
}

// mlx_put_pixel(image, x+1, y, color);
// mlx_put_pixel(image, x, y+1, color);
// mlx_put_pixel(image, x-1, y, color);
// mlx_put_pixel(image, x, y-1, color);
// mlx_put_pixel(image, x+1, y-1, color);
// mlx_put_pixel(image, x+1, y+1, color);
// mlx_put_pixel(image, x-1, y+1, color);
// mlx_put_pixel(image, x-1, y-1, color);