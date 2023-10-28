/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:09:05 by majrou            #+#    #+#             */
/*   Updated: 2023/10/25 00:36:21 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	return (count);
}

char	**read_map(char *file)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (count_lines(fd) + 1));
	if (!map)
		return (NULL);
	close(fd);
	fd = open(file, O_RDONLY);
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	close(fd);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_elements(char **map)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (map && map[i])
	{
		str = ft_strtrim(map[i], " ");
		if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
			|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3)
			|| !ft_strncmp(str, "C ", 2) || !ft_strncmp(str, "F ", 2))
			j++;
		if (!ft_strncmp(str, "1", 1))
			break ;
		free(str);
		i++;
	}
	if (j != 6)
	{
		printf("Error : extension for map  is not '.cub' \n");
		free_map(map);
		exit(0);
	}
	return (i);
}

void	check_map(char **map, int i)
{
	int	j;
	char *str;

	j = 0;
	while (map[i])
	{
		j = 0;
		str = ft_strtrim(map[i], " \t");
		if (ft_strlen(str) == 0)
		{
			error_map(map);
		}
		while (str[j])
		{
			if (ft_strchr("10 NSWE\n", str[j]) == NULL)
			{
				error_cheack_map(map, i);
			}
			j++;
		}
		free(str);
		i++;
	}
}


