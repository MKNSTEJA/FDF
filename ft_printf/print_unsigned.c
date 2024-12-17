/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:17:20 by kmummadi          #+#    #+#             */
/*   Updated: 2024/10/19 17:46:17 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(va_list args)
{
	unsigned long	num;
	char			*str_num;
	int				length;

	num = va_arg(args, unsigned long);
	str_num = ft_utoa(num);
	if (!str_num)
		return (-1);
	length = ft_putstr(str_num);
	free(str_num);
	return (length);
}
