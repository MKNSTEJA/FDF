/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:26:34 by kmummadi          #+#    #+#             */
/*   Updated: 2024/12/18 14:45:18 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_keypress(struct mlx_key_data keydata, void *data);
void	paint_black(mlx_image_t *image);

void	initialize_window(t_dim *dim)
{
	void		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!mlx)
		exit(-1);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		exit(-1);
	mlx_image_to_window(mlx, image, 0, 0);
	paint_black(image);
	draw_fdf(image, dim);
	mlx_key_hook(mlx, handle_keypress, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return ;
}

void	handle_keypress(struct mlx_key_data keydata, void *data)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window((mlx_t *)data);
}

void	paint_black(mlx_image_t *image)
{
	u_int32_t	i;
	u_int32_t	j;

	i = 0;
	j = 0;
	while (j < image->height)
	{
		i = 0;
		while (i < image->width)
		{
			draw_pixel(image, i, j, 0x000000FF);
			i++;
		}
		j++;
	}
}
