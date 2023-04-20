/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:36:55 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/20 11:45:09 by eduarodr         ###   ########.fr       */
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
			dd = pow(pos.x, 2) - pow(pos.y, 2);
			aa = 2.0 * dd * pos.x * pos.y;
			if (fabs(dd) > 25.0)
				break;
			pos.x = dd + pos.c;
			pos.y = aa + pos.d;
			n += 1;
		}
	return (n);
}

void render_mandelbrot(t_vars vars, t_data img)
{
	t_cords pos;
	
	pos.x = 0;
	while (pos.x++ < X)
	{
		pos.y = 0;
		while (pos.y++ < Y)
		{
			pos.x = 3 / X * pos.x + 2;
			pos.y = 2 / Y * pos.y - 1;
			pos.c = pos.x;
			pos.d = pos.y;
			if (mandelbrot(pos) == 100)
			{
				pixel_put(&img, pos.x, pos.y, YELLOW);
			}
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}