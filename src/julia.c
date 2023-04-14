/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:29:15 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/13 10:41:13 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	julia(t_vars vars, t_data img)
{
	t_cords	pos;
	float ca;
    float cb;
    int   n;

	pos.x = 0;
	while (pos.x++ < X)
	{
		pos.y = 0;
		while (pos.y++ < Y)
		{
			pos.d = pos.x;
			pos.c = pos.y;
			while (n++ < 100)
			{
				ca = pos.d * pos.d;
				cb = pos.c * pos.c;
				if (fabs((ca + cb - 0.8) + (2.0 * pos.d * pos.c + 0.8)) > 16)
					break ;
			}
		if (n == 100)
			pixel_put(&img, pos.x, pos.y, YELLOW);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}

void render_julia(t_vars vars, t_data img)
{
	printf("julia\n");
}