/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:50:07 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/29 18:16:05 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	inti(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->window_title);
	data->img->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->mlx || !data->window || !data->img->image)
	{
		ft_putendl_fd("Error: failed to initialize mlx", 2);
		cleanup_resources(data);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_img	img;

	data.img = &img;
	default_settings(&data);
	if (!init_fractol(&data, argc, argv))
	{
		ft_putendl_fd("Usage: ./fractol [mandelbrot/julia/burning_ship]", 2);
		return (1);
	}
	parse_input(&data, argc, argv);
	window_title(&data);
	inti(&data);
	paint_fractal(&data);
	mlx_put_image_to_window(data.mlx, data.window, data.img->image, 0, 0);
	mlx_mouse_hook(data.window, mouse_hook, &data);
	mlx_key_hook(data.window, key_hook, &data);
	mlx_hook(data.window, 17, 0, exit_x, &data);
	mlx_loop(data.mlx);
	return (0);
}
