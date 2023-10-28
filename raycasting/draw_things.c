/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:12:18 by mboudrio          #+#    #+#             */
/*   Updated: 2023/10/28 11:08:01 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_rect(int i, int j, t_map_data *data, int color)
{
	int x;
	int y;

	y = 0;
	while (y < 30)
	{
		if (j + y >= 1080)
			break;
		x = 0;
		while (x < 30)
		{
			if (i + x >= 1920)
				break;
            if (x == 0 || y == 0)
			 	mlx_put_pixel(data->img, i + x, j + y, 0xF0fF0F);
			else
                mlx_put_pixel(data->img, i + x, j + y, color);
			x++;
		}
		y++;
	}
}

void draw_player(int i, int j, t_map_data *data, int color)
{
	int x;
	int y;

	y = 0;

	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			mlx_put_pixel(data->img, i + x, j + y, color);
			x++;
		}
		y++;
	}
}

void draw_player1(int i, int j, t_map_data *data, int color)
{
	int x;
	int y;

	y = 0;

	while (y < 1)
	{
		x = 0;
		while (x < 1)
		{
			mlx_put_pixel(data->img, i + x, j + y, color);
			x++;
		}
		y++;
	}
}

void drawHRotationLine(t_map_data *mape)
{
	DDA(mape, mape->p_y ,mape->p_x, mape->horzWallHitY, mape->horzWallHitX);
}
void drawVRotationLine(t_map_data *mape)
{
	DDA(mape, mape->p_y, mape->p_x, mape->vertWallHitY, mape->vertWallHitX);
}
