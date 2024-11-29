/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:23:21 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/29 10:57:48 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		find_step(int dx, int dy);
void	isometric_projection(int *x, int *y, int z);
void draw_fdf_on_mesh(mlx_image_t *image, t_dim *dim, t_mesh *mesh);

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

// void	draw_grid(mlx_image_t *image)
// {
// 	uint32_t	color;
// 	int			rows;
// 	int			columns;
// 	int			i;
// 	int			x;
// 	int			y;
// 	int x_end = 0;
// 	int y_end = 0;

// 	x = 0;
// 	y = 0;
// 	color = 0xFFFFFFFF;
// 	rows = 20;
// 	columns = 20;
// 	i = 0;

// 	while (i < rows && (i * CELLS <= HEIGHT))
// 	{
// 		y = (i * CELLS);
// 		x = 0;
// 		x_end = ((columns-1)*CELLS);
// 		y_end = y;
// 		isometric_projection(&x, &y, mesh.z, rows, columns);
// 		isometric_projection(&x_end, &y_end, mesh.z, rows, columns);
// 		draw_line(image, x, y, x_end, y_end, color);
// 		i++;
// 	}
// 	// draw_line(image, x, y+CELLS+150, (columns*CELLS)+300, y+CELLS+150, color);
// 	i = 0;
// 	while (i < columns && (i * CELLS <= WIDTH))
// 	{
// 		x = (i * CELLS);
// 		y = 0;
// 		y_end = ((rows-1)*CELLS);
// 		x_end = x;
// 		isometric_projection(&x, &y, mesh.z, rows, columns);
// 		isometric_projection(&x_end, &y_end, mesh.z, rows, columns);
// 		draw_line(image, x, y, x_end, y_end, color);
// 		i++;
// 	}
// 	// draw_line(image, x+CELLS+300, y, x+CELLS+300, (rows*CELLS)+150, color);
// }
void	draw_grid(mlx_image_t *image, t_dim *dim)
{
	t_mesh		mesh;
	int			i;
	
	mesh.color = 0xFFFFFFFF;
	mesh.rows = 20;
	mesh.columns = 20;
	mesh.z = 1;
	i = 0;
	while (i < mesh.rows && (i * CELLS <= HEIGHT))
	{
		mesh.y_start = (i * CELLS);
		mesh.x_start = 0;
		mesh.x_end = ((mesh.columns-1)*CELLS);
		mesh.y_end = mesh.y_start;
		isometric_projection(&mesh.x_start, &mesh.y_start, mesh.z);
		isometric_projection(&mesh.x_end, &mesh.y_end, mesh.z);
		// draw_line(image, mesh.x_start, mesh.y_start, mesh.x_end, mesh.y_end, mesh.color);
		i++;
	}
	// draw_line(image, x, y+CELLS+150, (columns*CELLS)+300, y+CELLS+150, color);
	i = 0;
	while (i < mesh.columns && (i * CELLS <= WIDTH))
	{
		mesh.x_start = (i * CELLS);
		mesh.y_start = 0;
		mesh.y_end = ((mesh.rows-1)*CELLS);
		mesh.x_end = mesh.x_start;
		isometric_projection(&mesh.x_start, &mesh.y_start, mesh.z);
		isometric_projection(&mesh.x_end, &mesh.y_end, mesh.z);
		// draw_line(image, mesh.x_start, mesh.y_start, mesh.x_end, mesh.y_end, mesh.color);
		i++;
	}
	if(dim)
		draw_fdf_on_mesh(image, dim, &mesh);
}

void	isometric_projection(int *x, int *y, int z)
{
	int	pre_x;
	int	pre_y;
    // Calculate offsets to center the graph
    int offset_x = (WIDTH) / 2;
    int offset_y = (HEIGHT) / 2;

	pre_x = *x;
	pre_y = *y;
	*x = ((pre_x - pre_y) * cos(M_PI/5));
	*y = ((pre_x + pre_y) * sin(M_PI/5)) - z;
	*x += offset_x;
	*y += offset_y/2;
}

// void draw_fdf_on_mesh(mlx_image_t *image, t_dim *dim, t_mesh *mesh)
// {
//     uint32_t color = 0x99F9FF9F;
// 	t_point start;
// 	t_point	end;
// 	t_point pos_start;
// 	t_point pos_end;
// 	int i = 0;
// 	int j = 0;

// 	start.x = (abs(mesh->x_start - mesh->x_end) - (dim->width - 1))*CELLS/2;
// 	start.y = (abs(mesh->y_start - mesh->y_end) - (dim->height - 1))*CELLS/2;
// 	end.x = start.x + dim->width;
// 	end.y = start.y + dim->height;

// 	while(i+1 < dim->height)
// 	{
// 		pos_start.y = i*CELLS + start.y;
// 		j = 0;
// 		while(j+1 < dim->width)
// 		{
// 			pos_start.x = j*CELLS + start.x;
// 			pos_end.x = (j+1)*CELLS + start.x;
// 			isometric_projection(&pos_start.x, &pos_start.y, dim->values[i][j]);
// 			isometric_projection(&pos_end.x, &pos_start.y, dim->values[i][j+1]);
// 			draw_line(image, pos_start.x, pos_start.y, pos_end.x ,pos_start.y, color);
// 			// pos_end.y = (i+1)*CELLS + start.y;
// 			// isometric_projection(&pos_start.x, &pos_end.y, dim->values[i+1][j]);
// 			// draw_line(image, pos_start.x, pos_start.y, pos_start.x ,pos_end.y, color);
// 			j++;
// 		}
// 		if (i < dim->height - 1)
// 		{
// 			pos_end.x = j * CELLS + start.x;
// 			pos_end.y = (i + 1) * CELLS + start.y;
// 			isometric_projection(&pos_end.x, &pos_end.y, dim->values[i + 1][j]);
// 			draw_line(image, pos_start.x, pos_start.y, pos_end.x, pos_end.y, color);
// 		}
// 		i++;
// 	}
// }

// void draw_fdf_on_mesh(mlx_image_t *image, t_dim *dim, t_mesh *mesh)
// {
//     uint32_t color = 0x99F9FF9F; // Line color
//     t_point pos_start, pos_end;
// 	(void)mesh;
//     // Calculate starting coordinates to center the grid
//     int offset_x = (WIDTH - (dim->width - 1) * CELLS) / 2 * 0;
//     int offset_y = (HEIGHT - (dim->height - 1) * CELLS) / 2 * 0;

//     for (int i = 0; i < dim->height; i++)
//     {
//         for (int j = 0; j < dim->width; j++)
//         {
//             // Set the starting point
//             pos_start.x = j * CELLS + offset_x;
//             pos_start.y = i * CELLS + offset_y;

//             // Project starting point
//             isometric_projection(&pos_start.x, &pos_start.y, 6*dim->values[i][j]);

//             // Draw horizontal line to the right
//             if (j < dim->width - 1)
//             {
//                 pos_end.x = (j + 1) * CELLS + offset_x;
//                 pos_end.y = i * CELLS + offset_y;
//                 isometric_projection(&pos_end.x, &pos_end.y, 6*dim->values[i][j + 1]);
//                 draw_line(image, pos_start.x, pos_start.y, pos_end.x, pos_end.y, color);
//             }

//             // Draw vertical line downward
//             if (i < dim->height - 1)
//             {
//                 pos_end.x = j * CELLS + offset_x;
//                 pos_end.y = (i + 1) * CELLS + offset_y;
//                 isometric_projection(&pos_end.x, &pos_end.y, 6*dim->values[i + 1][j]);
//                 draw_line(image, pos_start.x, pos_start.y, pos_end.x, pos_end.y, color);
//             }
//         }
//     }
// }

void draw_fdf_on_mesh(mlx_image_t *image, t_dim *dim, t_mesh *mesh)
{
	uint32_t color1 = 0x00636363 ;
	uint32_t color2 = 0x00FF4444;
	t_point pos_start;
	t_point pos_end;
	(void)mesh;
	int i = 0;
	int j = 0;
	int offset_x = (WIDTH - (dim->width - 1) * CELLS) / 2 * 0;
    int offset_y = (HEIGHT - (dim->height - 1) * CELLS) / 2 * 0;
	
	while(i < dim->height)
	{
		j = 0;
		while(j < dim->width)
		{
			pos_start.y = (i * CELLS) + offset_y;
			pos_start.x = (j * CELLS) + offset_x;
			isometric_projection(&pos_start.x, &pos_start.y, 5*dim->values[i][j]);
			if(j + 1 < dim->width)
			{
				pos_end.x = ((j+1) * CELLS) + offset_x;
				pos_end.y = (i * CELLS) + offset_y;
				isometric_projection(&pos_end.x, &pos_end.y, 5*dim->values[i][j+1]);
				if(dim->values[i][j+1] || dim->values[i][j])
					draw_line(image, pos_start.x, pos_start.y, pos_end.x, pos_end.y, color2);
				else
					draw_line(image, pos_start.x, pos_start.y, pos_end.x, pos_end.y, color1);
			}
			if(i + 1 < dim->height)
			{
				pos_end.x = (j * CELLS) + offset_x;
				pos_end.y = ((i + 1)*CELLS) + offset_y;
				isometric_projection(&pos_end.x, &pos_end.y, 5*dim->values[i+1][j]);
				if(dim->values[i+1][j] || dim->values[i][j])
					draw_line(image, pos_start.x, pos_start.y, pos_end.x, pos_end.y, color2);
				else
					draw_line(image, pos_start.x, pos_start.y, pos_end.x, pos_end.y, color1);
			}
			j++;
		}
		i++;
	}
}
