/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:17:42 by kmummadi          #+#    #+#             */
/*   Updated: 2024/10/19 17:47:00 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(va_list args, char format)
{
	unsigned int	num;
	char			*str_num;
	int				length;

	num = va_arg(args, unsigned int);
	str_num = ft_utoa_hex(num, format);
	if (!str_num)
		return (-1);
	length = ft_putstr(str_num);
	free(str_num);
	return (length);
}
