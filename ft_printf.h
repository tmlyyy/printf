/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamoliv <thamoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:18:15 by thamoliv          #+#    #+#             */
/*   Updated: 2026/06/23 15:18:15 by thamoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_check(char type, va_list args);
int	ft_printf(const char *format, ...);
int	ftprint_char(int c);
int	ftprint_str(char *str);
int	ftprint_nbr(int n);
int	ftprint_unsigned(unsigned int n);
int	ftprint_hex(unsigned int n, char type);
int	ftprint_ptr(void *ptr);

#endif