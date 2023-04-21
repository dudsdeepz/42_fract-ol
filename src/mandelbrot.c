/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:36:55 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/21 17:48:31 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	mandelbrot(t_cords pos)
{
    int 	n;
	double	dd;
	double	aa;

	n = 0;
	while (n <= 100)
		{
			dd = pow(pos.c, 2) - pow(pos.d, 2);
			aa = 2.0 * pos.c * pos.d;
			printf("dd : %d\n", dd);
			if (abs(dd / 3) > 100)
				break ;
			pos.c = dd + pos.a;
			pos.d = aa + pos.b;
			printf("n: %i\n", n);
			printf("aa: %d\n", aa);
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
	while (pos.x++ < X - 1)
	{
		pos.y = 0;
		while (pos.y++ < Y - 1)
		{
			pos.c = ft_map(pos.x, X - 1, -2, 1.1);
			pos.d = ft_map(pos.y, Y - 1, -2, 1.1);
			pos.a = pos.c;
			pos.b = pos.d;
			iterations = mandelbrot(pos);
			color = get_color(iterations, 100);
			if (iterations == 100)
				color = BLACK;
			pixel_put(&img, pos.x, pos.y, color);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}
