/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texteur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:14:25 by majrou            #+#    #+#             */
/*   Updated: 2023/10/27 19:12:31 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_texteur	*load_txt(t_tex *tex)
{
	t_texteur *texteur;

	texteur = malloc(sizeof(t_texteur));
	texteur->no = mlx_load_png(tex->no);
	if (!texteur->no)
		printf("Error: Can't load texture\n");
	texteur->ea = mlx_load_png(tex->ea);
	if(!texteur->ea)
		printf("Error: Can't load texture\n");
	texteur->we = mlx_load_png(tex->we);
	if (!texteur->we)
		printf("Error: Can't load texture\n");
	texteur->so = mlx_load_png(tex->so);
	if (!texteur->so)
		printf("Error: Can't load texture\n");
	return (texteur);
}


int	get_offsetx(t_map_data *data, mlx_texture_t *img)
{
	(void)img;
	if(data->foundVertWallHit == 1)
		data->x_text = fmod(data->horzWallHitX, SQ_) /** (img->width / SQ_)*/;
	else if(data->foundHorzWallHit == 1)
		data->x_text = fmod(data->horzWallHitX, SQ_) /** (img->width / SQ_)*/;
	return (data->x_text);
}
// int	get_offsety(t_map_data *data, mlx_texture_t *img)
// {
// 	if(data->wallTopPixel > 0 && wallBottomPixel < HEIGHT)
// 		data->y_text = (1-(data->wallBottomPixel - data->wallTopPixel) / data->wallStripHeight) * img->height;
// 	return data->y_text;
// }

int	get_color_from_textur(mlx_texture_t *texteur, int x, int y)
{
	int index;
	int max;

	max = texteur->width * texteur->height * texteur->bytes_per_pixel;
	index = (x * 4) + (y * 4 * texteur->width);
	if (index >= max)
		return (0);
	return (ft_pixel(texteur->pixels[index], texteur->pixels[index + 1], texteur->pixels[index + 2], texteur->pixels[index + 3]));
}
