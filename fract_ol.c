/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:18 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/13 15:04:17 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;

	if (ac != 2)
		arguments();
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (MLX_ERROR);
	set_choose(av[1], vars, img);
	if (!vars.win)
	{
		free (vars.win);
		return (MLX_ERROR);
	}
}
