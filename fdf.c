/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:10:12 by kmummadi          #+#    #+#             */
/*   Updated: 2024/12/20 15:35:50 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_vertical(mlx_image_t *image, t_dim *dim, t_ij ij, t_line pos);
void	draw_horizontal(mlx_image_t *image, t_dim *dim, t_ij ij, t_line pos);
int		calc_cells(t_dim *dim);

void	draw_fdf(mlx_image_t *image, t_dim *dim)
{
	t_line	pos;
	t_ij	ij;

	ij.i = 0;
	ij.j = 0;
	dim->cells = calc_cells(dim);
	pos.max_z = dim->max_z;
	while (ij.i < dim->height)
	{
		ij.j = 0;
		while (ij.j < dim->width)
		{
			pos.y_start = (ij.i * dim->cells);
			pos.x_start = (ij.j * dim->cells);
			pos.z_start = (double)dim->values[ij.i][ij.j];
			isometric_projection(&pos.x_start, &pos.y_start, pos.z_start, dim);
			draw_horizontal(image, dim, ij, pos);
			draw_vertical(image, dim, ij, pos);
			ij.j++;
		}
		ij.i++;
	}
}

void	draw_horizontal(mlx_image_t *image, t_dim *dim, t_ij ij, t_line pos)
{
	if (ij.j + 1 < dim->width)
	{
		pos.x_end = ((ij.j + 1) * dim->cells);
		pos.y_end = (ij.i * dim->cells);
		pos.z_end = (double)dim->values[ij.i][ij.j + 1];
		isometric_projection(&pos.x_end, &pos.y_end, pos.z_end, dim);
		if (dim->values[ij.i][ij.j + 1] > dim->min_z
			|| dim->values[ij.i][ij.j] > dim->min_z)
			draw_line(image, &pos, COLOR2);
		else
			draw_line(image, &pos, COLOR1);
	}
}

void	draw_vertical(mlx_image_t *image, t_dim *dim, t_ij ij, t_line pos)
{
	if (ij.i + 1 < dim->height)
	{
		pos.x_end = (ij.j * dim->cells);
		pos.y_end = ((ij.i + 1) * dim->cells);
		pos.z_end = (double)dim->values[ij.i + 1][ij.j];
		isometric_projection(&pos.x_end, &pos.y_end, pos.z_end, dim);
		if (dim->values[ij.i + 1][ij.j] > dim->min_z
			|| dim->values[ij.i][ij.j] > dim->min_z)
			draw_line(image, &pos, COLOR2);
		else
			draw_line(image, &pos, COLOR1);
	}
}

int	calc_cells(t_dim *dim)
{
	if (dim->height >= 400)
		return (2);
	else if (dim->height >= 100)
		return (5);
	else if (dim->height >= 50)
		return (10);
	else if (dim->height >= 25)
		return (20);
	return (40);
}
