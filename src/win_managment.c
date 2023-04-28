/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:54:42 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/28 19:59:56 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	escape_close(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		ft_close(vars);
	return (0);
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	arguments(void)
{
	ft_printf("=====\n");
	ft_printf("./fract_ol <set> <max_iterations>\n");
	ft_printf("=====\n");
	ft_printf("Julia set.\n");
	ft_printf("Mandelbrot set.\n");
	ft_printf("===================\n");
	return (0);
}

void	handle_close(t_all_in_one *all)
{
	mlx_hook(all->vars.win, 17, 1L << 2, ft_close, &all->vars);
	mlx_key_hook(all->vars.win, &escape_close, &all->vars);
	mlx_loop(all->vars.mlx);
}
