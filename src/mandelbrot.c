/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:36:55 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/14 10:36:58 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	mandelbrot(t_vars vars)
{
	mlx_pixel_put(vars.mlx, vars.win, WIDTH / 2, HEIGHT / 2, RED);
	mlx_pixel_put(vars.mlx, vars.win, WIDTH / 4, HEIGHT / 4, GREEN);
	mlx_pixel_put(vars.mlx, vars.win, WIDTH / 3, HEIGHT / 3, YELLOW);
}
