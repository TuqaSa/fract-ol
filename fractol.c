/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:31:45 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/29 17:16:18 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	paint_fractal(t_data *data)
{
	t_point		real_pixel;
	int			color;
	int			pixel_index;
	t_rpoint	rp;

	rp.y = 0;
	data->img->image_pixels_ptr = mlx_get_data_addr(data->img->image,
			&data->img->bits_per_pixel, &data->img->line_len,
			&data->img->endian);
	while (rp.y < HEIGHT)
	{
		rp.x = 0;
		while (rp.x < WIDTH)
		{
			calc_real_cordants(data, &real_pixel, rp.x, rp.y);
			color = coloring(iteration(data, real_pixel), data->iterations);
			pixel_index = (rp.y * data->img->line_len) + (rp.x
					* (data->img->bits_per_pixel / 8));
			*((unsigned int *)(data->img->image_pixels_ptr
						+ pixel_index)) = color;
			rp.x++;
		}
		rp.y++;
	}
}

int	init_fractol(t_data *data, int ac, char **av)
{
	if (ac < 2 || ac > 4)
	{
		return (0);
	}
	if (ft_strncmp(av[1], "julia", 6) == 0)
		data->fractal_type = JULIA;
	else if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		data->fractal_type = MANDELBROT;
	else if (ft_strncmp(av[1], "burningship", 12) == 0)
		data->fractal_type = BURNING_SHIP;
	else
	{
		ft_putendl_fd(av[1], 2);
		return (0);
	}
	return (1);
}
