/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamoliv <thamoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:18:45 by thamoliv          #+#    #+#             */
/*   Updated: 2026/06/22 19:01:49 by thamoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_check(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	ft_check(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ftprint_char(va_arg(args, int));
	else if (type == 's')
		count += ftprint_str(va_arg(args, char *));
	else if (type == 'p')
		count += ftprint_ptr(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		count += ftprint_nbr(va_arg(args, int));
	else if (type == 'u')
		count += ftprint_unsigned(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ftprint_hex(va_arg(args, unsigned int), type);
	else if (type == '%')
		count += ftprint_char('%');
	return (count);
}
