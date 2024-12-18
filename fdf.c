/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:10:12 by kmummadi          #+#    #+#             */
/*   Updated: 2024/12/18 18:20:22 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_vertical(mlx_image_t *image, t_dim *dim, t_ij ij, t_line pos);
void	draw_horizontal(mlx_image_t *image, t_dim *dim, t_ij ij, t_line pos);

void	draw_fdf(mlx_image_t *image, t_dim *dim)
{
	t_line	pos;
	t_ij	ij;

	ij.i = 0;
	ij.j = 0;
	while (ij.i < dim->height)
	{
		ij.j = 0;
		while (ij.j < dim->width)
		{
			pos.y_start = (ij.i * CELLS);
			pos.x_start = (ij.j * CELLS);
			pos.z_start = dim->values[ij.i][ij.j];
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
		pos.x_end = ((ij.j + 1) * CELLS);
		pos.y_end = (ij.i * CELLS);
		pos.z_end = dim->values[ij.i][ij.j + 1];
		isometric_projection(&pos.x_end, &pos.y_end, pos.z_end, dim);
		if (dim->values[ij.i][ij.j + 1] || dim->values[ij.i][ij.j])
			draw_line(image, &pos, COLOR2);
		else
			draw_line(image, &pos, COLOR1);
	}
}

void	draw_vertical(mlx_image_t *image, t_dim *dim, t_ij ij, t_line pos)
{
	if (ij.i + 1 < dim->height)
	{
		pos.x_end = (ij.j * CELLS);
		pos.y_end = ((ij.i + 1) * CELLS);
		pos.z_end = dim->values[ij.i + 1][ij.j];
		isometric_projection(&pos.x_end, &pos.y_end, pos.z_end, dim);
		if (dim->values[ij.i + 1][ij.j] || dim->values[ij.i][ij.j])
			draw_line(image, &pos, COLOR2);
		else
			draw_line(image, &pos, COLOR1);
	}
}
