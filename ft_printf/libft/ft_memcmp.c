/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:48:50 by mknsteja          #+#    #+#             */
/*   Updated: 2024/09/24 21:25:26 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *string1, const void *string2, size_t range)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)string1;
	str2 = (unsigned char *)string2;
	if (range == 0)
		return (0);
	while ((range) && (*str1 == *str2))
	{
		str1++;
		str2++;
		range--;
	}
	if (range == 0)
		return (0);
	return (*str1 - *str2);
}
