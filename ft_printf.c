/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:19:03 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/05/11 20:10:12 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *forme, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	va_start(args, forme);
	while (forme[i])
	{
		if (forme[i] == '%')
		{
			i++;
			count += ft_conv(forme[i], args);
		}
		else
		{
			ft_putchar(forme[i]);
			count ++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
