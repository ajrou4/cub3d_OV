/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:21:21 by majrou            #+#    #+#             */
/*   Updated: 2023/10/20 20:45:46 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_duplcit(char **map)
{
	int	i;
	int	j;
	int	k;

	i = check_elements(map);
	j = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
				k++;
			j++;
		}
		i++;
	}
	if (k != 1)
	{
		printf("Error\n\tMultiple or no player position\n");
		free_map(map);
		exit(0);
	}
}

void	parse_floor_line(t_rgb *color, char *line)
{
	char	**str;
	int		k;

	str = ft_split(line + 2, ',');
	if (!str)
	{
		free(color);
		return ;
	}
	k = 0;
	while (str[k])
	{
		if(ft_atoi(str[k]) > 255)
		{
			printf("Error : Color value must be between 0 and 255\n");
			free_map(str);
			free(color);
			exit(0);
		}
		else if (ft_atoi(str[k]) <= 255)
			color->floor[k] = ft_atoi(str[k]);
		k++;
	}
	free_map(str);
}

void	parse_ceiling_line(t_rgb *color, char *line)
{
	char	**str;
	int		k;

	str = ft_split(line + 2, ',');
	if (!str)
	{
		free(color);
		return ;
	}
	k = 0;
	while (str[k])
	{
		if(ft_atoi(str[k]) > 255)
		{
			printf("Error : Color value must be between 0 and 255\n");
			free_map(str);
			free(color);
			exit(0);
		}
		else if (ft_atoi(str[k]) <= 255)
			color->sky[k] = ft_atoi(str[k]);
		k++;
	}
	free_map(str);
}

void	get_color(char **map)
{
	t_rgb	*color;
	int		i;

	color = malloc(sizeof(t_rgb));
	if (!color)
		return ;
	i = 0;
	while (map[i])
	{
		if (ft_strnstr(map[i], "F ", 2))
			parse_floor_line(color, map[i]);
		if (ft_strnstr(map[i], "C ", 2))
			parse_ceiling_line(color, map[i]);
		i++;
	}
	free(color);
}
