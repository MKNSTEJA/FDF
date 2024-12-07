/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:10:23 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/29 20:46:16 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_all(t_dim *dim);

int	main(int argc, char **argv)
{
	int		graph_ad;
	t_dim	*dim;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc != 2)
		return (-1);
	graph_ad = open(argv[1], O_RDONLY);
	if (graph_ad == -1)
	{
		perror("Error");
		return (-1);
	}
	dim = setup_dim(graph_ad, argv[1]);
	if (!dim)
		return (-1);
	while (i < dim->height)
	{
		j = 0;
		while (j < dim->width)
		{
			ft_printf("%d ", dim->values[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
	}
	initialize_window(dim);
	free_all(dim);
	close(graph_ad);
}

static void	free_all(t_dim *dim)
{
	int	i;

	i = 0;
	while (i < dim->height)
	{
		if (dim->values[i])
			free(dim->values[i]);
		i++;
	}
	if (dim)
		free(dim);
}
