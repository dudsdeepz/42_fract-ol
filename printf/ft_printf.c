/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:16:20 by eduarodr          #+#    #+#             */
/*   Updated: 2022/11/23 17:14:21 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		counter;

	counter = 0;
	va_list (arg);
	va_start (arg, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			counter += fmtspec(format[i], arg);
			i++;
		}
		else
			counter += ft_putchar(format[i++]);
	}
	va_end(arg);
	return (counter);
}
