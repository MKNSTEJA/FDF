/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:11:27 by kmummadi          #+#    #+#             */
/*   Updated: 2024/10/19 16:25:18 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(const char *str, va_list args, int *count, int *i);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (handle_specifier(str, args, &count, &i) == -1)
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	handle_specifier(const char *str, va_list args, int *count, int *i)
{
	int	res;

	res = 0;
	if (str[*i] == '%' && (ft_isalpha(str[*i + 1]) || (str[*i + 1] == '%')))
	{
		res = find_specifier(str[++(*i)], args);
	}
	else
	{
		res = ft_putchar(str[*i]);
	}
	if (res == -1)
		return (-1);
	*count += res;
	return (0);
}
