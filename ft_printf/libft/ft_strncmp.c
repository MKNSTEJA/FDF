/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:44:10 by mknsteja          #+#    #+#             */
/*   Updated: 2024/09/24 21:37:47 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	m;

	m = 0;
	if (n == 0)
	{
		return (0);
	}
	while (((s1[m] != '\0') || (s2[m] != '\0')) && (m < n))
	{
		if (s1[m] != s2[m])
			return ((unsigned char)s1[m] - (unsigned char)s2[m]);
		m++;
	}
	return (0);
}
