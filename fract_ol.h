/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:21:22 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/16 10:42:36 by eduarodr         ###   ########.fr       */
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
# include <X11/X.h>

# define RED 0xFF0000
# define GREEN 0xFF00
# define YELLOW 0xFFFF00
# define BLUE 0x0000FF

typedef struct s_vars {
	int	*mlx;
	int	*win;
}			t_vars;

typedef struct s_cords{
	int		y;
	int		x;
	int		a;
	int		n;
	int		b;
}	t_cords;

int 	handle_no_event(void *data);
void	close_it(t_vars vars);
int 	escape_close(int keycode, t_vars *vars);
int 	close(int keycode, t_vars *vars);
int		arguments(void);
int		ft_atoi(const char *nptr);
void 	set_choose(char *av, t_vars vars);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	mandelbrot(t_vars vars);

#endif
