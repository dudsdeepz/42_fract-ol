/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:18 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/26 17:12:52 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	int		max_iter;
	t_cords	pos;
	
	pos.max_iter = 25;
	if (ac < 2)
		exit(arguments());
	if (av[2])
		pos.max_iter = ft_atoi(av[2]);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (MLX_ERROR);
	set_choose(av[1], vars, img, pos);
	if (!vars.win)
	{
		free (vars.win);
		return (MLX_ERROR);
	}
}
