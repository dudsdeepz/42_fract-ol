/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardo <eduardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:57:40 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/27 01:08:08 by eduardo          ###   ########.fr       */
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

int get_color(int iter, t_all_in_one *all)
{
    int red;
    int green;
    int blue;

    red = (iter * 255) / all->pos.max_iter;
    green = (255 - (iter * 255) / all->pos.max_iter);
    blue = (255 * iter * (all->pos.max_iter - iter)) 
        / (all->pos.max_iter * all->pos.max_iter);
    return ((red << all->pos.red) | (green << all->pos.green) | (blue << all->pos.blue));
}

void set_render(t_all_in_one *all, char *set)
{
    all->img.img = mlx_new_image(all->vars.mlx, X, Y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bites,
        &all->img.length, &all->img.end);
    all->vars.win = mlx_new_window(all->vars.mlx, X, Y, set);
    all->pos.zoom = 4.0;
    all->pos.red = 16;
    all->pos.green = 10;
    all->pos.blue = 5;
    if (!ft_strcmp(set, "mandelbrot"))
        mlx_loop_hook(all->vars.mlx, render_mandelbrot, all);
    else if (!ft_strcmp(set, "julia"))
    {
        all->pos.a = 0.001;
	    all->pos.b = 0.001;
        mlx_loop_hook(all->vars.mlx, render_julia, all);
    }
	mlx_mouse_hook(all->vars.win, &zoom_fractal, all);
    mlx_hook(all->vars.win, 2, 1L << 0, julia_keys, all);
    handle_close(all->vars);
}