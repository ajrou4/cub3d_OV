/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texteur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:32:43 by majrou            #+#    #+#             */
/*   Updated: 2023/10/26 05:45:51 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texteur    *get_tex(char **map)
{
    t_tex *tex = malloc(sizeof(t_tex));
    if (!tex)
        return (NULL);
    int i = 0;
    // mlx_texture_t *texture;
	t_texteur *texteur;

	texteur = malloc(sizeof(t_texteur));
    while (map[i])
    {
        if (ft_strnstr(map[i], "NO ", 3))
        {
            texteur->no = mlx_load_png(map[i] + 3);
            if (texteur->no == NULL)
            {
                printf("Error\n");
                exit(0);
            }
        }
            if (ft_strnstr(map[i], "SO ", 3))
            {
                texteur->so = mlx_load_png(map[i] + 3);
                if (texteur->so == NULL)
                {
                    printf("Error\n");
                    exit(0);
                }
            }
            if (ft_strnstr(map[i], "WE ", 3))
            {
                texteur->we = mlx_load_png(map[i] + 3);
                if (texteur->we == NULL)
                {
                    printf("Error\n");
                    exit(0);
                }
            }
            if (ft_strnstr(map[i], "EA ", 3))
            {
                texteur->ea = mlx_load_png(map[i] + 3);
                if (texteur->ea == NULL)
                {
                    printf("Error\n");
                    exit(0);
                }
            }
            i++;
    }
    free(tex);
	return (texteur);
}

void	remove_newlines(char **map)
{
	int i = 0;

	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
	}
}
