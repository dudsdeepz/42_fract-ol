/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:57:40 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/13 15:04:24 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void    set_choose(char *set, t_vars vars, t_data img)
{
    int i;
    
    i = -1;
    while (set[++i])
        set[i] = ft_tolower(set[i]);
    img.img = mlx_new_image(vars.mlx, X, Y);
	img.addr = mlx_get_data_addr(img.img, &img.bites,
	    &img.length, &img.end);
    if (!ft_strcmp(set, "mandelbrot"))
    {
        vars.win = mlx_new_window(vars.mlx, X, Y, set);
        render_mandelbrot(vars, img);
    }
    else if (!ft_strcmp(set, "julia"))
    {
        vars.win = mlx_new_window(vars.mlx, X, Y, set);
        render_julia(vars, img);
    }
    else
        arguments();
    mlx_hook(vars.win, 17, 1L << 2, ft_close, &vars);
	mlx_key_hook(vars.win, &escape_close, &vars);
	mlx_loop(vars.mlx);
}