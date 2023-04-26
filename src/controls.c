/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:26:38 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/26 18:19:23 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"


int zoom_fractal(int button, int x, int y, t_all_in_one *all)
{
    if (button == 4)
		all->pos.zoom += 0.1;
    else if (button == 5)
        all->pos.zoom -= 0.1;
	pos.c = ft_map()
	pos.d = ft_map()
	return (0);
}

int change_color(int keycode, t_all_in_one *all)
{
    if(keycode == XK_1)
        all->pos.red += 1;
    else if(keycode == XK_4)
        all->pos.red -= 1;
    else if(keycode == XK_2)
        all->pos.green += 1;
    else if(keycode == XK_5)
        all->pos.green -= 1;
    else if(keycode == XK_3)
        all->pos.blue += 1;
    else if(keycode == XK_6)
        all->pos.blue -= 1;
    return (0);
}

int julia_keys(int keycode, t_all_in_one *all)
{
	if (keycode == XK_Up)
		all->pos.a += 0.005;
	else if (keycode == XK_Down)
		all->pos.a -= 0.005;
	else if (keycode == XK_Left)
		all->pos.b -= 0.005;
	else if (keycode == XK_Right)
		all->pos.b += 0.005;
	else
		change_iter(keycode, all);
	return (0);
}

int change_iter(int keycode, t_all_in_one *all)
{
	if (keycode == XK_9)
		all->pos.max_iter += 1;
	else if (keycode == XK_8)
		all->pos.max_iter -= 1;
	else
		change_color(keycode, all);
	return (0);
}

int controls_gui(int keyword, t_all_in_one *all)
{
	if (keyword == XK_Shift_R)
		{
			mlx_string_put(all->vars.mlx, all->vars.win, 20, 20, 0, "cona");
		}
	// ft_printf("===================================\n");
	// ft_printf("Number 1: add red to the fractal\n");
	// ft_printf("Number 2: add green to the fractal\n");
	// ft_printf("NUmber 3: add blue to the fractal\n");
	// ft_printf("Number 4: remove red to the fractal\n");
	// ft_printf("Number 5: remove green to the fractal\n");
	// ft_printf("Nmber 6: remove blue to the fractal\n");
	// ft_printf("Number 8: decrease number of max iterations\n");
	// ft_printf("Number 9: increase number of max iterations\n");
	// ft_printf("{Julia Set}Left arrou: decrease value b\n");
	// ft_printf("{Julia Set}Right arrou: increase value b\n");
	// ft_printf("{Julia Set}Up arrou: decrease value b\n");
	// ft_printf("{Julia Set}Down arrou: increasevalue b\n");
	// ft_printf("===================================\n");
	return (0);
}