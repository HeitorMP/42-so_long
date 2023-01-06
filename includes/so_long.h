/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:24:37 by hmaciel-          #+#    #+#             */
/*   Updated: 2022/12/22 00:24:40 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include <errno.h>
# include <stdlib.h>

/* KEY MACROS */
# define ESC 65307
# define RIGHT 100
# define LEFT 97
# define UP 119
# define DOWN 115
# define NONE 0

/* SIZE MACROS */

# define BITS 32
# define MONSTERS 2;

typedef struct s_sprite {
	char	control;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	size_t	x;
	size_t	y;
	int		direction;
	int		quant;
	char	*path;
}				t_sprite;

typedef	struct s_quant
{
	int	quant_collect;
	int	quant_patrol;
}				t_quant;


typedef struct s_playfield {
	char	**playfield;
	char	**playfield_mask;
	size_t	col;
	size_t	lin;
}				t_playfield;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_map_file {
	int		fd;
	char	*path;
}				t_map_file;

typedef struct s_flags
{
	int	has_init_error;
	int	has_ingame_error;
	int	is_player_present;
	int	is_not_square;
	int	is_not_way_out;
	int	is_exit_present;
	int	is_collect_present;
	int	is_files_not_present;
	int	is_not_border;
	int	is_invalid_element;
	int	is_door_open;
	int	is_all_collect;
	int	is_game_over;
	int	is_game_over_fail;
	int	is_not_ber;
}				t_flags;

typedef struct s_path
{
	char	*hero_right;
	char	*hero_left;
	char	*hero_up;
	char	*hero_down;
	char	**walls;
	char	*border_wall_hu;
	char	*border_wall_hb;
	char	*border_wall_vr;
	char	*border_wall_vl;
	char	*border_wall_ul;
	char	*border_wall_ur;
	char	*border_wall_bl;
	char	*border_wall_br;
	char	*inner_wall;
	char	**collect;
	char	*closed_door;
	char	*opened_door;
	char	*patrol1;
	char	*patrol2;
	char	*patrol3;
	char	*floor;
	char	*tile;
}				t_path;

typedef struct s_counter
{
	int	count_collect;
	int	count_move;
	int	count_wall_animation;
	int	count_collect_animation;
	int	count_patrol_animation;
	int	count_patrol;
}				t_counter;

typedef struct root {
	t_mlx		mlx;
	t_playfield	playfield;
	t_map_file	map_file;
	t_flags		flags;
	t_counter	counters;
	t_sprite	hero;
	t_sprite	*patrol;
	t_sprite	exit;
	t_sprite	floor;
	t_sprite	wall;
	t_sprite	*collect;
	t_path		path;
	t_quant		quant;
	char		*score;
}				t_root;

int		collision(t_sprite *element1, t_sprite *element2);
void	move_sprite(t_root *root, t_sprite *element, t_sprite *behind, \
		int direction);
void	put_sprite(t_root *root, t_sprite *sprite, size_t y, size_t x);
int		exit_game_request(t_root *root);
int		playfield_free(t_root *root);
void	set_counters(t_root *root);
void	set_flags(t_root *root);
void	set_path(t_root *root);
void	init_game(t_root *root);
void	check_playfield(t_root *root);
void	get_playfield(t_root *root);
void	flood_fill(t_root *root);
int		game_loop(t_root *root);
void	render_map(t_root *root);
void	check_move_sprite(t_root *root, int direction);
void	game_events(t_root *root);
void	check_collision_events(t_root *root);
int		game_over_sucess(t_root *root);
int		exit_game_init_error(t_root *root);
int		exit_ingame_error_(t_root *root);
int		print_error(t_root *root);
void	check_ber_file(t_root *root);
void	animation(t_root *root);
void	collect_animation(t_root *root);
void	hero_animation(t_root *root);
void	wall_animation(t_root *root);
void	exit_animation(t_root *root);

#endif
