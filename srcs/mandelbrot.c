/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:58:05 by hakim             #+#    #+#             */
/*   Updated: 2023/04/20 22:19:05 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_in_mandelbrot(t_complex c, t_fractol data)
{
	t_complex	z;
	int			i;

	z = (t_complex){0, 0};
	i = 0;
	while (i < data.max_iter)
	{
		z = cpx_add(cpx_mul(z, z), c);
		if (cpx_mag(z) > 2)
			return (i);
		i++;
	}
	return (i);
}

int	is_in_julia(t_complex z, t_fractol data)
{
	int	i;

	i = 0;
	while (i < data.max_iter)
	{
		z = cpx_add(cpx_mul(z, z), data.julia_coor);
		if (cpx_mag(z) > 2)
			return (i);
		i++;
	}
	return (i);
}

t_complex	cpx_pow(t_complex z, double n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		z = cpx_mul(z, z);
		i++;
	}
	return (z);
}

int	multibrot(t_complex c, t_fractol data)
{
	t_complex	z;
	int			i;

	z = (t_complex){0, 0};
	i = 0;
	while (i < data.max_iter)
	{
		z = cpx_add(cpx_pow(z, data.multibrot_pow), c);
		if (cpx_mag(z) > 2)
			return (i);
		i++;
	}
	return (i);
}
