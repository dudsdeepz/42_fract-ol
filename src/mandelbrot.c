/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:36:55 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/29 17:22:40 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	mandelbrot(t_vars vars, t_data img)
{
	t_cords	pos;

	pos.x = 0;
	while (pos.x++ < X)
	{
		pos.y = 0;
		while (pos.y++ < Y)
		{
			pos.n = 0;
			while (pos.n++ < 100)
			{
				pos.a = ft_map(pos.y, Y, Y / 4 + Y / 2, Y / 4);
				pos.b = ft_map(pos.x, X, X / 4, X / 2 + X / 4);
				pos.c = pos.a - pos.b / pos.a - pos.b;
				pos.d = (pos.d * pos.d) + pos.c - 1;
				if (abs(pos.d) > 200)
					break ;
			}
			if (pos.n == 100)
				pixel_put(&img, pos.x, pos.y, YELLOW);
			else
				pixel_put(&img, pos.x, pos.y, RED);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}

double	ft_map(double start, double end, double r1, double r2)
{
	return (((start * (r1 - r2)) / end) + r1);
}
