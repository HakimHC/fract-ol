/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:22:27 by hakim             #+#    #+#             */
/*   Updated: 2023/04/20 03:55:40 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include <mlx.h>

#include "fractol.h"

void	determine_color(t_fractol data, int i, int j)
{
	t_complex	pix;
	int	iter_count;

	pix = pixel_to_complex(i, j, data);
	iter_count = data.f(pix, data);
	if (data.max_iter == iter_count)
		my_mlx_pixel_put(&data.img, i, j, 0x00000000);
	else
	{
		int color = rgb_to_trgb(iter_to_rgb(iter_count, data));
		my_mlx_pixel_put(&data.img, i, j, color);
	}
}

void	print_fractal(t_fractol data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.width)
	{
		j = 0;
		while (j < data.height)
		{
			determine_color(data, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
}


