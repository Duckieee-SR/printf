/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:46:21 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/04/13 16:31:56 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_putchar(char c);
int	ft_putnbr(int c);
int	ft_putnbr_unsigned(unsigned int c);
int	ft_putstr(char *str);
int	ft_iterat(int hex);
int	ft_hex(unsigned int hex);
int	ft_lwr_hex(unsigned int hex);
int	ft_void_hex(unsigned long hex);
int	ft_printf(const char *a, ...);

#endif
