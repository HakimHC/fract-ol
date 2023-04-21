/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:26:07 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/21 03:55:02 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <mlx.h>

#include "fractol.h"

void	move_pos(int keycode, t_fractol *data)
{
	double	move_amount_x;
	double	move_amount_y;

	move_amount_x = ((double)data->width / 2)
		/ (data->zoom * data->width);
	move_amount_y = ((double) data->height / 2)
		/ (data->zoom * data->height * (double)data->width
			/ (double)data->height);
	if (keycode == 123)
		data->center.real -= move_amount_x;
	else if (keycode == 124)
		data->center.real += move_amount_x;
	else if (keycode == 125)
		data->center.imag += move_amount_y;
	else if (keycode == 126)
		data->center.imag -= move_amount_y;
}

void	zoom_space(t_fractol *data)
{
	data->zoom *= 1.5;
}

int	key_hook(int keycode, t_fractol *data)
{
	printf("%d\n", keycode);
	if (keycode == 40 || keycode == 38)
		change_max_iter(keycode, data);
	else if (keycode == 53)
		destroyer(data);
	else if (keycode == 15 && (*data).f == &is_in_julia)
		(*data).rotate *= -1;
	else if (keycode == 13)
		go_home(data);
	else if (keycode == 12)
		change_color(data);
	else if (keycode >= 123 && keycode <= 126)
		move_pos(keycode, data);
	else if (keycode == 48)
		change_multibrot(data);
	else if (keycode == 49)
		zoom_space(data);
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
