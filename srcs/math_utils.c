/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:36:47 by hakahmed          #+#    #+#             */
/*   Updated: 2023/04/19 21:38:23 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_abs(double t)
{
	if (t < 0)
		return (-t);
	return (t);
}

double	ft_atof(char *str)
{
	double	digits;
	double	decimal_i;
	long	i;
	double	sign;

	sign = 1;
	digits = ft_atoi(str);
	if (digits < 0)
		sign = -sign;
	decimal_i = 10;
	i = str - ft_strchr(str, '.');
	if (!(str - i))
		return (0);
	i = ft_abs(i) + 1;
	while (str[i] && ft_isdigit(str[i]))
	{
		digits += ((double)(str[i] - 48) / decimal_i) * sign;
		decimal_i *= 10;
		i++;
	}
	if (digits >= 0 && digits < 1)
		digits = -digits;
	return (digits);
}
