/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:31:52 by aybiouss          #+#    #+#             */
/*   Updated: 2023/05/24 15:11:21 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h> 
# include "Libft/libft.h"
# include <math.h>

# define ROTATION_SPEED 5
# define MOUSE_SPEED 0.5
# define EACH 64
# define VER 1
# define HOR 2
# define MOVE_UP 1
# define MOVE_DOWN -1
# define MOVE_RIGHT 2
# define MOVE_LEFT -2
# define ROTATE_RIGHT 1
# define ROTATE_LEFT -1
# define SLOWING_DOWN 12
# define MINI_WIDTH 240
# define MINI_HIGHT 180
# define WINDOW_HIGHT 720
# define WINDOW_WIDTH 1200
# define WALL_HIGHT 0.75
# define TEXTURE_HIGHT 64
# define TEXTURE_WIDTH 64
# define MINI 20
# define IS_BACK_GROUND 0
# define IS_WALL 1
# define IS_DOOR 2
# define IS_SPACE 3

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_coor
{
	double	h_hit_x;
	double	h_hit_y;
	double	v_hit_x;
	double	v_hit_y;
}				t_coor;

typedef struct s_plyr
{
	double	x;
	double	y;
	double	move_speed;
	int		p_angle;
	char	pos;
}				t_plyr;

typedef struct s_map
{
	char		**map;
	int			y;
	int			x;
	int			floor_colour;
	int			ceil_clr;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	t_plyr		plyr;
}				t_map;

typedef struct s_ray
{
	double	length;
	double	angle;
	int		type;
	int		is_wall;
	int		hit_x;
	int		hit_y;
}				t_ray;

typedef struct s_doors
{
	int		x;
	int		y;
	int		is_closed;
}				t_doors;

typedef struct s_prog
{
	int			loop_var;
	int			p_x;
	int			p_y;
	int			cursor_x;
	int			cursor_y;
	int			start;
	int			is_mouse_works;
	int			move_to;
	int			rotate_to;
	void		*mlx;
	void		*win;
	void		*img_wall;
	int			nbr_doors;
	t_doors		*doors;
	t_ray		*rays;
	t_map		map;
	t_data		data;
	t_data		no_txtr;
	t_data		so_txtr;
	t_data		we_txtr;
	t_data		ea_txtr;
	t_data		door_txtr;
	t_data		data_3d;
	t_data		fire_txtr;
	t_data		fire_1;
	t_data		fire_2;
	t_data		fire_3;
	t_data		fire_4;
	t_data		fire_5;
	t_data		fire_6;
	t_data		fire_7;
}	t_prog;

//Utils
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
size_t	ft_strlene(char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoine(char *s1, char *s2);
char	*ft_strdupp(char *str);
int		rgbtoint(int red, int green, int blue);

//Errors
void	ft_perror(char *msg, char *utils);
void	error_image(t_prog *game);
void	error_file(void);
void	error_name(void);
void	error_map(void);
void	put_error(char *msg);
void	error_mapfree(char *line);
void	error_infos(void);

//Parsing
int		check_inner_wall(t_prog *game);
int		checking_outer_walls(t_prog *game);
void	check_colours(char *line, t_prog *game);
int		checking_cub(char *av);
void	check_map(char *av, t_prog *game);
void	insert_data(char *av, t_prog **game);
t_prog	*init_game(void);
void	check_door(int up, int down, int left, int right);
void	position_door(t_prog *game);
void	check_vertical_space(char c, char character);
void	check_verticaly(t_prog *game);
void	check_horizontaly(t_prog *game);
void	check_horizontal_space(char c, char character);
int		check_plyr_coords(t_prog *game);
void	check_colours(char *line, t_prog *game);
int		rgbToInt(int red, int green, int blue);
void	*ft_realloc(void *line, size_t size, int len);
void	rectangular_map(t_prog *game, int length);
void	check_characters(t_prog *game);
void	checkparam(char *line, t_prog *game);
void	checker(t_prog *game);
int		check_longest_line(char *line, int fd, t_prog *game);
int		cub_map(char *line, int fd, t_prog *game);
void	rectangular_map(t_prog *game, int length);
int		check_last_line(t_prog *game);
int		check_first_line(t_prog *game);
int		check_walls(t_prog *game);
int		ft_strlen_n(char *s);
char	*line_protection(int fd);
int		ft_strchr(char const *s, int c);
int		ft_strnstr_int(const char *haystack, const char *needle, size_t len);
char	**freeing(char **s);
int		cub_map(char *line, int fd, t_prog *game);
int		check_line_chars(char *line);

//////////// Execution /////////////

/*  get_started */
int		open_win(t_prog *game);
char	*which_texture(t_prog *game, int x);
void	set_first_direction(t_prog *game);

/*  handle_doors */
void	open_close_door(t_prog *game);
int		count_doors(t_prog *game);
void	handle_doors(t_prog *game);
int		ft_abs(int d);
int		found_door(t_prog *game, int y, int x);

/*  control_keys */
int		keys_func(t_prog *game);
int		unset_keys(int key, t_prog *game);
int		set_keys(int key, t_prog *game);
void	rotate_left(t_prog *game);
void	rotate_right(t_prog *game);

/*  control_moves */
void	move_to_(t_prog *game, int angle, int _cos, int _sin);
int		between_walls(t_prog *game, double l_dx, double l_dy);
int		is_next_step_dangerous(t_prog *game, double l_dx, double l_dy);

/*  render_mini_map.c */
void	render_mini_map(t_prog *game);
void	for_each_coloum(t_prog *game, int j, int m);
void	mini_mini_map(t_prog *game);
void	put_pixels(t_prog *game, int x, int y, int _which_);

/*  init_images */
void	init_img(t_prog *game);
void	get_addr(t_prog *game);
void	get_addr_animation(t_prog *game);

/*  control_hooks */
void	control_hooks(t_prog *game);
int		looping_function(t_prog *game);
int		put_fire(t_prog *game);
int		control_mouse(int x, int y, t_prog *game);
int		ft_close(t_prog *game);

/*  draw_walls */
void	drawing_walls(t_prog *game);
double	get_projcted_hight(t_prog *game, int x);
void	draw_wall_and_door(t_prog *game, int x, int y, double wallstrp_hiht);
int		get_offset_x(t_prog *game, int x);
int		get_offset_y(int y, double wallstrp_hight);

/*  render_all */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	identify_player(t_prog *game, int x, int y);
void	render_all(t_prog *game);

/*  ray_casting */
void	rays_casting(t_prog *game);
void	set_rays_angle(t_prog *game);

/*  0__to__90  */
void	from_0_90(t_prog *game, double angle, t_ray *ray);
double	from_0_90_hor(t_prog *game, double angle, t_coor *coor);
double	from_0_90_ver(t_prog *game, double angle, t_coor *coor);

/*  90__to__180  */
void	from_90__180(t_prog *game, double angle, t_ray *ray);
double	from_90__180_hor(t_prog *game, double angle, t_coor *coor);
double	from_90__180_ver(t_prog *game, double angle, t_coor *coor);
double	get_ver_len(t_prog *gm, t_coor *coor, double v_ht_x, double v_ht_y);
double	get_hor_len(t_prog *gm, t_coor *coor, double h_ht_x, double h_ht_y);

/*  180__to__270  */
void	from_180__270(t_prog *game, double angle, t_ray *ray);
double	from_180__270_hor(t_prog *game, double angle, t_coor *coor);
double	from_180__270_ver(t_prog *game, double angle, t_coor *coor);
double	get_hor_ln(t_prog *game, t_coor *coor, double _x, double _y);
double	get_ver_ln(t_prog *game, t_coor *coor, double _x, double _y);

/*  270__to__360  */
void	from_270__360(t_prog *game, double angle, t_ray *ray);
double	from_270__360_hor(t_prog *game, double angle, t_coor *coor);
double	from_270__360_ver(t_prog *game, double angle, t_coor *coor);

#endif