/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyer <mbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:10:21 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/08 13:03:16 by mbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		j = 6;
		return (j);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
		j++;
	}
	return (j);
}

int	ft_putadress(void *ptr)
{
	unsigned long	address;
	int				count;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	else if (!ptr)
	{
		return (ft_putstr("0x0"));
	}
	address = (unsigned long)ptr;
	count = ft_putstr("0x");
	count += ft_putnbr_base_xl(address);
	return (count);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_u(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
