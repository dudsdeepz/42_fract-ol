/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:36:55 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/21 13:29:18 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	mandelbrot(t_cords pos)
{
    int n;
	double	dd;
	double	aa;

	n = 0;
	while (n < 100)
		{
			dd = pow(pos.c, 2) - pow(pos.d, 2);
			aa = 2.0 * pos.c * pos.d;
			if (fabs(dd) > 15.0)
				break;
			pos.c = dd + pos.a;
			pos.d = aa + pos.b;
			n++;
		}
	return (n);
}

void render_mandelbrot(t_vars vars, t_data img)
{
	t_cords pos;
	int	iterations;
	int color;

	pos.x = 0;
	while (pos.x++ < X)
	{
		pos.y = 0;
		while (pos.y++ < Y)
		{
			pos.c = ft_map(pos.x, X - 1, -2.0, 2.0);
			pos.d = ft_map(pos.y, Y - 1, -2.0, 2.0);
			pos.a = pos.c;
			pos.b = pos.d;
			iterations = mandelbrot(pos);
			if (iterations == 100)
				pixel_put(&img, pos.x, pos.y, YELLOW);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}