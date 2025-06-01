/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:41:17 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/05/25 15:53:16 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(char c, unsigned long n)
{
	char	*hex;
	int		count;

	count = 0;
	if (c == 'x')
		hex = LOWER_BASE;
	else if (c == 'X')
		hex = UPPER_BASE;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n >= 16)
		count += ft_puthex(c, n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	tmp_ptr;
	int				count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	tmp_ptr = (unsigned long)ptr;
	write(1, "0x", 2);
	count = 2;
	count += ft_puthex('x', tmp_ptr);
	return (count);
}

int	ft_putpercent(void)
{
	ft_putchar('%');
	return (1);
}

int	ft_conv(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(c, va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putpercent());
	return (0);
}
