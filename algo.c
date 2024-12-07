/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:51:51 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/29 17:56:00 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		find_step(int dx, int dy);

void	dda_algorithm(t_line *pos, t_algo *dda)
{
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
