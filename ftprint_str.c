/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamoliv <thamoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:04:50 by thamoliv          #+#    #+#             */
/*   Updated: 2026/06/22 19:13:38 by thamoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftprint_str(char *str)
{
	int	i;

	if (!str)
		return (ftprint_str("(null)"));
	i = 0;
	while (str[i] != '\0')
	{
		ftprint_char(str[i]);
		i++;
	}
	return (i);
}
