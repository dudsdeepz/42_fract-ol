/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:18 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/27 17:31:46 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_cords	pos;
	
	pos.max_iter = 25;
	if (ac < 2)
		exit(arguments());
	if (av[2])
		pos.max_iter = ft_atoi(av[2]);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (MLX_ERROR);
	vars.set = av[1];	
	init_fractal(vars.set, img, pos, vars);
	if (!vars.win)
	{
		free (vars.win);
		return (MLX_ERROR);
	}
}