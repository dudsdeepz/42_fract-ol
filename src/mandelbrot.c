/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:36:55 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/24 17:01:27 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	mandelbrot(t_cords pos)
{
    int 	n;
	double	dd;
	double	aa;

	n = 0;
	while (n < 100)
		{
			dd = pow(pos.a, 2) - pow(pos.b, 2);
			aa = 2.0 * pos.a * pos.b;
			if (fabs(dd) > 15.0)
				break ;
			pos.a = dd + pos.c;
			pos.b = aa + pos.d;
			n++;
		}
	return (n);
}

void render_mandelbrot(t_vars vars, t_data img)
{
	t_cords pos;
	int	iterations;
	int color;

	pos.x = -1;
	pos.y = 0;
	while (++pos.x < X)
	{
		pos.y = 0;
		pos.c = ft_map(pos.x, X - 1, -2.5, 2.5);
		// pos.c = pos.x;
		while (pos.y++ < Y)
		{
			// pos.d = pos.y;
			pos.d = ft_map(pos.y, Y - 1, -2.5, 2.5);
			pos.a = pos.c;
			pos.b = pos.d;
			iterations = mandelbrot(pos);
			color = get_color(iterations, 25);
			if (iterations == 100)
				color = BLACK;
			pixel_put(&img, pos.x , pos.y, color);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}
