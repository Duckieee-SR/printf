/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:56:47 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/04/13 16:51:14 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int c)
{
	int	t;
	int	i;

	i = 0;
	t = c;
	if (t == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (t < 0)
	{
		t *= -1;
		i += ft_putchar('-');
	}
	if (t > 9)
	{
		i += ft_putnbr((t / 10));
		i += ft_putchar((t % 10 + '0'));
	}
	else
	{
		i += ft_putchar((t + '0'));
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int c)
{
	unsigned int	t;
	int				i;

	i = 0;
	t = c;
	if (t < 0)
	{
		t *= -1;
		i += ft_putchar('-');
	}
	if (t > 9)
	{
		i += ft_putnbr((t / 10));
		i += ft_putchar((t % 10 + '0'));
	}
	else
	{
		i += ft_putchar((t + '0'));
	}
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}
