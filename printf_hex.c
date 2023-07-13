/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:04:40 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/04/13 16:49:44 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_iterat(int hex)
{
	int	i;

	i = 0;
	while (hex != 0)
	{
		hex /= 16;
		i++;
	}
	return (i);
}

int	ft_hex(unsigned int hex)
{
	int		i;
	char	*hexnum;

	i = 0;
	hexnum = "0123456789ABCDEF";
	if (hex >= 16)
	{
		i += ft_hex(hex / 16);
		i += ft_hex(hex % 16);
	}
	else
		i += ft_putchar(hexnum[hex]);
	return (i);
}

int	ft_lwr_hex(unsigned int hex)
{
	int		i;
	char	*hexnum;

	i = 0;
	hexnum = "0123456789abcdef";
	if (hex >= 16)
	{
		i += ft_lwr_hex(hex / 16);
		i += ft_lwr_hex(hex % 16);
	}
	else
		i += ft_putchar(hexnum[hex]);
	return (i);
}

int	ft_void_hex(unsigned long hex)
{
	unsigned long	x;
	long			i;
	char			*hexnum;

	x = 0;
	i = 0;
	hexnum = malloc(sizeof(char) * (ft_iterat(hex)+1));
	if (hex == 0)
		i = 1;
	while (hex != 0)
	{
		hexnum[x++] = "0123456789abcdef"[hex % 16];
		hex /= 16;
		i++;
	}
	if (x == 0)
		ft_putchar('0');
	while (x != 0)
	{
		x--;
		ft_putchar(hexnum[x]);
	}
	free(hexnum);
	return (i);
}
