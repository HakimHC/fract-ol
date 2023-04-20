/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:30:04 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/20 03:54:56 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <mlx.h>

#include "fractol.h"

t_fractol	init(void)
{
	t_fractol	res;

	res.width = 600;
	res.height = 600;
	res.mlx = mlx_init();
	res.win = mlx_new_window(res.mlx, res.width, res.height, "tremendo");
	res.img.img = mlx_new_image(res.mlx, res.width, res.height);
	res.img.addr = mlx_get_data_addr(res.img.img, &res.img.bits_per_pixel,
			&res.img.line_length,
			&res.img.endian);
	res.max_iter = 100;
	res.center = (t_complex) {0, 0};
	res.zoom = 1;
	res.rotate = -1;
	res.color = 1;
	res.available_fractals = ft_split("Mandelbrot Julia Newton", 32);
	return (res);
}

t_fractol	init_cfg(void)
{
	t_fractol	res;

	res.mlx = mlx_init();
	res.win = mlx_new_window(res.mlx, res.width, res.height, "tremendo");
	res.img.img = mlx_new_image(res.mlx, res.width, res.height);
	res.img.addr = mlx_get_data_addr(res.img.img, &res.img.bits_per_pixel,
			&res.img.line_length,
			&res.img.endian);
	res.center = (t_complex) {0, 0};
	res.zoom = 1;
	res.available_fractals = ft_split("Mandelbrot Julia Newton", 32);
	return (res);
}

void	destroyer(t_fractol *data)
{
	mlx_destroy_image((*data).mlx, (*data).img.img);
	mlx_destroy_window((*data).mlx, (*data).win);
	ft_free_strarr((*data).available_fractals);
	exit(0);
}
