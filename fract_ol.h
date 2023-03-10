/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:21:22 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/10 11:21:24 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define WIDTH 800
# define HEIGHT 600
# define MLX_ERROR 1
# include <stdlib.h>
# include <X11/keysym.h>
# include <math.h>

typedef struct s_vars {
	int	*mlx;
	int	*win;
}			t_vars;

int 	handle_no_event(void *data);
void	close_it(t_vars vars);
int 	escape_close(int keycode, t_vars *vars);
int 	close(int keycode, t_vars *vars);
int		arguments(void);
int		ft_atoi(const char *nptr);
int 	set_choose(char *av);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
