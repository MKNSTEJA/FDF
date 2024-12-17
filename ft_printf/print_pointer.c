/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:13:39 by kmummadi          #+#    #+#             */
/*   Updated: 2024/11/22 22:45:45 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	free_all(char **final_ptr, char **str_ptr);

int	print_pointer(va_list args)
{
	unsigned long	num;
	char			*str_ptr;
	int				length;
	char			*final_ptr;

	final_ptr = NULL;
	num = (unsigned long)va_arg(args, void *);
	if (num == 0)
	{
		final_ptr = ft_strdup("0x0");
		if (!final_ptr)
			return (-1);
		length = ft_putstr(final_ptr);
		free(final_ptr);
		return (length);
	}
	str_ptr = ft_utoa_hex(num, 'x');
	if (!str_ptr)
		return (-1);
	final_ptr = ft_strjoin("0x", str_ptr);
	if (!final_ptr)
		return (free_all(&final_ptr, &str_ptr));
	length = ft_putstr(final_ptr);
	(void)free_all(&final_ptr, &str_ptr);
	return (length);
}

static int	free_all(char **final_ptr, char **str_ptr)
{
	if (final_ptr && *final_ptr)
	{
		free(*final_ptr);
		*final_ptr = NULL;
	}
	if (str_ptr && *str_ptr)
	{
		free(*str_ptr);
		*str_ptr = NULL;
	}
	return (-1);
}
