/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:29:15 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/26 11:49:44 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	julia(t_cords pos)
{
	int 	n;
	double	dd;
	double	aa;
	double 	two;

	n = 0;
	while (n < pos.max_iter)
		{
			dd = pow(pos.c, 2) - pow(pos.d, 2);
			aa = 2.0 * pos.c * pos.d;
			if (fabs(dd) > 25.0)
				break ;
			pos.c = dd + pos.a;
			pos.d = aa + pos.b;
			n++;
		}
	return (n);

}

int render_julia(t_all_in_one *all)
{
	int	iterations;
	int color;
	
	all->pos.x = -1;
	while (++all->pos.x < X)
	{
		all->pos.y = -1;
		while (++all->pos.y < Y)
		{
			all->pos.c = ft_map(all->pos.x, X - 1, -all->pos.zoom, all->pos.zoom);
			all->pos.d = ft_map(all->pos.y, Y - 1, -all->pos.zoom, all->pos.zoom);
			iterations = julia(all->pos);
			color = get_color(iterations, all->pos);
			if (iterations == all->pos.max_iter)
				color = BLACK;
			pixel_put(&all->img, all->pos.x , all->pos.y, color);
		}
	}
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
}

int julia_keys(int keycode, t_all_in_one *all)
{
	if (keycode == XK_Up)
		all->pos.a += 0.001;
	else if (keycode == XK_Down)
		all->pos.a -= 0.001;
	else if (keycode == XK_Left)
		all->pos.b -= 0.001;
	else if (keycode == XK_Right)
		all->pos.b += 0.001;
	return (0);
}