/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:21:22 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/26 12:05:05 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define X 800
# define Y 800
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
# define BLACK 0x000000
typedef struct s_vars {
	int	*mlx;
	int	*win;
}			t_vars;


typedef struct s_cords{
	double			y;
	double			x;
	double			a;
	double			b;
	double			c;
	double			d;
	double			zoom;
	double			max_iter;
}	t_cords;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bites;
	int		length;
	int		end;
}	t_data;

typedef struct s_all_in_one{
	t_data img;
	t_cords pos;
	t_vars vars;
}	t_all_in_one;

int		handle_no_event(void *data);
void	close_it(t_vars vars);
int		escape_close(int keycode, t_vars *vars);
int		ft_close(t_vars *vars);
int		arguments(void);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		mandelbrot(t_cords pos);
int		julia(t_cords pos);
double	ft_map(double start, double end, double r1, double r2);
void	pixel_put(t_data *data, int x, int y, int color);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_tolower(int c);
void 	render_mandelbrot(t_vars vars, t_data img, t_cords pos);
int 	render_julia(t_all_in_one *all);
void    set_choose(char *set, t_vars vars, t_data img, t_cords pos);
int 	get_color(int iter, t_cords pos);
int 	zoom_fractal(int keycode, t_cords pos);
void 	set_render(t_all_in_one *all, char *set);
void 	handle_close(t_vars vars);
int 	julia_keys(int keysym, t_all_in_one *all);

#endif
