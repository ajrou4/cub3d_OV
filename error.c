/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:58:38 by majrou            #+#    #+#             */
/*   Updated: 2023/10/21 17:00:42 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_cheack_map(char **map , int i)
{
	printf("maps invalid! \n");
	printf("\t%s\n", map[i]);
	free_map(map);
	exit(0);
}
void	error_map(char **map)
{
	printf("Error in maps1 \n");
	free_map(map);
	exit(0);
}
