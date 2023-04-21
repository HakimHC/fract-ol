/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:07:47 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/21 03:37:23 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_max_iter(int keycode, t_fractol *data)
{
	if (keycode == 40)
		(*data).max_iter += 5;
	else if (keycode == 38 && (*data).max_iter > 5)
		(*data).max_iter -= 5;
}

void	go_home(t_fractol *data)
{
	(*data).zoom = 1;
	(*data).center = (t_complex){0, 0};
}

void	change_color(t_fractol *data)
{
	data->color *= 1000;
	if (data->color >= 1000000000)
		data->color = 1;
}

void	change_multibrot(t_fractol *data)
{
	data->multibrot_pow++;
	if (data->multibrot_pow >= 7)
		data->multibrot_pow = 1;
}
