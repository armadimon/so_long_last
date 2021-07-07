#include "game.h"

int	user_move(int key_code, t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = game->player.player_x;
	player_y = game->player.player_y;
	if (key_code == 53)
		key_press_exit(game);
	if (key_code == 126
		&& !(game->map[((player_y - 1) * game->map_width) + player_x] == '1'))
		key_press_up(game, player_y, player_x);
	if (key_code == 125
		&& !(game->map[((player_y + 1) * game->map_width) + player_x] == '1'))
		key_press_down(game, player_y, player_x);
	if (key_code == 123
		&& !(game->map[player_y * game->map_width + player_x - 1] == '1'))
		key_press_left(game, player_y, player_x);
	if (key_code == 124
		&& !(game->map[player_y * game->map_width + player_x + 1] == '1'))
		key_press_right(game, player_y, player_x);
	return (0);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			(game->map_width + 5) * TILE_SIZE,
			(game->map_height + 1) * TILE_SIZE, "so_long");
}

int	main_loop(t_game *game)
{
	static int	sprite_cnt;

	draw_player(game);
	sprite_cnt = draw_enemy(game, sprite_cnt);
	sprite_cnt++;
	return (0);
}
