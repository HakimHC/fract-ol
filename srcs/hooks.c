/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:26:07 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/20 04:03:59 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <mlx.h>

#include "fractol.h"

void	go_home(t_fractol *data)
{
	(*data).zoom = 1;
	(*data).center = (t_complex) {0, 0};
}

int	change_max_iter(int keycode, t_fractol *data)
{
	if (keycode == 40)
		(*data).max_iter += 5;
	else if (keycode == 38 && (*data).max_iter > 5)
		(*data).max_iter -= 5;
	else if (keycode == 53)
		destroyer(data);
	else if (keycode == 15 && (*data).f == &is_in_julia)
		(*data).rotate *= -1;
	else if (keycode == 13)
		go_home(data);
	else if (keycode == 12)
		(*data).color = 1000;
	else
		return (1);
	mlx_clear_window((*data).mlx, (*data).win);
	print_fractal(*data);
	return (0);
}

int	zoom_hook(int button, int x, int y, t_fractol *data)
{
	if (button == 4)
	{
		(*data).zoom *= 1.5;
		(*data).center = pixel_to_complex(x, y, *data);
	}
	else if (button == 5 && (*data).zoom >= 0.5)
		(*data).zoom /= 1.5;
	else
		return (1);
	mlx_clear_window((*data).mlx, (*data).win);
	print_fractal(*data);
	return (0);
}

int	move_arrow(int keycode, t_fractol *data)
{
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
	mlx_clear_window((*data).mlx, (*data).win);
	print_fractal(*data);
	return (1);
}
