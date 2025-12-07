/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickael <mickael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:40:02 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/07 18:29:24 by mickael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdarg.h>

/* ft_printf_utils functions*/

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putadress(long int nb);
int ft_putnbr(int nb);
int ft_putnbr_base_xl(int nb);
int ft_putnbr_base_xh(long int nb);
size_t  ft_strlen(const char *str);
int ft_putnbr_u(int nb);

#endif