/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:57:40 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/28 18:04:29 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void set_choose(t_all_in_one *all, t_data img, t_cords pos, t_vars vars)
{
    int i;
    
    i = -1;
    all->img = img;
    all->pos = pos;
    all->vars = vars;
    all->vars.win = mlx_new_window(all->vars.mlx, X, Y, all->vars.set); 
    all->img.img = mlx_new_image(all->vars.mlx, X, Y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bites,
        &all->img.length, &all->img.end);
    default_values(all);
    while (all->vars.set[i++])
        all->vars.set[i++] = ft_tolower(all->vars.set[i++]);
    if (!ft_strcmp(all->vars.set, "mandelbrot"))
        mlx_loop_hook(all->vars.mlx, set_render, all);
    else if (!ft_strcmp(all->vars.set, "julia"));
        mlx_loop_hook(all->vars.mlx, set_render, all);
    mlx_hook(all->vars.win, 2, 1L << 0, julia_keys, all);
	mlx_mouse_hook(all->vars.win, &zoom_fractal, all);
    handle_close(all);
}

int set_render(t_all_in_one *all)
{
    int color;

    all->pos.x = -1;
    while (++all->pos.x < X)
        {
            all->pos.y = -1;
            while (++all->pos.y < Y)
            {
                all->pos.c = ft_map(all->pos.x + all->pos.xx, X - 1, -all->pos.zoom, all->pos.zoom);
                all->pos.d = ft_map(all->pos.y + all->pos.yy, Y - 1, -all->pos.zoom, all->pos.zoom);
                if (!ft_strcmp(all->vars.set, "mandelbrot"))
                    color = render_mandelbrot(all);
                else if (!ft_strcmp(all->vars.set, "julia"))
                    color = render_julia(all);
                pixel_put(&all->img, all->pos.x, all->pos.y, color);
            }
        }
    mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
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


void default_values(t_all_in_one *all)
{
    all->pos.zoom = 3.5;
    all->pos.red = 16;
    all->pos.green = 10;
    all->pos.blue = 5;
}

void init_fractal(char *set, t_data img, t_cords pos, t_vars vars)
{
    int i;
    t_all_in_one all;

    i = -1;
    vars.set = set;
    while (vars.set[++i])
        vars.set[i] = ft_tolower(vars.set[i]);
	if (!ft_strcmp(vars.set, "mandelbrot"))
		set_choose(&all, img, pos, vars);
    else if (!ft_strcmp(vars.set, "julia"))
		set_choose(&all, img, pos, vars);
	else
		exit(arguments());
}