/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:24:47 by majrou            #+#    #+#             */
/*   Updated: 2023/10/27 14:45:24 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/MLX42.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

// # define TILE_SIZE 32
// # define MAP_NUM_ROWS 11
// # define MAP_NUM_COLS 15
// # define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
// # define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
#define SQ_ 30
#define PLAYER_SPEED 1
#define WIDTH 1200
#define HEIGHT 1200
#define false 0
#define true 1

typedef struct s_data
{
	mlx_t *mlx;
	mlx_image_t *mlx_img;
} t_data;

typedef struct s_tex
{
	char *so;
	char *no;
	char *we;
	char *ea;
} t_tex;

typedef struct s_rgb
{
	int	sky[3];
	int	floor[3];
} t_rgb;

typedef struct s_map
{
	int	width;
	int	height;
	char	**map;
} t_map;

typedef struct s_texteur
{
	mlx_texture_t *no;
	mlx_texture_t *ea;
	mlx_texture_t *we;
	mlx_texture_t *so;
} t_texteur;

typedef struct s_map_data
{
	t_texteur	*texteur;
	t_rgb	rgb;
	t_tex	tex;
	int* dummy_texture;
	void	*img;
	int		line_length;
    void	*mlx;
	void	*win;
    int		row_count;
	int		col_count;
	int		c_col_count;
	char	cur_char;
	char	**map;
	float		p_x;
	float		p_y;
	float		p_xtmp;
	float		p_ytmp;
	float		new_x;
	float		new_y;
	float 		radius;
	double		r_angle;
	double		ray_angle;
	float		move_speed;
	float		rotation_speed;
	int			walk_direction;
	double		Pi;
	int			r_right;
	int			r_left;
	int			m_up;
	int			m_down;
	int			m_right;
	int 		m_left;
	double		FOV;
	int			ray_Id;
	int	isRayFacingDown;
	int	isRayFacingUp;
	int	isRayFacingRight;
	int	isRayFacingLeft;
	// float			horzW_x;
	// float			horzW_y;
	// float			VertW_x;
	// float			VertW_y ;
	// float			x_hstep;
	// float			y_hstep;
	// float			x_vstep;
	// float			y_vstep;
	float nextVertTouchX;
	float nextHorzTouchX;
	float nextVertTouchY;
	float nextHorzTouchY;
	float horzWallHitX;
	float vertWallHitX;
	float horzWallHitY;
	float vertWallHitY;
	int	foundVertWallHit;
	int foundHorzWallHit;
	float	horDis;
	float	verDis;
	int wallTopPixel;
	int wallBottomPixel;
	int	x_text;
	int	y_text;
	int	wallStripHeight;

}			t_map_data;

char			**read_map(char *file);
void			get_color(char	**map);
t_texteur		*get_tex(char **map);
int				count_lines(int fd);
int				check_elements(char **map);
void			check_map(char **map, int i);
void			check_duplcit(char **map);
void			free_map(char **map);
void			parse_ceiling_line(t_rgb *color, char *line);
void			parse_floor_line(t_rgb *color, char *line);
void			remove_newlines(char **map);
int				load_texture(char *path);
void			error_map(char **map);
void			error_cheack_map(char **map , int i);
// ------------------------------------------------------------------------------------------------------------------------
int ray_main(int argc, char **argv, char **map, t_texteur *tex); // main function in raycasting
// ------------------------------------------------------------------------------------------------------------------------
void	DDA(t_map_data *map, int  X0, int Y0, int X1, int Y1) ;
//-----------------------------------------------------------------------*
int	get_offsetx(t_map_data *data, mlx_texture_t *img);
int	get_offsety(t_map_data *data, mlx_texture_t *img);
int	get_color_from_textur(mlx_texture_t *texteur, int x, int y);
//-----------------------------------------------------------------------*
int		release(int key);
void	move(t_map_data *mape);
int		mouvements(int keycode,t_map_data *map);
void	initialize_player_data(t_map_data *mape);
void	copie_the_map(t_map_data *mape, char *path);
void	render_map(t_map_data *map);
int     mouvements_p(int keycode, t_map_data *map);
int	    exito(t_map_data *map);
void	vree(t_map_data *mape);
void	player_x_y(t_map_data *mape);
void	tree(t_map_data *mape, char *line);
int     strlen_nn(char *s);
void	get_map_data(t_map_data *mape, char *path);
void	fill_window(t_map_data *mape );
void	filling(t_map_data *mape, int i,  int j);
void	my_mlx_pixel_put(t_map_data *data, int x, int y, int color);
int		press(int key,t_map_data *mape );
void	draw_h_grid(t_map_data *mape);
void	draw_v_grid(t_map_data *mape);
void	draw_rect(int i, int j, t_map_data *data, int color);
void	draw_player(int i, int j, t_map_data *data, int color);
void	rotate_player(t_map_data *mape, double angle);
void	drawRotationLine(t_map_data *mape);
double normalize(double angle);
void	cast_all_rays(t_map_data *mape );
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
float	ray_distance(float x1, float y1, float x2, float y2);
void			distances(t_map_data *mape);
void			cast_vertical_Ray(t_map_data *mape);
bool			mapHasWallAt(t_map_data *mape, float x, float y);
void			cast_horizontal_Ray(t_map_data *mape);
void			drawHRotationLine(t_map_data *mape);
void			drawVRotationLine(t_map_data *mape);
void			castRay(t_map_data *cb, int __unused  r);
double			rad(float degree);
void			generate3DProjection(t_map_data *mape, int i);
float			short_distance(t_map_data *mape);
void			loding_png(t_map_data *data);
t_texteur		*load_txt(t_tex *tex);
int* 	convert_to_bitmap(mlx_texture_t* data);
void	mlx_textur_to_image(mlx_image_t* image, mlx_texture_t* texture, int x_tex, int y_tex, int x_img, int y_img);

#endif
