/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyer <mbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:10:21 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/05 17:30:04 by mbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	int i;
	
	i = 0;
	i = write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;
	int j;
	
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
		j++;
	}
	return (j);
}

int	ft_putadress(int str)
{
	int j;
	j = 2;
	write(1, "0x", 2);
	j = ft_putnbr_base_l(str);
	return (j);
}

int	ft_putnbr(int nb)
{
	int j;

	j = 0;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		write(1, "147483648", 9);
		return(0) ;
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
		j++;
	}
	return (j);
}

int	ft_putnbr_base_l(int nb)
{
    int j;

	j = 0;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		write(1, "147483648", 9);
		return (0) ;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 16)
	{
		ft_putnbr_base_l(nb / 16);
		ft_putnbr_base_l(nb % 16);
	}
	else
	{
		if (nb <= 9)
            ft_putchar(nb + 48);
			j++;
        if (nb <= 15 && nb > 9)
        {
			ft_putchar((nb - 10) + 'a');
			j++;
		}
	}
	return (j);
}

int	ft_putnbr_base_h(int nb)
{
	int j;
	
	j = 0;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		write(1, "147483648", 9);
		return (0);
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 16)
	{
		ft_putnbr_base_h(nb / 16);
		ft_putnbr_base_h(nb % 16);
	}
	else
	{
		if (nb <= 9)
        {
			ft_putchar(nb + 48);
			j++;
		}	
        else if (nb <= 15 && nb > 9)
        {
			ft_putchar((nb - 10) + 'A');
			j++;
		}
	}
	return (j);
}

int	ft_putnbr_u(unsigned int nb)
{
	int j;
	
	j = 0;
	if (nb >= 10)
	{
		ft_putnbr_u(nb / 10);
		ft_putnbr_u(nb % 10);
	}
	else
	{
		if (nb <= 9)
        {    
			ft_putchar(nb + 48);
			j++;
		}
	}
	return (j);
}