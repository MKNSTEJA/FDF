/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:27:00 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/19 16:17:02 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printf(const char *str, ...);
int		print_char(va_list args);
int		print_num(va_list args);
int		print_str(va_list args);
int		find_specifier(char str, va_list args);
int		print_unsigned(va_list args);
char	*ft_utoa(unsigned int n);
char	*ft_utoa_hex(unsigned long num, char format);
int		print_hexa(va_list args, char format);
int		print_pointer(va_list args);

#endif