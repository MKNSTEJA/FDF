/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:40:57 by mknsteja          #+#    #+#             */
/*   Updated: 2024/09/26 00:26:15 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int character)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*string)
	{
		if (*string == (char)character)
			last_occurrence = (char *)string;
		string++;
	}
	if ((char)character == '\0')
		return ((char *)string);
	return (last_occurrence);
}
