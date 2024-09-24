
#ifndef CUB3D_H
# define CUB3D_H

/*---------------*/
/*  Text colors  */
/*---------------*/
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[24m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[97m"
# define RESET "\x1b[0m"

/*----------------------*/
/*  Included libraries  */
/*----------------------*/
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

/*-------------------*/
/*  Constant values  */
/*-------------------*/
# define WIDTH 1920
# define HEIGHT 1080
# define VIEW 60
# define GRID 64
# define MOVE 0.02
# define ROTATE 0.02

/*-------------*/
/*  Side enum  */
/*-------------*/
typedef enum s_side
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	VERTICAL,
	HORIZONTAL,
}	t_side;

/*----------------*/
/*  Table struct  */
/*----------------*/
typedef struct s_table
{
	int	row;
	int	column;
}	t_table;

/*----------------------*/
/*  Point struct (int)  */
/*----------------------*/
typedef struct s_point_int
{
	int	x;
	int	y;
}	t_point_int;

/*-------------------------*/
/*  Point struct (double)  */
/*-------------------------*/
typedef struct s_point_double
{
	double	x;
	double	y;
}	t_point_double;

/*--------------*/
/*  Map struct  */
/*--------------*/
typedef struct s_map
{
	char		**map2d;
	char		player_direction;
	t_point_int	player_position;
	int			color_floor;
	int			color_ceiling;
	char		*path_texture_north;
	char		*path_texture_south;
	char		*path_texture_east;
	char		*path_texture_west;
}	t_map;

/*-----------------*/
/*  Player struct  */
/*-----------------*/
typedef struct s_player
{
	double			angle;
	double			fov;
	t_side			pov;
	t_point_double	pos;
}	t_player;

/*--------------*/
/*  Ray struct  */
/*--------------*/
typedef struct s_ray
{
	double			angle;
	t_point_double	direction;
	t_table			map;
	t_point_double	delta_dist;
	t_point_int		step;
	t_point_double	side_dist;
	t_side			side;
	t_side			wall;
	double			plane_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
}	t_ray;

/*------------------*/
/*  Texture struct  */
/*------------------*/
typedef struct s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	int				ceiling;
	int				floor;
}	t_texture;

/*---------------*/
/*  Data struct  */
/*---------------*/
typedef struct s_data
{
	int			width;
	int			height;
	t_map		map;
	t_player	player;
	t_texture	texture;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*buf;
}	t_data;

/*-------------*/
/*  Functions  */
/*-------------*/
void	init_data(t_data *data);
void	init_map(t_data *data);
void	init_player(t_data *data);
void	invert_view(t_player *player);
void	simulation(void *param);
double	radian(int degree);
void	action_handling(t_data *data);
void	move_player(t_data *data, double move_column, double move_row);
void	ray_casting(t_data *data);
void	define_ray_values(t_data *data, t_ray *ray, int x);
void	define_step_direction(t_ray *ray, t_player *player);
void	define_wall_collision(t_data *data, t_ray *ray);
void	define_plane_distance(t_ray *ray, t_player *player);
void	rendering(t_data *data, t_ray *ray, int x);
void	set_ceiling_floor_colors(t_data *data, t_ray *ray, int x);
void	set_wall_textures(t_data *data, t_ray *ray, int x);
void	free_array(char **array);
void	free_exit(t_data *data, int exit_status);
void	ft_perror(char *error_msg);
void	error_free_exit(t_data *data, char *error_msg);

#endif
