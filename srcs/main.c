/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:20:21 by hakim             #+#    #+#             */
/*   Updated: 2023/04/18 21:04:21 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <mlx.h>

#include "fractol.h"
#include "libft.h"

t_fractol	init(void)
{
	t_fractol	res;

	res.width = 300;
	res.height = 300;
	res.mlx = mlx_init();
	res.win = mlx_new_window(res.mlx, res.width, res.height, "tremendo");
	res.img.img = mlx_new_image(res.mlx, res.width, res.height);
	res.img.addr = mlx_get_data_addr(res.img.img, &res.img.bits_per_pixel,
			&res.img.line_length,
			&res.img.endian);
	res.max_iter = 25;
	res.center = (t_complex) {0, 0};
	res.zoom = 1;
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

int	change_max_iter(int keycode, t_fractol *data)
{
	// printf("%d\n", keycode);
	// printf("%d\n", (*data).max_iter);
	if (keycode == 107)
		(*data).max_iter += 5;
	else if (keycode == 106 && (*data).max_iter > 5)
		(*data).max_iter -= 5;
	else if (keycode == 65307)
	{
		mlx_destroy_image((*data).mlx, (*data).img.img);
		mlx_destroy_window((*data).mlx, (*data).win);
		ft_free_strarr((*data).available_fractals);
		exit(0);
	}
	else
		return (1);
	mlx_clear_window((*data).mlx, (*data).win);
	print_mandelbrot((*data), (*data).max_iter);
	return (0);
}

int	zoom_hook(int button, int x, int y, t_fractol *data)
{
	// printf("button - %d\n", button);
	if (button == 4)
	{
		(*data).zoom *= 1.5;
		(*data).center = pixel_to_complex(x, y, *data);
	}
	else if (button == 5 && (*data).zoom >= 0.5)
	{
		// (*data).center = pixel_to_complex(x, y, *data);
		(*data).zoom /= 1.5;
	}
	else
		return (1);
	mlx_clear_window((*data).mlx, (*data).win);
	print_mandelbrot((*data), (*data).max_iter);
	return (0);
}

int	move_arrow(int keycode, t_fractol *data)
{
	if (keycode == 97)
		(*data).center.real /= 1.2;
	else if (keycode == 98)
		(*data).center.imag /= 1.2;
	else if (keycode == 99)
		(*data).center.real *= 1.2;
	// else if (keycode == 98)
	// 	(*data).center.imag *= 1.2;
	else
		return (1);
	printf("ENTRE");
	mlx_clear_window((*data).mlx, (*data).win);
	print_mandelbrot((*data), (*data).max_iter);
	return (1);
}

int	main(int argc, char **argv)
{
	// t_fractol data = init(argv[1]);
	t_fractol data;
	(void) argv;

	// if (!(cfg_parser(&data)))
	// {
	// 	data = init();
	// 	printf("FAILED\n");
	// }
	// data = init_cfg();
	data = init();
	// cfg_parser(&data);
	if (argc >= 2)
	{
		printf("maxiter - %d\n", data.max_iter);
		print_mandelbrot(data, data.max_iter);
		// mlx_key_hook(data.win, move_arrow, &data);
		mlx_hook(data.win, 4, 1L<<2, zoom_hook, &data);
		mlx_hook(data.win, 2, 1L<<0, change_max_iter, &data);
		mlx_loop(data.mlx);
	}
	else 
	{
		ft_printf("Available fractals:\n%a\n", data.available_fractals);
		ft_free_strarr(data.available_fractals);
	}
	return (0);
}
