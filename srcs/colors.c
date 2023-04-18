/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:37:54 by hakim             #+#    #+#             */
/*   Updated: 2023/04/18 12:14:54 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int color)
{
	return (color >> 24 & 0xFF);
}

int	get_r(int color)
{
	return (color >> 16 & 0xFF);
}

int	get_g(int color)
{
	return (color >> 8 & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}

void	print_colors(int color)
{
	printf("T - %d\n", get_t(color));
	printf("R - %d\n", get_r(color));
	printf("G - %d\n", get_g(color));
	printf("B - %d\n", get_b(color));
}
