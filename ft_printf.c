/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 05:16:43 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/04/13 16:39:12 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' \
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_list(va_list arg, char c)
{
	int	bytesreturn;

	bytesreturn = 0;
	if (c == 'd')
		bytesreturn = ft_putnbr(va_arg(arg, int));
	else if (c == 'i')
		bytesreturn = ft_putnbr(va_arg(arg, int));
	else if (c == 'c')
		bytesreturn = ft_putchar(va_arg(arg, int));
	else if (c == 's')
		bytesreturn = ft_putstr(va_arg(arg, char *));
	else if (c == 'u')
		bytesreturn = ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (c == 'X')
		bytesreturn = ft_hex(va_arg(arg, unsigned int));
	else if (c == 'x')
		bytesreturn = ft_lwr_hex(va_arg(arg, unsigned int));
	else if (c == '%')
		bytesreturn = ft_putchar('%');
	else if (c == 'p')
	{
		ft_putstr("0x");
		bytesreturn = ft_void_hex(va_arg(arg, unsigned long)) + 2;
	}
	return (bytesreturn);
}

int	ft_printf(const char *a, ...)
{
	int		i;
	va_list	arg;
	int		j;

	i = 0;
	j = 0;
	va_start(arg, a);
	while (a[i])
	{
		if (a[i] != '%')
		{
			write(1, &a[i++], 1);
			j++;
		}
		else if (a[i] == '%')
		{
			if (ft_conversion(a[i + 1]))
			{
				j += ft_list(arg, a[i + 1]);
			}
			i += 2;
		}	
	}
	return (j);
}

/*int	main ()
{
	char CONA = 'D';
	int pixa = 126712;
	char *puta = -1351345;
	ft_printf("A SOPEGA E COMO O PANDA %x bue fixe", 6);
	return(0);
}*/
