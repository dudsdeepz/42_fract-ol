/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:26:38 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/28 20:21:28 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	zoom_fractal(int button, int x, int y, t_all_in_one *all)
{
	if (button == 4)
	{
		all->pos.zoom /= 1.1;
		all->pos.xx *= 1.1;
		all->pos.yy *= 1.1;
		all->pos.xx += ((x - X / 2) * 0.1);
		all->pos.yy += ((y - Y / 2) * 0.1);
		all->pos.max_iter++;
	}
	else if (button == 5)
	{
		all->pos.zoom *= 1.1;
		all->pos.xx -= ((x - X / 2) * 0.1);
		all->pos.yy -= ((y - Y / 2) * 0.1);
	}
	else if (button == 1)
	{
			all->pos.xx += ((x - X / 2) * 0.1);
			all->pos.yy += ((y - Y / 2) * 0.1);
	}
	return (0);
}

int	change_color(int keycode, t_all_in_one *all)
{
	if (keycode == XK_1)
		all->pos.red += 1;
	else if (keycode == XK_4)
		all->pos.red -= 1;
	else if (keycode == XK_2)
		all->pos.green += 1;
	else if (keycode == XK_5)
		all->pos.green -= 1;
	else if (keycode == XK_3)
		all->pos.blue += 1;
	else if (keycode == XK_6)
		all->pos.blue -= 1;
	else
		arrow_move(keycode, all);
	return (0);
}

int	julia_keys(int keycode, t_all_in_one *all)
{
	if (keycode == XK_w)
		all->pos.a += 0.005;
	else if (keycode == XK_s)
		all->pos.a -= 0.005;
	else if (keycode == XK_a)
		all->pos.b -= 0.005;
	else if (keycode == XK_d)
		all->pos.b += 0.005;
	else
		change_iter(keycode, all);
	return (0);
}

int	change_iter(int keycode, t_all_in_one *all)
{
	if (keycode == XK_9)
		all->pos.max_iter += 1;
	else if (keycode == XK_8)
		all->pos.max_iter -= 1;
	else
		change_color(keycode, all);
	return (0);
}


int	arrow_move(int keyword, t_all_in_one *all)
{
	if (keyword == XK_Up)
		all->pos.yy -= ((all->pos.y - X / 2) * 0.1);
	else if (keyword == XK_Down)
		all->pos.yy += ((all->pos.y - X / 2) * 0.1);
	else if (keyword == XK_Left)
		all->pos.xx -= ((all->pos.y - X / 2) * 0.1);
	else if (keyword == XK_Right)
		all->pos.xx += ((all->pos.y - X / 2) * 0.1);
	return (0);
}
