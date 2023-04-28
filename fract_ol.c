/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:18 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/28 20:00:03 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_cords	pos;
	int	i;

	i = 0;
	pos.max_iter = 25;
	if (ac < 2)
		exit(arguments());
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (MLX_ERROR);
	if (av[2])
		if (ft_isdigit(*av[2]))
			pos.max_iter = ft_atoi(av[2]);
	else
		exit(arguments());
	vars.set = av[1];
	init_fractal(vars.set, img, pos, vars);
	if (!vars.win)
	{
		free (vars.win);
		return (MLX_ERROR);
	}
}
