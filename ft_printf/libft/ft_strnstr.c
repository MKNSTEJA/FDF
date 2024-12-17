/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:07:05 by mknsteja          #+#    #+#             */
/*   Updated: 2024/09/24 08:24:43 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_strlen;

	i = 0;
	j = 0;
	little_strlen = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && (i + little_strlen <= len))
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j < len) && (big[i + j]
				&& little[j]))
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
