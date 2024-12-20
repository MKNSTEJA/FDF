/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:51:51 by kmummadi          #+#    #+#             */
/*   Updated: 2024/12/20 15:52:23 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		find_step(int dx, int dy);

void	dda_algorithm(t_line *pos, t_algo *dda, t_line *line)
{
	double	total_steps;
	double	current_steps;

	if (dda->xacc >= dda->step)
	{
		if (pos->x_end > pos->x_start)
			(pos->x_start)++;
		else
			(pos->x_start)--;
		dda->xacc -= dda->step;
	}
	if (dda->yacc >= dda->step)
	{
		if (pos->y_end > pos->y_start)
			(pos->y_start)++;
		else
			(pos->y_start)--;
		dda->yacc -= dda->step;
	}
	total_steps = sqrt(pow(line->x_end - line->x_start, 2) + pow(line->y_end
				- line->y_start, 2));
	current_steps = sqrt(pow(pos->x_start - line->x_start, 2) + pow(pos->y_start
				- line->y_start, 2));
	pos->z_start = line->z_start + (line->z_end - line->z_start)
		* (current_steps / total_steps);
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
