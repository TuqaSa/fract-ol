/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractolutls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:31:38 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/29 17:15:59 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_real_cordants(t_data *data, t_point *real_pixel, int x, int y)
{
	real_pixel->x = x - WIDTH / 2;
	real_pixel->y = y - HEIGHT / 2;
	real_pixel->x /= data->zoom_factor;
	real_pixel->y /= data->zoom_factor;
	real_pixel->x += data->center_point.x;
	real_pixel->y += data->center_point.y;
}

int	coloring(int iterations, int max_iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iterations == max_iterations)
		return (0x000000);
	t = (double)iterations / max_iterations;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	iteration(t_data *data, t_point real_pixel)
{
	if (data->fractal_type == MANDELBROT)
		return (calc_mandelbrot(real_pixel, data));
	else if (data->fractal_type == JULIA)
		return (calc_julia(real_pixel, data->julia_constant, data));
	else if (data->fractal_type == BURNING_SHIP)
	{
		return (calc_burning_ship(real_pixel, data));
	}
	return (0);
}

void	cleanup_resources(t_data *data)
{
	if (data->img->image)
		mlx_destroy_image(data->mlx, data->img->image);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
