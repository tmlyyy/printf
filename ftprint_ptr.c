/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamoliv <thamoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:40:21 by thamoliv          #+#    #+#             */
/*   Updated: 2026/06/23 15:06:01 by thamoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ftprint_ptr_hex(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		return (ftprint_ptr_hex(n / 16) + ftprint_char(base[n % 16]));
	return (ftprint_char(base[n]));
}

int	ftprint_ptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (ftprint_str("(nil)"));
	address = (unsigned long)ptr;
	count = ftprint_str("0x");
	count += ftprint_ptr_hex(address);
	return (count);
}
