/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:10:23 by kmummadi          #+#    #+#             */
/*   Updated: 2024/12/21 11:43:12 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		graph_ad;
	t_dim	*dim;

	if (argc != 2)
		return (-1);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 3], "fdf", 3) != 0)
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
	initialize_window(dim);
	free_all(&dim);
	close(graph_ad);
}

void	free_all(t_dim **dim)
{
	int	i;

	i = 0;
	if (!dim || !*dim)
		return ;
	while (i < (*dim)->height)
	{
		if ((*dim)->values[i] && (dim))
		{
			free((*dim)->values[i]);
			(*dim)->values[i] = NULL;
		}
		i++;
	}
	if ((*dim)->values)
	{
		free((*dim)->values);
		(*dim)->values = NULL;
	}
	if (*dim)
	{
		free(*dim);
		*dim = NULL;
	}
}

// void	print_fdf(t_dim *dim)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < dim->height)
// 	{
// 		j = 0;
// 		while (j < dim->width)
// 		{
// 			ft_printf("%d ", dim->values[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// }
