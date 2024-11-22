/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:26:34 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/22 18:01:02 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_window(void)
{
	void *data;

	data = mlx_init(WIDTH, HEIGHT, "FDF", true);
    if(!data)
        return;
    
	mlx_loop(data);
}

int handle_keypress(void *data)
{
    mlx_t *mlx;
    mlx = data;

    if(mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);
}
