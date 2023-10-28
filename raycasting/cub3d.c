/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:59:08 by mboudrio          #+#    #+#             */
/*   Updated: 2023/10/28 11:22:53 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int abs(int n) { return ((n > 0) ? n : (n * (-1))); }

// DDA Function for line generation


void DDA(t_map_data *map, int  X0, int Y0, int X1, int Y1)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;

    for (int i = 0; i <= steps; i++)
	{
		if (X >= WIDTH || Y >= HEIGHT)
			break;
		if (map->horDis > map->verDis){
			if (map->isRayFacingRight)
       			mlx_put_pixel(map->img, X, Y, ft_pixel(255, 0,0,255)); // put pixel at (X,Y)
			else
       			mlx_put_pixel(map->img, X, Y, ft_pixel(0, 255,0,255)); // put pixel at (X,Y)
		}
		else {
			if (map->isRayFacingUp)
       			mlx_put_pixel(map->img, X, Y, ft_pixel(0, 0,255,255)); // put pixel at (X,Y)
			else
       			mlx_put_pixel(map->img, X, Y, ft_pixel(0, 0,0,255)); // put pixel at (X,Y)
		}
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
                    // generation step by step
    }
}

double rad(float degree)
{
	return (degree * M_PI / 180);
}

void	get_map_data(t_map_data *mape, char *path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		// vree(mape);
	line = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		// tree(mape, line);
	mape->c_col_count = strlen_nn(line);
	mape->col_count = strlen_nn(line);
	mape->row_count = 0;
	while (line)
	{
		(mape->row_count)++;
		i = 0;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	vree(t_map_data *mape)
{
	printf("Error\nThere is a Problem in your file\n");
	free(mape);
	exit (1);
}

int	strlen_nn(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

void	loop(void *p)
{
	t_map_data *a = p;

	a->p_xtmp = a->p_x;
	a->p_ytmp = a->p_y;
	// for(int i = 0; i < HEIGHT; i++)
	// 	for(int j = 0; j < WIDTH; j++)
	// 		mlx_put_pixel(a->img, j, i, ft_pixel(0,0,0,255));
	if (mlx_is_key_down(a->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(a->mlx);
	else if (mlx_is_key_down(a->mlx, MLX_KEY_RIGHT))
	{
		rotate_player(a, 0.0274533);
		a->r_angle = normalize(a->r_angle);
	}
	else if (mlx_is_key_down(a->mlx, MLX_KEY_LEFT))
	{
		rotate_player(a, -0.0274533);
		a->r_angle = normalize(a->r_angle);
	}
	else if (mlx_is_key_down(a->mlx, MLX_KEY_W))
	{
		{
			a->p_ytmp += sin(a->r_angle) * PLAYER_SPEED;
			a->p_xtmp += cos(a->r_angle) * PLAYER_SPEED;
		}
	}
	else if (mlx_is_key_down(a->mlx, MLX_KEY_S))
	{
		{
			a->p_ytmp -= sin(a->r_angle) * PLAYER_SPEED;
			a->p_xtmp -= cos(a->r_angle) * PLAYER_SPEED;
		}
	}
	else if (mlx_is_key_down(a->mlx, MLX_KEY_D))
	{
		{
			a->p_xtmp += cos(a->r_angle + rad(90)) * PLAYER_SPEED;
			a->p_ytmp += sin(a->r_angle + rad(90)) * PLAYER_SPEED;
		}
	}
	else if (mlx_is_key_down(a->mlx, MLX_KEY_A))
	{
		{
			a->p_xtmp -= cos(a->r_angle + rad(90)) * PLAYER_SPEED;
			a->p_ytmp -= sin(a->r_angle + rad(90)) * PLAYER_SPEED;
		}
	}
	if ((a->map[((int)a->p_x) / SQ_][((int)a->p_ytmp) / SQ_ ] != '1'
        && a->map[((int)a->p_xtmp) / SQ_][((int)a->p_y) / SQ_] != '1'
         && a->map[((int)a->p_xtmp) / SQ_][((int)a->p_ytmp) / SQ_] != '1'))
		 {
			a->p_x = a->p_xtmp;
			a->p_y = a->p_ytmp;
			// fill_window(p);
			cast_all_rays(p);
		 }
}

void	render_map(t_map_data *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", 1);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	// fill_window(map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
	mlx_loop_hook(map->mlx, loop, map);
	mlx_loop(map->mlx);
}
void	copie_the_map(t_map_data *mape, char *path)
{
	int	fd;
	int	i;
	int	j;

	j = 0;
	i = 0;
	mape->map = malloc(mape->row_count * sizeof(char *));
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(mape->map);
		free(mape);
		exit(1);
	}
	while (i < mape->row_count)
	{
		mape->map[i] = get_next_line(fd);
		i++;
	}
}

void	fill_window(t_map_data *mape)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mape->col_count)
	{
		j = -1;
		while (++j < mape->row_count)
		{
			mape->cur_char = mape->map[j][i];
			// filling(mape, i * 30, j * 30);
		}
	}
	cast_all_rays(mape);
	// mape->ray_angle = 0;
}

void	filling(t_map_data *mape,int i, int j)
{
	if (mape->cur_char == '1')
		draw_rect(i, j, mape, 0xf0f0f0);
	if (mape->cur_char == '0' || mape->cur_char == 'P')
		draw_rect(i, j, mape, 0x0FFF0F);
	draw_player(mape->p_y, mape->p_x, mape, 0xFF000F);
}

int	exito(t_map_data *map)
{
	free(map);
	exit(0);
}

void	player_x_y(t_map_data *mape)
{
	int i;
	int j;

	i = -1;
	while(++i < mape->row_count)
	{
		j = -1;
		while(++j < mape->col_count)
		{
			if (mape->map[i][j] == 'N')
			{
				mape->p_x = i * SQ_;
				mape->p_y = j * SQ_;
			}
		}
	}
}

void	initialize_player_data(t_map_data *mape)
{
	mape->Pi = M_PI;
	mape->walk_direction = 0;
	mape->radius = 5;
	mape->r_angle = M_PI / 2;
	mape->FOV = (60 * (M_PI / 180));
	mape->move_speed = 2.0;
	// mape->rotation_speed = 2 * (mape->Pi / 180);
}

int ray_main(int argc, char **argv , char **map1, t_texteur *tex)
{
    t_map_data *map;

	if (argc == 2)
	{
    	map = malloc(sizeof(t_map_data));
		map->texteur = tex;
		map->map = map1;
		// initialize_map_data(map);
		initialize_player_data(map);
		get_map_data(map, argv[1]);
		copie_the_map(map, argv[1]);
		player_x_y(map);
		// load_txt(map);
    	render_map(map);
	}
	return (0);
}
