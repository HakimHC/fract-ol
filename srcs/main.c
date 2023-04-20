/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:20:21 by hakim             #+#    #+#             */
/*   Updated: 2023/04/20 04:18:33 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <mlx.h>

#include "fractol.h"
#include "libft.h"


void	leaks(void)
{
	system("leaks -q fractol");
}

int	move_julia(int x, int y, t_fractol *data)
{
	if ((*data).rotate == 1)
	{
		(*data).julia_coor = pixel_to_complex(x, y, *data);
		print_fractal(*data);
	}
	return (1);
}

void fractal_selector(char **argv, t_fractol *data)
{
	if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")))
		(*data).f = &is_in_mandelbrot;
	else if (!ft_strncmp(argv[1], "Multibrot", ft_strlen("Multibrot")))
		(*data).f = &multibrot;
	else if (!ft_strncmp(argv[1], "Julia", ft_strlen("Julia")))
	{
		(*data).f = &is_in_julia;
		(*data).rotate *= -1;
		if (argv[2])
		{
			(*data).julia_coor.real = ft_atof(argv[2]);
			(*data).rotate *= -1;
		}
		if (argv[2] && argv[3])
			(*data).julia_coor.imag = ft_atof(argv[3]);
	}
	else 
	{
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": Invalid fractal!\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	atexit(leaks);
	t_fractol data;

	data = init();
	if (argc >= 2)
	{
		fractal_selector(argv, &data);
		print_fractal(data);
		// mlx_key_hook(data.win, move_arrow, &data);
		mlx_hook(data.win, 4, 1L<<2, zoom_hook, &data);
		mlx_hook(data.win, 6, 1L<<6, move_julia, &data);
		mlx_hook(data.win, 2, 1L<<0, change_max_iter, &data);
		mlx_loop(data.mlx);
	}
	else 
	{
		ft_printf("Available fractals:\n%a\n", data.available_fractals);
		destroyer(&data);
	}
	return (0);
}
