/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowsettings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:28:53 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/28 17:29:23 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	default_settings(t_data *data)
{
	data->zoom_factor = 200;
	data->iterations = 250;
	data->center_point.x = 0;
	data->center_point.y = 0;
	data->fractal_type = MANDELBROT;
	data->julia_constant.real = -0.7;
	data->julia_constant.img = 0.27015;
}

void	window_title(t_data *data)
{
	if (data->fractal_type == MANDELBROT)
		ft_strlcpy(data->window_title, "Mandelbrot Set", 50);
	else if (data->fractal_type == JULIA)
		ft_strlcpy(data->window_title, "Julia Set", 50);
	else if (data->fractal_type == BURNING_SHIP)
		ft_strlcpy(data->window_title, "Burning Ship", 50);
}
