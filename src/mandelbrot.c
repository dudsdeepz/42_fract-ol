/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:36:55 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/17 11:08:22 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	mandelbrot(t_vars vars)
{
	int		ac;
	int		bc;
	t_cords	pos;
	int		aa;
	int		bb;

	pos.y = 0;
	pos.x = 0;
	pos.n = 0;
	while (pos.n++ <= 100)
	{
		aa = pos.a + pos.a * pos.b + pos.b;
		bb = pos.a * pos.b;
		pos.a = aa;
		pos.b = bb;
		mlx_pixel_put(vars.mlx, vars.win, pos.a, pos.b, RED);
	}
}
