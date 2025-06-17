/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:07:44 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/28 16:02:11 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_mandelbrot(t_point real_pixel, t_data *data)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z.real = 0.0;
	z.img = 0.0;
	c.real = real_pixel.x;
	c.img = real_pixel.y;
	i = 0;
	while (i < data->iterations)
	{
		z = add_complex(square_complex(z), c);
		i++;
		if ((z.img * z.img) + (z.real * z.real) >= 4)
		{
			return (i);
		}
	}
	return (0);
}
