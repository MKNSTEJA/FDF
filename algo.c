/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:51:51 by kmummadi          #+#    #+#             */
/*   Updated: 2024/12/20 06:15:59 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		find_step(int dx, int dy);

void	dda_algorithm(t_line *pos, t_algo *dda, t_line *line)
{
	double total_steps;
  double current_steps;
	double ratio;

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
	total_steps = sqrt(pow(line->x_end - line->x_start, 2) + pow(line->y_end - line->y_start, 2));
	current_steps = sqrt(pow(line->x_end - pos->x_start, 2) + pow(line->y_end - pos->y_start, 2));
  ratio = line->z_start + (line->z_end - line->z_start) * (current_steps / total_steps);
  pos->z_start = ratio;
  // pos->z_start = line->z_start + ((line->z_end - line->z_start) / line->max_z);
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
