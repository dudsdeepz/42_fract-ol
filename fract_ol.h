/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:21:22 by eduarodr          #+#    #+#             */
/*   Updated: 2023/02/15 17:59:17 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1
# include <stdlib.h>
# include <X11/keysym.h>

typedef struct s_vars {
	int	*mlx;
	int	*win;
}			t_vars;

int 	handle_no_event(void *data);
int 	escape_close(int keycode, t_vars *vars);

#endif
