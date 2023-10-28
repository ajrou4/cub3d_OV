/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:55:02 by majrou            #+#    #+#             */
/*   Updated: 2023/10/27 11:17:54 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf ("%s", map[i]);
		i++;
	}
}
// void loadtxt(t_texteur tex, char **map)
// {
// 	tex = get_tex(map);
// 	tex.north = mlx_load_png("textures/path1.png");
// 	if (!tex.north)
// 		printf("Error: Can't load texture\n");
// 	tex.east = mlx_load_png("textures/path2.png");
// 	if(!tex.east)
// 		printf("Error: Can't load texture\n");
// 	tex.weast = mlx_load_png("textures/path3.png");
// 	if (!tex.weast)
// 		printf("Error: Can't load texture\n");
// 	tex.south = mlx_load_png("textures/path4.png");
// 	if (!tex.south)
// 		printf("Error: Can't load texture\n");
// }



int	main(int ac, char **av)
{
	char	**map;
	t_texteur *tex;

	if (ac == 2)
	{
			map = read_map(av[1]);
			remove_newlines(map);
			check_map(map, check_elements(map));
			check_duplcit(map);
			get_color(map);
			tex = get_tex(map);
			check_duplcit(map);
			ray_main(ac, av ,map, tex);
	}
	else
	{
		printf("Error: Where is map\n");
		exit(0);
	}
	return (0);

}
