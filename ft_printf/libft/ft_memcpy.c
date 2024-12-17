/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:14:23 by mknsteja          #+#    #+#             */
/*   Updated: 2024/09/20 07:16:16 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t range)
{
	unsigned char	*string;
	unsigned char	*copy;
	size_t			i;

	string = (unsigned char *)dest;
	copy = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < range)
	{
		*(string + i) = *(copy + i);
		i++;
	}
	return (dest);
}
