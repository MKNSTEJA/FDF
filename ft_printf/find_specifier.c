/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:13:24 by kmummadi          #+#    #+#             */
/*   Updated: 2024/10/19 16:26:37 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_specifier(char str, va_list args)
{
	if (str == 'i' || str == 'd')
		return (print_num(args));
	else if (str == 'c')
		return (print_char(args));
	else if (str == 's')
		return (print_str(args));
	else if (str == 'u')
		return (print_unsigned(args));
	else if (str == 'x' || str == 'X')
		return (print_hexa(args, str));
	else if (str == '%')
		return (ft_putchar('%'));
	else if (str == 'p')
		return (print_pointer(args));
	return (-1);
}
