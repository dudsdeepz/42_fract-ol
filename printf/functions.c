/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:06:50 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/02 10:02:19 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[++i])
		ft_putchar(s[i]);
	return (i);
}

int	ft_putnbr(int c)
{
	unsigned int	num;
	int				count;

	count = 0;
	if (c < 0)
	{
		count += ft_putchar('-');
		num = c * -1;
	}
	else
		num = c;
	if (num > 9)
		count += ft_putnbr(num / 10);
	count += ft_putchar((char)(num % 10 + 48));
	return (count);
}

int	ft_putnbr_uns(int c)
{
	unsigned int	num;
	int				count;

	count = 0;
	num = c;
	if (num > 9)
		count += ft_putnbr(num / 10);
	count += ft_putchar((char)(num % 10 + 48));
	return (count);
}

int	fmtspec(char a, va_list arg)
{
	int	counter;

	counter = 0;
	if (a == 's')
		counter += ft_putstr(va_arg(arg, char *));
	else if (a == 'd' || a == 'i')
		counter += ft_putnbr(va_arg(arg, int));
	else if (a == 'u')
		counter += ft_putnbr_uns(va_arg(arg, int));
	if (a == 'c')
		counter += ft_putchar((char)va_arg(arg, int));
	else if (a == 'x')
		counter += ft_nbrhex(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (a == 'X')
		counter += ft_nbrhex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (a == 'p')
		counter += ft_pt(va_arg(arg, unsigned long int), "0123456789abcdef", 0);
	else if (a == '%')
		counter += ft_putchar('%');
	return (counter);
}
