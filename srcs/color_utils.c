/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:37:46 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/20 01:45:56 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	t = ((double) iter_count / (double) max_iter );
	// printf("flot %f\n", t);
	c1 = (t_color) {50, 0, 60};
	c2 = (t_color) {0, 255, 255};
	res = interpolate(c1, c2, t);
	return (res);
}

int rgb_to_trgb(t_color c)
{
	return (0 << 24 | c.r << 16 | c.g << 8 | c.b);
}
