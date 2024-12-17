/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:13:52 by kmummadi          #+#    #+#             */
/*   Updated: 2024/10/19 15:43:18 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

char	*ft_utoa_hex(unsigned long num, char format)
{
	char	*hexa;
	int		length;
	char	*str_hex;

	length = len(num);
	if (num == 0)
		return (ft_strdup("0"));
	if (format == 'x')
		hexa = "0123456789abcdef";
	else if (format == 'X')
		hexa = "0123456789ABCDEF";
	str_hex = malloc(sizeof(char) * (length + 1));
	if (str_hex == NULL)
		return (NULL);
	str_hex[length] = '\0';
	while (num)
	{
		str_hex[--length] = hexa[num % 16];
		num /= 16;
	}
	return (str_hex);
}
