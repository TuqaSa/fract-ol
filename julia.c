/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:10:47 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/28 16:03:30 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_julia(t_point real_pixel, t_complex julia_constant, t_data *data)
{
	t_complex	z;
	int			i;

	z.real = real_pixel.x;
	z.img = real_pixel.y;
	i = 0;
	while (i < data->iterations)
	{
		z = add_complex(square_complex(z), julia_constant);
		i++;
		if ((z.img * z.img) + (z.real * z.real) >= 4)
			return (i);
	}
	return (0);
}
