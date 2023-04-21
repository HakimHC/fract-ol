/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:31:36 by hakim             #+#    #+#             */
/*   Updated: 2023/04/20 22:14:30 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "fractol.h"

t_complex	cpx_add(t_complex num1, t_complex num2)
{
	num1.real += num2.real;
	num1.imag += num2.imag;
	return (num1);
}

t_complex	cpx_mul(t_complex num1, t_complex num2)
{
	t_complex	res;

	res.real = (num1.real * num2.real) - (num1.imag * num2.imag);
	res.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
	return (res);
}

double	cpx_mag(t_complex num)
{
	return (pow(pow(num.real, 2) + pow(num.imag, 2), 0.5));
}

t_complex	pixel_to_complex(int x, int y, t_fractol data)
{
	double		ratio;
	t_complex	res;

	ratio = (double) data.width / (double) data.height;
	res.real = (x - (double)data.width / 2)
		* (4 / data.zoom) / (double)data.width;
	res.imag = (y - (double)data.height / 2)
		* (4 / (data.zoom * ratio)) / (double) data.height;
	res.real += data.center.real;
	res.imag += data.center.imag;
	return (res);
}
