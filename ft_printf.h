/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:08:15 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/05/25 15:53:53 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# define LOWER_BASE "0123456789abcdef"
# define UPPER_BASE "0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_conv(char c, va_list args);
int	ft_putpercent(void);
int	ft_putptr(void *ptr);
int	ft_puthex(char c, unsigned long n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putchar(char c);

#endif