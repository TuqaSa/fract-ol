/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:43:24 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/28 17:20:21 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	add_complex(t_complex comp1, t_complex comp2)
{
	t_complex	result;

	result.real = comp1.real + comp2.real;
	result.img = comp1.img + comp2.img;
	return (result);
}

t_complex	square_complex(t_complex comp)
{
	t_complex	result;

	result.real = (comp.real * comp.real) - (comp.img * comp.img);
	result.img = 2 * (comp.real * comp.img);
	return (result);
}
