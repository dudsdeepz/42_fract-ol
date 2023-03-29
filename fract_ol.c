/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:18 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/29 13:59:53 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;

	if (ac > 1)
	{
		vars.mlx = mlx_init();
		if (!vars.mlx)
			return (MLX_ERROR);
		vars.win = mlx_new_window(vars.mlx, X, Y, av[1]);
		if (!vars.win)
		{
			free (vars.win);
			return (MLX_ERROR);
		}
		img.img = mlx_new_image(vars.mlx, X, Y);
		img.addr = mlx_get_data_addr(img.img, &img.bites,
				&img.length, &img.end);
		mandelbrot(vars, img);
		close_it(vars);
	}
	else
		arguments();
}
