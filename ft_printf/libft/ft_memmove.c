/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 07:16:20 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/13 11:22:24 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t range)
{
	unsigned char	*string_dest;
	unsigned char	*string_src;

	string_dest = (unsigned char *)dest;
	string_src = (unsigned char *)src;
	if (range == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	if ((dest > src) && dest < (src + range))
	{
		while (range--)
		{
			*(string_dest + range) = *(string_src + range);
		}
	}
	else
	{
		while (range--)
		{
			*(string_dest++) = *(string_src++);
		}
	}
	return (dest);
}
