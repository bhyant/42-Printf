/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:19:03 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/05/25 15:52:22 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_conv(format[i], args);
		}
		else
		{
			ft_putchar(format[i]);
			count ++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
