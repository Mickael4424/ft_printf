/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyer <mbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:40:02 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/08 13:47:21 by mbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	conversion(const char *type, va_list args, int i);
int	ft_printf(const char *type, ...);

// ft_printf_utils_1 functions
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putadress(void *ptr);
int	ft_putnbr_u(unsigned int nb);

// ft_printf_utils_2 functions
int	count_nb(int nb);
int	ft_putnbr(int nb);
int	ft_putnbr_base_xl(unsigned long nb);
int	ft_putnbr_base_xh(unsigned long nb);

#endif
