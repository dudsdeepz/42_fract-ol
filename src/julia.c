/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:29:15 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/28 20:02:01 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	julia(t_cords pos)
{
	int		n;
	double	dd;
	double	aa;

	n = 0;
	while (n < pos.max_iter)
	{
		dd = pow(pos.c, 2) - pow(pos.d, 2);
		aa = 2.0 * pos.c * pos.d;
		if (fabs(dd) > 25.0)
			break ;
		pos.c = dd + pos.a;
		pos.d = aa + pos.b;
		n++;
	}
	return (n);
}

int	render_julia(t_all_in_one *all)
{
	int	iterations;
	int	color;

	iterations = julia(all->pos);
	color = get_color(iterations, all);
	if (iterations == all->pos.max_iter)
		color = BLACK;
	return (color);
}
