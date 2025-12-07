/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickael <mickael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:10:21 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/07 18:29:10 by mickael          ###   ########.fr       */
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

int	ft_print_adr(unsigned long int nb)
{
	if (nb >= 16)
	{
		ft_print_adr(nb / 16);
		ft_print_adr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + 48);
        else if (nb <= 15 && nb > 9)
			ft_putchar((nb - 10) + 'a');
	}
	return (0);
}

int count_nb_ad(int nb)
{
	int i;
	i = 0;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_putadress(long int nb)
{
	int count;
	
	count = 0;
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		count = 5;
		return (count);
	}
	write(1, "0x", 2);
	count += 2;
	ft_print_adr(nb);
	count += count_nb_ad(nb);
	return (count);
}

int count_nb(int nb)
{
	int i;
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
	int nb1;

	nb1 = nb;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return(11);
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

int count_nb_hex(int nb)
{
	int i;
	i = 0;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_putnbr_base_xl(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0) ;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 16)
	{
		ft_putnbr_base_xl(nb / 16);
		ft_putnbr_base_xl(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + 48);
        else if (nb <= 15 && nb > 9)
			ft_putchar((nb - 10) + 'a');
	}
	return (count_nb_hex(nb));
}

int	ft_putnbr_base_xh(long int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 16)
	{
		ft_putnbr_base_xh(nb / 16);
		ft_putnbr_base_xh(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + 48);
        else if (nb <= 15 && nb > 9)
			ft_putchar((nb - 10) + 'A');
	}
	return (count_nb_hex(nb));
}

int	ft_putnbr_u(int nb)
{
	int nb1;

	nb1 = nb;	
	if (nb < 0)
	{
		write(1, "4294967254", 10);
		nb1 = 4294967254;
		return (count_nb(nb1));
	}	
	if (nb >= 10)
	{
		ft_putnbr_u(nb / 10);
		ft_putnbr_u(nb % 10);
	}
	else
	{
		if (nb <= 9) 
			ft_putchar(nb + 48);
	}
	return (count_nb(nb1));
}