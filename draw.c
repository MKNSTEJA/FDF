/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:23:21 by kmummadi          #+#    #+#             */
/*   Updated: 2024/12/20 06:27:37 by mknsteja         ###   ########.fr       */
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
	t_algo		dda;
	t_line		line;

	dda.dx = abs(pos->x_start - pos->x_end);
	dda.dy = abs(pos->y_end - pos->y_start);
	dda.xacc = 0;
	dda.yacc = 0;
	dda.step = find_step(dda.dx, dda.dy);
	line = *pos;
	// printf("%d, %d, %d, %lf, %lf", line.x_start, line.x_end, line.y_start, line.z_start, line.z_end);
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

	offset_x = abs(WIDTH - (dim->width * dim->cells)) / 2;
	offset_y = abs(HEIGHT - (dim->height * dim->cells)) / 2;
	if(((dim->max_z * 10) + offset_y) < (HEIGHT - 100))
		z_height = 10;
	else
		z_height = abs(HEIGHT/10 - (dim->max_z * dim->cells)) / 50;
	pre_x = *x;
	pre_y = *y;
	*x = ((pre_x - pre_y) * cos(M_PI / 6));
	*y = ((pre_x + pre_y) * sin(M_PI / 6)) - (z_height * z);
	// printf("%d and %d\n", offset_x, offset_y);
  if(z_height != 10)
  {
    *x += offset_x + 500;
    *y += offset_y + 150;
  }
  else 
  {
	  *x += offset_x + 180;
	  *y += offset_y + 20;
  }
}

double	calc_ratio(t_line *pos, t_line *line, t_algo *dda)
{
	double	ratio;
	// double	total_steps;
	// double	current_steps;
	(void)dda;
	// total_steps = sqrt(pow(line->x_end - line->x_start, 2) + pow(line->y_end
	// 			- line->y_start, 2));
	// current_steps = sqrt(pow(pos->x_start - line->x_start, 2) + pow(pos->y_start
	// 			- line->y_start, 2));
	// printf("%lf vs %d\n",pos->z_start, line->max_z);
	ratio = pos->z_start / (double)line->max_z;
	// else 
	// 	ratio = 1 - (current_steps / total_steps);
	return (ratio);
}

uint32_t	gradient_colour(t_line *pos, t_algo *dda, t_line *line,
		uint32_t color)
{
	double			ratio;
	t_color			start;
	t_color			end;
	t_color			exact;
	// uint32_t		final;
  (void)dda;
	if (color == COLOR1)
		return (COLOR1);
	// if ((line->z_start == line->z_end))
// 	return (final);
	ratio = pos->z_start / (double)line->max_z;
	// if(pos->z_start == line->z_end)
    // ratio = 0;
	// {
    // printf("%lf \n", ratio);
	// }
  // ratio = 0.012;
	start.r = (0xFFFF00 >> 16) & 0xFF;
	start.g = (0xFFFF00 >> 8) & 0xFF;
	start.b = 0xFFFF00 & 0xFF;
	end.r = (0xFFA500 >> 16) & 0xFF;
	end.g = (0xFFA500 >> 8) & 0xFF;
	end.b = 0xFFA500 & 0xFF;
	exact.r = start.r + (end.r - start.r) * ratio;
	exact.g = start.g + (end.g - start.g) * ratio;
	exact.b = start.b + (end.b - start.b) * ratio;
	// final = exact.r << 24 | exact.g << 16 | exact.b << 8 | 0xFF;
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
