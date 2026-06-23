/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamoliv <thamoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:24:39 by thamoliv          #+#    #+#             */
/*   Updated: 2026/06/23 15:17:25 by thamoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftprint_unsigned(unsigned int n)
{
	if (n > 9)
		return (ftprint_unsigned(n / 10) + ftprint_char((n % 10) + '0'));
	return (ftprint_char(n + '0'));
}
