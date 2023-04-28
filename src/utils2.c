/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:34:32 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/28 19:59:48 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

double	ft_map(double start, double end, double r1, double r2)
{
	return (((start * (r2 - r1)) / end) + r1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] != '\0' && s2[i] == s1[i])
	{
		s1++;
		s2++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
