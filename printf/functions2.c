/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:21:31 by eduarodr          #+#    #+#             */
/*   Updated: 2022/11/18 10:27:45 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrhex(unsigned long int c, const char *b)
{
	int	size;

	size = 0;
	if (c >= 16)
		size += ft_nbrhex(c / 16, b);
	size += ft_putchar(b[c % 16]);
	return (size);
}

int	ft_pt(unsigned long int c, const char *b, int flag)
{
	int	size;

	size = 0;
	if (!c)
		return (write(1, "(nil)", 5));
	if (!flag)
		size += write(1, "0x", 2);
	if (c >= 16)
		size += ft_pt(c / 16, b, 1);
	size += ft_putchar(b[c % 16]);
	return (size);
}
