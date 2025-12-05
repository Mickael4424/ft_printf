/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyer <mbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:40:02 by mbouyer           #+#    #+#             */
/*   Updated: 2025/12/05 17:20:31 by mbouyer          ###   ########.fr       */
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
int ft_putadress(int str);
int ft_putnbr(int nb);
int ft_putnbr_base_l(int nb);
int ft_putnbr_base_h(int nb);
size_t  ft_strlen(const char *str);
int ft_putnbr_u(unsigned int nb);

#endif