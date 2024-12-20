/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:23:21 by kmummadi          #+#    #+#             */
/*   Updated: 2024/12/20 15:54:10 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isometric_projection(int *x, int *y, int z, t_dim *dim);
void		draw_fdf(mlx_image_t *image, t_dim *dim);
uint32_t	gradient_colour(t_line *pos, t_algo *dda, t_line *line,
				uint32_t color);

void	draw_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	if ((x < image->width) && (y < image->height))
	{
		mlx_put_pixel(image, x, y, color);
	}
}

void	draw_line(mlx_image_t *image, t_line *pos, uint32_t color)
{
	t_algo	dda;
	t_line	line;

	dda.dx = abs(pos->x_start - pos->x_end);
	dda.dy = abs(pos->y_end - pos->y_start);
	dda.xacc = 0;
	dda.yacc = 0;
	dda.step = find_step(dda.dx, dda.dy);
	line = *pos;
	while (1)
	{
		color = gradient_colour(pos, &dda, &line, color);
		draw_pixel(image, pos->x_start, pos->y_start, color);
		if (pos->x_end == pos->x_start && pos->y_start == pos->y_end)
			break ;
		dda.xacc += dda.dx;
		dda.yacc += dda.dy;
		dda_algorithm(pos, &dda, &line);
	}
}

void	isometric_projection(int *x, int *y, int z, t_dim *dim)
{
	int	pre_x;
	int	pre_y;
	int	z_height;
	int	offset_x;
	int	offset_y;

	offset_x = (WIDTH / 2 - ((dim->width) * dim->cells / 2));
	offset_y = (HEIGHT / 2 - (dim->height) * dim->cells / 2);
	if (((dim->max_z * 10) + offset_y) > (HEIGHT - 500))
		z_height = 1;
	else if (dim->max_z * 10 >= 100)
		z_height = 3;
	else
		z_height = 10;
	pre_x = *x;
	pre_y = *y;
	*x = ((pre_x - pre_y) * cos(M_PI / 6));
	*y = ((pre_x + pre_y) * sin(M_PI / 6)) - (z_height * z);
	if (dim->width >= 400)
		offset_x += 200;
	else if (dim->width >= 100)
		offset_x += 150;
	*x += offset_x + 300;
	*y += offset_y - 100;
}

uint32_t	gradient_colour(t_line *pos, t_algo *dda, t_line *line,
		uint32_t color)
{
	double	ratio;
	t_color	start;
	t_color	end;
	t_color	exact;

	(void)dda;
	if (color == COLOR1)
		return (COLOR1);
	ratio = pos->z_start / (double)line->max_z;
	start.r = (0xFFFF00 >> 16) & 0xFF;
	start.g = (0xFFFF00 >> 8) & 0xFF;
	start.b = 0xFFFF00 & 0xFF;
	end.r = (0xFFA500 >> 16) & 0xFF;
	end.g = (0xFFA500 >> 8) & 0xFF;
	end.b = 0xFFA500 & 0xFF;
	exact.r = start.r + (end.r - start.r) * ratio;
	exact.g = start.g + (end.g - start.g) * ratio;
	exact.b = start.b + (end.b - start.b) * ratio;
	return (exact.r << 24 | exact.g << 16 | exact.b << 8 | 0xFF);
}

// mlx_put_pixel(image, x+1, y, color);
// mlx_put_pixel(image, x, y+1, color);
// mlx_put_pixel(image, x-1, y, color);
// mlx_put_pixel(image, x, y-1, color);
// mlx_put_pixel(image, x+1, y-1, color);
// mlx_put_pixel(image, x+1, y+1, color);
// mlx_put_pixel(image, x-1, y+1, color);
// mlx_put_pixel(image, x-1, y-1, color);
