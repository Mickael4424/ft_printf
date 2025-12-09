/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyer <mbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:59:58 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/08 17:26:00 by mbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(const char *type, va_list args, int i)
{
	int	count;

	count = 0;
	if (type[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (type[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (type[i] == 'p')
		count += ft_putadress(va_arg(args, void *));
	else if (type[i] == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (type[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (type[i] == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned int));
	else if (type[i] == 'x')
		count += ft_putnbr_base_xl(va_arg(args, unsigned int));
	else if (type[i] == 'X')
		count += ft_putnbr_base_xh(va_arg(args, unsigned int));
	else if (type[i] == '%')
		count += ft_putchar('%');
	else if (type[i] == 'a')
		count += ft_putstr("my awesome 42");
	return (count);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!type)
		return (-1);
	va_start(args, type);
	i = 0;
	count = 0;
	while (type[i])
	{
		if (type[i] == '%' && type[i + 1])
		{
			i++;
			count += conversion(type, args, i);
		}
		else if (type[i] == '%' && !type[i + 1])
			break ;
		else
			count += ft_putchar(type[i]);
		i++;
	}
	va_end(args);
	return (count);
}


#include <stdio.h>

int main(void)
{
	int	count1;
	int count2;
	
	// Test 1: Texte simple
	count1 = ft_printf("Hello world!\n");
	count2 = printf("Hello world!\n");
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 2: Caractère
	count1 = ft_printf("Char: %c\n", 'A');
	count2 = printf("Char: %c\n", 'A');
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 3: Chaîne
	count1 = ft_printf("String: %s\n", "test");
	count2 = printf("String: %s\n", "test");
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 4: String NULL
	count1 = ft_printf("NULL: %s\n", NULL);
	//count2 = printf("NULL: %s\n", (char *) NULL);
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 5: Entier positif
	count1 = ft_printf("Positive: %d\n", 42);
	count2 = printf("Positive: %d\n", 42);
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 6: Entier négatif
	count1 = ft_printf("Negative: %d\n", -42);
	count2 = printf("Negative: %d\n", -42);
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 7: Unsigned
	count1 = ft_printf("Unsigned: %u\n", 4294967295);
	count2 = printf("Unsigned: %ld\n", 4294967295);
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 8: Hex minuscules
	count1 = ft_printf("Hex: %x\n", 255);
	count2 = printf("Hex: %x\n", 255);
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 9: Hex majuscules
	count1 = ft_printf("HEX: %X\n", 255);
	count2 = printf("HEX: %X\n", 255);
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 10: Pointeur
	int x = 42;
	count1 = ft_printf("Pointer: %p\n", &x);
	count2 = printf("Pointer: %p\n", &x);
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 11: Pointeur NULL
	count1 = ft_printf("NULL pointer: %p\n", NULL);
	count2 = printf("NULL pointer: %p\n", NULL);
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 12: Pourcentage
	count1 = ft_printf("Pourcent: %%\n");
	count2 = printf("Pourcent: %%\n");
	ft_printf("ft: %d, orig: %d\n\n", count1, count2);
	
	// Test 13: Mix
	count1 = ft_printf("Mix: %c %s %d %u %x %X %% %p\n", 
		'A', "test", -42, 100, 255, 255, &x);
	count2 = printf("Mix: %c %s %d %u %x %X %% %p\n", 
		'A', "test", -42, 100, 255, 255, &x);
	ft_printf("ft: %d, orig: %d\n", count1, count2);

	ft_printf("Hello %a World");
	return (0);
}
