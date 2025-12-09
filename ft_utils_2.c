/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyer <mbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:40:21 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/08 13:02:49 by mbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_nb(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	nb1;

	nb1 = nb;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
	return (count_nb(nb1));
}

int	ft_putnbr_base_xl(unsigned long nb)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		count += ft_putnbr_base_xl(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_putnbr_base_xh(unsigned long nb)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_putnbr_base_xh(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}
