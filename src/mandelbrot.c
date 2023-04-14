/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:36:55 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/13 15:21:45 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	mandelbrot(t_cords pos)
{
	float temp;
	float ca;
    float cb;
    int n;

	ca = 0.8;
	cb = 0.8;
	n = 0;
	while (n++ < 100)
		{
			temp = ca * ca - cb * cb + pos.x;
			cb = 2 * ca * cb + pos.y;
			ca = temp;
			if (fabs((ca + cb)) > 4.0)
				break ;
		}
	return (n);
}

void render_mandelbrot(t_vars vars, t_data img)
{
	t_cords pos;
	int		iterations;
	
	pos.x = 0;
	while (pos.x++ < X)
	{
		pos.y = 0;
		while (pos.y++ < Y)
		{
			iterations = mandelbrot(pos);
			if (iterations == 100)
				pixel_put(&img, X / 2, Y / 2, YELLOW);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}