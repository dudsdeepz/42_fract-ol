/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:21:22 by eduarodr          #+#    #+#             */
/*   Updated: 2023/04/21 17:48:58 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define X 1920
# define Y 1080
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
int		mandelbrot(t_cords pos);
void	julia(t_vars vars, t_data img);
double	ft_map(double start, double end, double r1, double r2);
void	pixel_put(t_data *data, int x, int y, int color);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_tolower(int c);
void 	render_mandelbrot(t_vars vars, t_data img);
void 	render_julia(t_vars vars, t_data img);
void    set_choose(char *set, t_vars vars, t_data img);
int 	get_color(int max_iterations);

#endif
