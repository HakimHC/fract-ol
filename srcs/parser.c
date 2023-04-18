/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim </var/spool/mail/hakim>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:33:31 by hakim             #+#    #+#             */
/*   Updated: 2023/04/18 20:25:02 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "fractol.h"
#include "libft.h"

int	strarr_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	valid_atrribute(char *str)
{
	char **attrs = ft_split("height width maxiter", 32);
	if (!attrs)
		return (0);
	int i = 0;
	while (attrs[i])
	{
		if (!ft_strncmp(str, attrs[i], ft_strlen(str)))
			return (ft_free_strarr(attrs), 1);
		i++;
	}
	printf("fractolrc: ERROR: No attribute named '%s'\n", str);
	ft_free_strarr(attrs);
	free(str);
	exit(1);
}

int	populator(char **tokens, t_fractol *data)
{
	if (!ft_strncmp(tokens[1], "height", ft_strlen(tokens[1])))
		(*data).height = ft_atoi(tokens[3]);
	if (!ft_strncmp(tokens[1], "width", ft_strlen(tokens[1])))
		(*data).width = ft_atoi(tokens[3]);
	if (!ft_strncmp(tokens[1], "maxiter", ft_strlen(tokens[1])))
		(*data).max_iter = ft_atoi(tokens[3]);
	return (1);
}

int	is_valid(char **tokens, t_fractol *data)
{
	if (!tokens)
		return (0);
	if (strarr_len(tokens) != 4)
		return (0);
	if (ft_strncmp(tokens[0], "let", 3))
		return (0);
	if (!valid_atrribute(tokens[1]))
		return (0);
	if (tokens[2][0] != '=')
		return (0);
	if (!ft_atoi(tokens[3]) && ft_strncmp(tokens[3], "0", 1))
		return (0);
	return (populator(tokens, data));
}

int	cfg_parser(t_fractol *data)
{
	int	fd;
	char	*line;
	char **tokens;

	fd = open(".fractolrc", O_RDONLY);
	if (fd < 0)
	{
		printf("fractolrc: ERROR: Unable to open config.");
		return (0);
	}
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		tokens = ft_split(line, 32);
		ft_printf("%A", tokens);
		if (!is_valid(tokens, data))
			return (ft_free_strarr(tokens), free(line), 0);
		free(line);
		line = get_next_line(fd);
		ft_free_strarr(tokens);
		printf("LINE - %s\n", line);
	}
	free(line);
	return (1);
}
