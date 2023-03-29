/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:21:22 by eduarodr          #+#    #+#             */
/*   Updated: 2023/03/29 16:04:11 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define X 800
# define Y 600
# define MLX_ERROR 1
# include <stdlib.h>
# include <X11/keysym.h>
# include <math.h>
# include <X11/X.h>
# include "./mlx/mlx.h"
# include "./printf/ft_printf.h"

# define RED 0xFF0000
# define GREEN 0xFF0000
# define YELLOW 0xFFFF00
# define BLUE 0x0000FF

typedef struct s_vars {
	int	*mlx;
	int	*win;
}			t_vars;

typedef struct s_cords{
	int			y;
	int			x;
	double		a;
	int			n;
	double		b;
	double		c;
	int			d;
}	t_cords;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bites;
	int		length;
	int		end;
}	t_data;

int		handle_no_event(void *data);
void	close_it(t_vars vars);
int		escape_close(int keycode, t_vars *vars);
int		ft_close(t_vars *vars);
int		arguments(void);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	mandelbrot(t_vars vars, t_data img);
double	ft_map(double start, double end, double r1, double r2);
void	pixel_put(t_data *data, int x, int y, int color);

#endif
