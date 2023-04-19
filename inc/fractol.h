/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:29:10 by hakim             #+#    #+#             */
/*   Updated: 2023/04/20 01:41:59 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"

typedef struct	s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

typedef struct	s_fractol
{
	void	*mlx;
	void	*win;
	int	height;
	int	width;
	t_data	img;
	int	max_iter;
	t_complex	center;
	double	zoom;
	char	**available_fractals;
	t_complex	julia_coor;
}	t_fractol;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

/***************** COMPLEX NUMBERS ********************/

t_complex	cpx_add(t_complex num1, t_complex num2);
t_complex	cpx_mul(t_complex num1, t_complex num2);
double	cpx_mag(t_complex num);
void	print_complex(t_complex num, int nl);
t_complex	pixel_to_complex(int x, int y, t_fractol data);

/***************** MANDELBROT STUFF *******************/

int	is_in_mandelbrot(t_complex c, int max_iter);
void	print_mandelbrot(t_fractol data, int max_iter);

/***************** COLORS AND STUFF *******************/

int	create_trgb(int t, int r, int g, int b);
int	get_t(int color);
int	get_r(int color);
int	get_g(int color);
int	get_b(int color);
void	print_colors(int color);

int	cfg_parser(t_fractol *data);

int	is_in_julia(t_complex z, t_complex c, int max_iter);

int	move_arrow(int keycode, t_fractol *data);
int	zoom_hook(int button, int x, int y, t_fractol *data);
int	change_max_iter(int keycode, t_fractol *data);

t_fractol	init(void);
void	destroyer(t_fractol *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_color	iter_to_rgb(int iter_count, int max_iter);
int rgb_to_trgb(t_color c);

double	ft_abs(double t);
double	ft_atof(char *str);

#endif
