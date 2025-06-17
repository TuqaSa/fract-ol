/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:54:39 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/30 15:20:11 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keysym, t_data *data)
{
	double	pan_amount;

	if (keysym == XK_Escape)
	{
		cleanup_resources(data);
		exit(0);
	}
	if (keysym == XK_m)
		data->fractal_type = MANDELBROT;
	else if (keysym == XK_j)
		data->fractal_type = JULIA;
	pan_amount = 150 / data->zoom_factor;
	if (keysym == XK_Left)
		data->center_point.x -= pan_amount;
	else if (keysym == XK_Right)
		data->center_point.x += pan_amount;
	else if (keysym == XK_Up)
		data->center_point.y -= pan_amount;
	else if (keysym == XK_Down)
		data->center_point.y += pan_amount;
	mlx_clear_window(data->mlx, data->window);
	paint_fractal(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img->image, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	t_point	real_pos_bre;
	t_point	real_pos_aft;

	calc_real_cordants(data, &real_pos_bre, x, y);
	if (button == 3 && data->fractal_type == JULIA)
	{
		data->julia_constant.real = real_pos_bre.x;
		data->julia_constant.img = real_pos_bre.y;
	}
	else if (button == 4)
		data->zoom_factor *= 1.1;
	else if (button == 5)
		data->zoom_factor *= 0.9;
	calc_real_cordants(data, &real_pos_aft, x, y);
	data->center_point.x += real_pos_bre.x - real_pos_aft.x;
	data->center_point.y += real_pos_bre.y - real_pos_aft.y;
	mlx_clear_window(data->mlx, data->window);
	paint_fractal(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img->image, 0, 0);
	return (0);
}

int	exit_x(t_data *data)
{
	cleanup_resources(data);
	exit(0);
	return (0);
}
