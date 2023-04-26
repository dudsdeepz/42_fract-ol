/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:57:40 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/26 12:04:35 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void    set_choose(char *set, t_vars vars, t_data img, t_cords pos)
{
    int i;
    t_all_in_one all;

    all.img = img;
    all.pos = pos;
    all.vars = vars;
    all.pos.zoom = 3.5;
    i = -1;
    while (set[++i])
        set[i] = ft_tolower(set[i]);
    if (!ft_strcmp(set, "mandelbrot"))
        set_render(&all, set);
    else if (!ft_strcmp(set, "julia"))
        set_render(&all, set);
    else
        exit(arguments());
}

int get_color(int iter, t_cords pos)
{
    int red;
    int green;
    int blue;

    red = (iter * 255) / pos.max_iter;
    green = (255 - (iter * 255) / pos.max_iter);
    blue = (255 * iter * (pos.max_iter - iter)) 
        / (pos.max_iter * pos.max_iter);
    return ((red << 20) | (green << 6) | (blue << 5));
}

int zoom_fractal(int keycode, t_cords pos)
{
    if (keycode == XK_A)
		pos.zoom += 0.1;
    else if (keycode == XK_S)
        pos.zoom -= 0.1;
    return(pos.zoom);
}

void set_render(t_all_in_one *all, char *set)
{
    all->img.img = mlx_new_image(all->vars.mlx, X, Y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bites,
        &all->img.length, &all->img.end);
    all->vars.win = mlx_new_window(all->vars.mlx, X, Y, set);
    // if (!ft_strcmp(set, "mandelbrot"))
    // {
    //     all->vars.win = mlx_new_window(all->vars.mlx, X, Y, set);
    //     render_mandelbrot(vars, img, pos);
    // }
    if (!ft_strcmp(set, "julia"))
    {
        all->pos.a = 0.001;
	    all->pos.b = 0.001;
        mlx_hook(all->vars.win, 2, 1L << 0, julia_keys, all);
        mlx_loop_hook(all->vars.mlx, render_julia, all);
    }
    handle_close(all->vars);
}