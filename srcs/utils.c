/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:22:27 by hakim             #+#    #+#             */
/*   Updated: 2023/04/20 01:41:42 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include <mlx.h>

#include "fractol.h"

void	print_mandelbrot(t_fractol data, int max_iter)
{
	int	i;
	int	j;
	t_complex	pix;
	int	iter_count;

	i = 0;
	while (i < data.width)
	{
		j = 0;
		while (j < data.height)
		{
			pix = pixel_to_complex(i, j, data);
			// iter_count = is_in_mandelbrot(pix, max_iter);
			iter_count = is_in_julia(pix, data.julia_coor, max_iter);
			if (max_iter == iter_count)
				my_mlx_pixel_put(&data.img, i, j, 0x00000000);
			else
			{
				int color = rgb_to_trgb(iter_to_rgb(iter_count, max_iter));
				// print_colors(color);
				my_mlx_pixel_put(&data.img, i, j, color);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
}


