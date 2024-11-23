/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:23:21 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/23 22:08:36 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		find_step(int dx, int dy);
void	isometric_projection(int *x, int *y, int z);

void	draw_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	if ((x >= 0 && x < image->width) && (y >= 0 && y < image->height))
		mlx_put_pixel(image, x, y, color);
}

void	draw_line(mlx_image_t *image, int x0, int y0, int x1, int y1,
		uint32_t color)
{
	int	xacc;
	int	yacc;
	int	dx;
	int	dy;
	int	step;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	xacc = 0;
	yacc = 0;
	step = find_step(dx, dy);
	while (1)
	{
		draw_pixel(image, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		xacc += dx;
		yacc += dy;
		if (xacc >= step)
		{
			if (x1 > x0)
				x0++;
			else
				x0--;
			xacc -= step;
		}
		if (yacc >= step)
		{
			if (y1 > y0)
				y0++;
			else
				y0--;
			yacc -= step;
		}
	}
}

int	find_step(int dx, int dy)
{
	int	step;

	step = 0;
	if (dx > dy)
		step = dx;
	else
		step = dy;
	return (step);
}

void	draw_grid(mlx_image_t *image)
{
	uint32_t	color;
	int			rows;
	int			columns;
	int			i;
	int			x;
	int			y;
	int x_end = 0;
	int y_end = 0;

	x = 300;
	y = 150;
	color = 0xFFFFFFFF;
	rows = 20;
	columns = 20;
	i = 0;

    int offset_x = WIDTH / 2;    // Centering offset for x
    int offset_y = HEIGHT / 4;  // Centering offset for y
	while (i < rows && (i * CELLS <= HEIGHT))
	{
		y = (i * CELLS)+150;
		x = 300;
		x_end = ((columns-1)*CELLS)+300;
		y_end = y;
		isometric_projection(&x, &y, 10);
		isometric_projection(&x_end, &y_end, 10);

		draw_line(image, x, y, x_end, y_end, color);
		i++;
	}
	// draw_line(image, x, y+CELLS+150, (columns*CELLS)+300, y+CELLS+150, color);
	i = 0;
	while (i < columns && (i * CELLS <= WIDTH))
	{
		x = (i * CELLS) + 300;
		y = 150;
		y_end = ((rows-1)*CELLS)+150;
		x_end = x;
		isometric_projection(&x, &y, 10);
		isometric_projection(&x_end, &y_end, 10);

		draw_line(image, x, y, x_end, y_end, color);
		i++;
	}
	// draw_line(image, x+CELLS+300, y, x+CELLS+300, (rows*CELLS)+150, color);
}

void	isometric_projection(int *x, int *y, int z)
{
	int	pre_x;
	int	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y) * 0.866;
	*y = (pre_x + pre_y) * 0.5 - z;
}



