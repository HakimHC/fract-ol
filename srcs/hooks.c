/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:26:07 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/19 22:35:56 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <mlx.h>

#include "fractol.h"

int	change_max_iter(int keycode, t_fractol *data)
{
	printf("%d\n", keycode);
	printf("%d\n", (*data).max_iter);
	if (keycode == 38)
		(*data).max_iter += 5;
	else if (keycode == 40 && (*data).max_iter > 5)
		(*data).max_iter -= 5;
	else if (keycode == 53)
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
	printf("keycode - %d\n", keycode);
	if (keycode == 123)
		(*data).center.real = ((*data).center.real - (*data).zoom) / 1.2;
	else if (keycode == 98)
		(*data).center.imag /= 1.2;
	else if (keycode == 124)
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
