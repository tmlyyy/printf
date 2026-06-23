/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamoliv <thamoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:18:33 by thamoliv          #+#    #+#             */
/*   Updated: 2026/06/23 14:23:27 by thamoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftprint_nbr(int n)
{
	if (n == -2147483648)
		return (ftprint_str("-2147483648"));
	if (n < 0)
		return (ftprint_char('-') + ftprint_nbr(-n));
	if (n > 9)
		return (ftprint_nbr(n / 10) + ftprint_char((n % 10) + '0'));
	return (ftprint_char(n + '0'));
}
