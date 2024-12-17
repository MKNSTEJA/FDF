/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:07:18 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/12 14:40:01 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *string, size_t range)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)string;
	i = 0;
	while (i < range)
	{
		str[i] = 0;
		i++;
	}
}
