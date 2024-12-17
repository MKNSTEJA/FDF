/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:37:21 by mknsteja          #+#    #+#             */
/*   Updated: 2024/09/26 00:45:32 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int character)
{
	char	*str;

	str = (char *)string;
	while (*str)
	{
		if (*str == (unsigned char)character)
			return (str);
		str++;
	}
	if ((unsigned char)character == '\0')
		return (str);
	return (NULL);
}
