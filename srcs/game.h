#ifndef GAME_H
# define GAME_H

# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include "../utils/etc.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"

# define TILE_SIZE 32

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_map_data
{
	int		cnt_P;
	char	*str_C;
	int		cnt_E;
	int		cnt_C;
}				t_map_data;

typedef struct s_player
{
	int		player_x;
	int		player_y;
	int		pos_left;
	int		size_l;
	int		bpp;
	int		endian;
}				t_player;

typedef struct s_enemy
{
	int		*enemy_xy;
	int		enemy_cnt;
	int		enemy_cnt_ori;
}				t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			score;
	char		*str_score;
	t_map_data	map_data;
	t_img		img;
	t_player	player;
	t_enemy		enemy;
	int			map_width;
	int			map_height;
	char		*map;
}				t_game;

int		parse_map(t_game *game, t_list *map_buffer);
int		check_top_bottom_line(t_list *map_buffer);
int		check_left_right_line(t_game *game, t_list *map_buffer);
int		check_valid(t_list *map_buffer);
void	window_init(t_game *game);
int		user_move(int key_code, t_game *game);
int		close_game(t_game *game);
int		deal_key(int key_code, t_game *game);
void	draw_field(t_game *game);
void	draw_exit(t_game *game, int i, int j);
void	draw_player(t_game *game);
void	draw_obstacle(t_game *game, int i, int j);
void	draw_tileset(t_game *game, int i, int j);
void	draw_collectible(t_game *game, int i, int j);
int		draw_enemy(t_game *game, int sprite_cnt);
void	draw_enemy1(t_game *game, int enemy_cnt);
void	draw_enemy2(t_game *game, int enemy_cnt);
void	draw_enemy3(t_game *game, int enemy_cnt);
void	get_enemy_xy(t_game *game, int i, int j);
void	enemy_move(t_game *game);
int		draw_str(t_game *game);
int		key_press_up(t_game *game, int player_y, int player_x);
int		key_press_down(t_game *game, int player_y, int player_x);
int		key_press_left(t_game *game, int player_y, int player_x);
int		key_press_right(t_game *game, int player_y, int player_x);
int		key_press_exit(t_game *game);
int		handle_score(t_game *game);
int		handle_collect(t_game *game);
int		main_loop(t_game *game);

#endif