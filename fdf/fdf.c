/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:10:12 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/29 19:14:01 by kmummadi         ###   ########.fr       */
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
			isometric_projection(&pos.x_start, &pos.y_start, 5
				* dim->values[ij.i][ij.j]);
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
		isometric_projection(&pos.x_end, &pos.y_end, 5 * dim->values[ij.i][ij.j
			+ 1]);
		if (dim->values[ij.i][ij.j + 1] || dim->values[ij.i][ij.j])
			draw_line(image, pos, COLOR2);
		else
			draw_line(image, pos, COLOR1);
	}
}

void	draw_vertical(mlx_image_t *image, t_dim *dim, t_ij ij, t_line pos)
{
	if (ij.i + 1 < dim->height)
	{
		pos.x_end = (ij.j * CELLS);
		pos.y_end = ((ij.i + 1) * CELLS);
		isometric_projection(&pos.x_end, &pos.y_end, 5 * dim->values[ij.i
			+ 1][ij.j]);
		if (dim->values[ij.i + 1][ij.j] || dim->values[ij.i][ij.j])
			draw_line(image, pos, COLOR2);
		else
			draw_line(image, pos, COLOR1);
	}
}
