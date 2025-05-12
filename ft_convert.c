/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:19:41 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/05/11 19:51:32 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long int	nbr;
	size_t		count;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		count++;
		nbr *= -1;
	}
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n > 9)
		count += ft_unsigned_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
