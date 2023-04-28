/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:36:55 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/28 20:02:12 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	mandelbrot(t_cords pos)
{
	int		n;
	double	dd;
	double	aa;

	n = 0;
	while (n < pos.max_iter)
	{
		dd = pow(pos.a, 2) - pow(pos.b, 2);
		aa = 2.0 * pos.a * pos.b;
		if (fabs(dd) > 25.0)
			break ;
		pos.a = dd + pos.c;
		pos.b = aa + pos.d;
		n++;
	}
	return (n);
}

int	render_mandelbrot(t_all_in_one *all)
{
	int	iterations;
	int	color;

	all->pos.a = all->pos.c;
	all->pos.b = all->pos.d;
	iterations = mandelbrot(all->pos);
	color = get_color(iterations, all);
	if (iterations == all->pos.max_iter)
		color = BLACK;
	return (color);
}
