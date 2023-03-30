/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:36:55 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/30 17:09:38 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	mandelbrot(t_vars vars, t_data img)
{
	t_cords	pos;
	int		n;

	n = 0;
	pos.x = 0.0;
	while (pos.x++ < X)
	{
		pos.y = 0.0;
		while (pos.y++ < Y)
		{
			pos.d = (pos.x - 0.5 * X) / (0.25 * X);
			pos.c = (pos.y - 0.5 * Y) / (0.25 * Y);
			pos.a = pos.d;
			pos.b = pos.c;
			while (n++ < 100)
			{
				if (!mandel_math(pos))
					break ;
			}
			if (n == 100)
				pixel_put(&img, pos.x, pos.y, YELLOW);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}

