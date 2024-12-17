/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:39:19 by mknsteja          #+#    #+#             */
/*   Updated: 2024/09/24 12:23:48 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *string, int character, size_t range)
{
	unsigned char	*str;

	str = (unsigned char *)string;
	while (range)
	{
		if (*str == (unsigned char)character)
			return ((void *)str);
		str++;
		range--;
	}
	return (NULL);
}
