/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:51:35 by kmummadi          #+#    #+#             */
/*   Updated: 2024/12/18 19:53:40 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <ctype.h>
#include <stdint.h>

uint32_t	ft_atoi_base(const char *str)
{
	uint32_t	result;
	int			base;

	result = 0;
	base = 16;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str)
	{
		result *= base;
		if (*str >= '0' && *str <= '9')
			result += *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			result += *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			result += *str - 'A' + 10;
		else
			return (0); // Invalid character for hexadecimal
		str++;
	}
	return (result);
}
