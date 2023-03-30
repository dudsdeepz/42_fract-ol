/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:34:32 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/30 17:08:08 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

double	ft_map(double start, double end, double r1, double r2)
{
	return (((start * (r1 - r2)) / end) + r1);
}

int mandel_math(t_cords pos)
{
    int ca;
    int cb;
    int n;
    
    ca = pos.d * pos.d - pos.c * pos.c + pos.a;
    cb = 2 * pos.d * pos.c + pos.b;
    pos.d = ca;
    pos.c = cb;
    if (fabs(pos.d + pos.c) > 16)
    {
        return (0);
    }
	return (1);
}