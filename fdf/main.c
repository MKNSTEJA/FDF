/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:10:23 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/22 17:25:47 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int	graph_ad;
	char *line;

	if (argc != 2)
		return (-1);
	graph_ad = open(argv[1], O_RDONLY);
	line = get_next_line(graph_ad);
	while(line)
	{
		line = get_next_line(graph_ad);
	}
}
