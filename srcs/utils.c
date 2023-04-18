/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:22:27 by hakim             #+#    #+#             */
/*   Updated: 2023/04/18 19:20:04 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include <mlx.h>

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_color	interpolate(t_color c1, t_color c2, double t)
{
	t_color	res;

	res.r = c1.r + t * (c2.r - c1.r);
	res.g = c1.g + t * (c2.g - c1.g);
	res.b = c1.b + t * (c2.b - c1.b);
	return (res);
}

t_color	iter_to_rgb(int iter_count, int max_iter)
{
	double	t;
	t_color	c1;
	t_color	c2;
	t_color	res;

	t = ((double) iter_count / (double) max_iter) * 10000;
	// printf("flot %f\n", t);
	c1 = (t_color) {150, 0, 255};
	c2 = (t_color) {0, 0, 0};
	res = interpolate(c1, c2, t);
	return (res);
}

int rgb_to_trgb(t_color c)
{
	return (0 << 24 | c.r << 16 | c.g << 8 | c.b);
}

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
			iter_count = is_in_mandelbrot(pix, max_iter);
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

