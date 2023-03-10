/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:54:42 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/10 11:20:57 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int escape_close(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	close_it(t_vars vars)
{
	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_hook(vars.win, 17, 1L<<2, close, &vars);
	mlx_key_hook(vars.win, &escape_close, &vars);
}

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
int arguments(void)
{
		ft_printf("=====\n");
		ft_printf("Julia set.\n");
		ft_printf("Mandelbrot set.\n");
		ft_printf("===================\n");
		return (0);
}
int set_choose(char *av)
{
	if (ft_strncmp(av[1], "Julia", 6) == 0)
		return (1);
	else if (ft_strncmp(av[1], "Mandelbrot", 10) == 0)
		return (2);
}
