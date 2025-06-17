/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:24:21 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/29 18:16:47 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	sign_set(char *str, int *sign)
{
	*sign = 1;
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
}

double	parse_float(const char *str)
{
	int		sign;
	double	result;
	double	decimal_place;

	sign = 1;
	result = 0;
	decimal_place = 0.1;
	sign_set((char *)str, &sign);
	while (ft_isdigit(*str))
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			result += (*str - '0') * decimal_place;
			decimal_place *= 0.1;
			str++;
		}
	}
	return (result * sign);
}

void	parse_input(t_data *data, int ac, char **av)
{
	if (data->fractal_type == JULIA)
	{
		if (ac != 4)
		{
			ft_putendl_fd("Usage: ./fractol julia [real] [imaginary]", 2);
			exit(1);
		}
		if (!parse_float(av[2]) || !parse_float(av[3]))
		{
			ft_putendl_fd("Usage: ./fractol julia [real] [imaginary]", 2);
			exit(1);
		}
		data->julia_constant.real = parse_float(av[2]);
		data->julia_constant.img = parse_float(av[3]);
	}
	else if ((data->fractal_type == MANDELBROT
			|| data->fractal_type == BURNING_SHIP) && ac != 2)
	{
		ft_putendl_fd("Usage: ./fractol [mandelbrot/julia/burning_ship]", 2);
		exit(1);
	}
}
