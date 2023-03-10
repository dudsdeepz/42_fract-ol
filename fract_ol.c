/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:18 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/10 11:19:21 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac >= 2)
	{
		vars.mlx = mlx_init();
		if (!vars.mlx)
			return (MLX_ERROR);
		vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, av[1]);
		if (!vars.win)
		{
			free (vars.win);
			return (MLX_ERROR);
		}
		if (set_choose(av[1]) == 1)
			printf("Julia\n");
		else if (set_choose(av[1] == 2))
			printf("Mandelbrot\n");
		close_it(vars);
		mlx_loop(vars.mlx);
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
	}
	arguments();
}
