/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickael <mickael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:59:58 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/07 18:34:27 by mickael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int conversion(const char *type, va_list args, int i)
{
	int j;
	j = 0;
	if (type[i] == 'c')
		j += ft_putchar(va_arg(args, int));
	else if (type[i] == 's')
		j += ft_putstr(va_arg(args, char*));               
	else if (type[i] == 'p')
		j += ft_putadress(va_arg(args, long int));           
	else if (type[i] == 'd')
		j += ft_putnbr(va_arg(args, int));            
	else if (type[i] == 'i')
		j += ft_putnbr(va_arg(args, int));
	else if (type[i] == 'u')
		j += ft_putnbr_u(va_arg(args, int));
	else if (type[i] == 'x')
		j += ft_putnbr_base_xl(va_arg(args, long int));
	else if (type[i] == 'X')
		j += ft_putnbr_base_xh(va_arg(args, long int));
	else if (type[i] == '%')
		j += ft_putchar('%');
	return (j);
}


int ft_printf(const char * type, ...)
{
	va_list args;
	va_start(args, type);
	int	i;
	int j;

	i = 0;
	j = 0;
	while (type[i] != '\0')
	{
		if (type[i] == '%')
		{	
			i++;
			j += conversion(type, args, i);
		}
		else
		{
			ft_putchar(type[i]);
			j++;
		}
		i++;
	}
	va_end(args);   
	return (j);
}
/*
int main(void)
{
	int result3;
	int result2;
	
	result3 = ft_printf("Char : %c\n", 'A');
	result2 = printf("Char : %c\n", 'A');
	printf("%d\n", result3);
	printf("%d\n", result2);
	
	result2 = ft_printf("String : %s\n", "Hello");
	result3 = printf("String : %s\n", "Hello");
	printf("%d\n", result2);
	printf("%d\n", result3);
	
	result2 = ft_printf("Pointer : %p\n", main);
	result3 = printf("Pointer : %p\n", main);
	printf("%d\n", result2);
	printf("%d\n", result3);
	
	result2 = ft_printf("Decimal : %d\n", -42);
	result3 = printf("Decimal : %d\n", -42);
	printf("%d\n", result2);
	printf("%d\n", result3);
	
	result2 = ft_printf("Integer : %i\n", 42);
	result3 = printf("Integer : %i\n", 42);
	printf("%d\n", result2);
	printf("%d\n", result3);
	
	result2 = ft_printf("Unsigned : %u\n", 42222);
	result3 = printf("Unsigned : %u\n", 42222);
	printf("%d\n", result2);
	printf("%d\n", result3);
	
	result2 = ft_printf("Hex low : %x\n", 25555);
	result3 = printf("Hex low : %x\n", 25555);
	printf("%d\n", result2);
	printf("%d\n", result3);
	
	result2 = ft_printf("Hex high : %X\n", 255);
	result3 = printf("Hex high : %X\n", 255);
	printf("%d\n", result2);
	printf("%d\n", result3);
	
	result2 = ft_printf("Percent : %%\n");
	result3 = printf("Percent : %%\n");
	printf("%d\n", result2);
	printf("%d\n", result3);

	result2 = ft_printf("Pointer : %p\n", main);
	result3 = printf("Pointer : %p\n", main);
	printf("%d\n", result2);
	printf("%d\n", result3);

	printf("%d\n", ft_printf("This is some serious testing...\n%c %d %i %p %% %s %u %x %X\nDid you survived it?", 42, 42, 42, 42, "42", 42, 42, 42));
	
	printf("%d\n", ft_printf("%p\n", 0));
	long tmp = 2147483647;
	printf("%d\n", ft_printf("%p\n", tmp));
	long tmp1 = -2147483647;
    printf("%d\n", ft_printf("%p\n", tmp1));
}
*/
