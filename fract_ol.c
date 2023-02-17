/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:18 by eduarodr          #+#    #+#             */
/*   Updated: 2023/02/10 16:48:23 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int escape_close(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int handle_no_event(void *data)
{
	return (0);
}

int	main(void)
{
	t_vars	vars;
	//int		i;

	//i = 0;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fract-ol");
	if (!vars.win)
	{
		free (vars.win);
		return (MLX_ERROR);
	}
	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_key_hook(vars.win, &escape_close, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}
