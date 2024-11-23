/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:47:19 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/23 06:28:36 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_columns(char *line);
void	initialise_values(int fd, char *file, t_dim *dim);
void	parse_line(char *line, t_dim *dim, int i);

t_dim	*setup_dim(int fd, char *file)
{
	t_dim	*dim;
	char	*line;
	int		height;

	dim = malloc(sizeof(t_dim));
	if(!dim)
		return (NULL);
	line = get_next_line(fd);
	dim->height = 0;
	height = 0;
	dim->width = count_columns(line);
	while (line)
	{
		dim->height++;
		free(line);
		line = get_next_line(fd);
	}
	dim->values = malloc(sizeof(int *) * dim->height);
	if (!dim->values)
		return (NULL);
	while (height < dim->height)
	{
		dim->values[height] = malloc(sizeof(int) * dim->width);
		if (!dim->values[height])
			return (NULL);
		height++;
	}
	// ft_printf("Dim width: %d, dim Height: %d\n", dim->height, dim->width);
	return (initialise_values(fd, file, dim), dim);
}

int	count_columns(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			while (line[i] && line[i] != ' ' && line[i] != '\n')
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

void	initialise_values(int fd, char *file, t_dim *dim)
{
	char	*line;
	int		i;

	close(fd);
	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, dim, i);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	parse_line(char *line, t_dim *dim, int i)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (line[k])
	{
		if ((line[k] >= '0' && line[k] <= '9') && (i < dim->height
				&& j < dim->width))
		{
			// ft_printf("%d. No segfault here! i: %d, j: %d \n", k, i , j);
			dim->values[i][j] = ft_atoi(&line[k]);
			// ft_printf("%d. No segfault here! \n", k);
			while (line[k] && line[k] != ' ' && line[k] != '\n')
				k++;
			j++;
		}
		else
			k++;
	}
}
