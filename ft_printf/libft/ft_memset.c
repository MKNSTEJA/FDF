/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:47:39 by mknsteja          #+#    #+#             */
/*   Updated: 2024/09/26 01:09:05 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *string, int value, size_t range)
{
	size_t			i;
	unsigned char	*copy;

	copy = (unsigned char *)string;
	i = 0;
	while (i < range)
	{
		*(copy + i) = value;
		i++;
	}
	return (string);
}
