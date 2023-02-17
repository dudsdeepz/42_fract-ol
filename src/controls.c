/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:26:38 by eduarodr          #+#    #+#             */
/*   Updated: 2023/02/10 16:48:15 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

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


