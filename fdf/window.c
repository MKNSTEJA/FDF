/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:26:34 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/29 19:07:15 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_keypress(struct mlx_key_data keydata, void *data);

void	initialize_window(t_dim *dim)
{
	void		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!mlx)
		exit(-1);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
	{
		fprintf(stderr, "Error: image is NULL\n");
		exit(-1);
	}
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_key_hook(mlx, handle_keypress, mlx);
	draw_fdf(image, dim);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return ;
}

void	handle_keypress(struct mlx_key_data keydata, void *data)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window((mlx_t *)data);
}
