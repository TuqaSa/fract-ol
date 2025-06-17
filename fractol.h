/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:44:05 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/30 15:23:49 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 700
# define HEIGHT 700
# define MANDELBROT 1
# define JULIA 2
# define NEWTON 3
# define BURNING_SHIP 4

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_img
{
	void		*image;
	char		*image_pixels_ptr;
	int			bits_per_pixel;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_complex
{
	long double	real;
	long double	img;
}				t_complex;
typedef struct s_point
{
	long double	x;
	long double	y;
}				t_point;

typedef struct s_rpoint
{
	int			x;
	int			y;
}				t_rpoint;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_img		*img;
	char		window_title[50];
	int			iterations;
	double		zoom_factor;
	t_point		center_point;
	int			fractal_type;
	t_complex	julia_constant;
}				t_data;

t_complex		square_complex(t_complex comp);
t_complex		add_complex(t_complex comp1, t_complex comp2);
void			calc_real_cordants(t_data *data, t_point *real_pixel, int x,
					int y);

int				calc_julia(t_point real_pixel, t_complex julia_constant,
					t_data *data);

double			parse_float(const char *str);
int				calc_mandelbrot(t_point real_pixel, t_data *data);
void			paint_fractal(t_data *data);
int				key_hook(int keysym, t_data *data);
int				mouse_hook(int button, int x, int y, t_data *data);
int				calc_burning_ship(t_point real_pixel, t_data *data);
void			cleanup_resources(t_data *data);
void			sign_set(char *str, int *sign);
double			parse_float(const char *str);
void			parse_input(t_data *data, int ac, char **av);
int				exit_x(t_data *data);
void			default_settings(t_data *data);
void			window_title(t_data *data);
int				init_fractol(t_data *data, int ac, char **av);
int				iteration(t_data *data, t_point real_pixel);
int				coloring(int iterations, int max_iterations);
void			calc_real_cordants(t_data *data, t_point *real_pixel, int x,
					int y);
void			paint_fractal(t_data *data);
int				key_hook(int keysym, t_data *data);
int				mouse_hook(int button, int x, int y, t_data *data);

#endif
