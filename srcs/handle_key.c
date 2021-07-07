#include "game.h"

int	key_press_exit(t_game *game)
{
	free(game->enemy.enemy_xy);
	free(game->map);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

int	key_press_up(t_game *game, int player_y, int player_x)
{
	enemy_move(game);
	if (game->map[((player_y - 1) * game->map_width) + player_x] == 'E'
		|| game->map[((player_y - 1) * game->map_width) + player_x] == 'Z')
	{
		if (game->map_data.cnt_C == 0
			|| game->map[((player_y - 1) * game->map_width) + player_x] == 'Z')
			key_press_exit(game);
		if (game->map_data.cnt_C > 0)
		{
			mlx_string_put(game->mlx, game->win,
				game->map_width * TILE_SIZE + 10,
				(game->map_height) * TILE_SIZE, 0xFFFFFF, "get all food!");
			return (0);
		}
	}
	draw_tileset(game, player_y, player_x);
	if (game->map[((player_y - 1) * game->map_width) + player_x] == 'C')
	{
		game->map[((player_y - 1) * game->map_width) + player_x] = '0';
		handle_collect(game);
	}
	game->player.player_y--;
	handle_score(game);
	return (0);
}

int	key_press_down(t_game *game, int player_y, int player_x)
{
	enemy_move(game);
	if (game->map[((player_y + 1) * game->map_width) + player_x] == 'E'
		|| game->map[((player_y + 1) * game->map_width) + player_x] == 'Z')
	{
		if (game->map_data.cnt_C == 0
			|| game->map[((player_y + 1) * game->map_width) + player_x] == 'Z')
			key_press_exit(game);
		if (game->map_data.cnt_C > 0)
		{
			mlx_string_put(game->mlx, game->win,
				game->map_width * TILE_SIZE + 10,
				(game->map_height) * TILE_SIZE, 0xFFFFFF, "get all food!");
			return (0);
		}
	}
	draw_tileset(game, player_y, player_x);
	if (game->map[((player_y + 1) * game->map_width) + player_x] == 'C')
	{
		game->map[((player_y + 1) * game->map_width) + player_x] = '0';
		handle_collect(game);
	}
	game->player.player_y++;
	handle_score(game);
	return (0);
}

int	key_press_left(t_game *game, int player_y, int player_x)
{
	enemy_move(game);
	game->player.pos_left = 1;
	if (game->map[player_y * game->map_width + player_x - 1] == 'E'
		|| game->map[player_y * game->map_width + player_x - 1] == 'Z')
	{
		if (game->map_data.cnt_C == 0
			|| game->map[player_y * game->map_width + player_x - 1] == 'Z')
			key_press_exit(game);
		if (game->map_data.cnt_C > 0)
		{
			mlx_string_put(game->mlx,
				game->win, game->map_width * TILE_SIZE + 10,
				(game->map_height) * TILE_SIZE, 0xFFFFFF, "get all food!");
			return (0);
		}
	}
	draw_tileset(game, player_y, player_x);
	if (game->map[player_y * game->map_width + player_x - 1] == 'C')
	{
		game->map[player_y * game->map_width + player_x - 1] = '0';
		handle_collect(game);
	}
	game->player.player_x--;
	handle_score(game);
	return (0);
}

int	key_press_right(t_game *game, int player_y, int player_x)
{
	enemy_move(game);
	game->player.pos_left = 0;
	if (game->map[player_y * game->map_width + player_x + 1] == 'E'
		|| game->map[player_y * game->map_width + player_x + 1] == 'Z')
	{
		if (game->map_data.cnt_C == 0
			|| game->map[player_y * game->map_width + player_x + 1] == 'Z')
			key_press_exit(game);
		if (game->map_data.cnt_C > 0)
		{
			mlx_string_put(game->mlx,
				game->win, game->map_width * TILE_SIZE + 10,
				(game->map_height) * TILE_SIZE, 0xFFFFFF, "get all food!");
			return (0);
		}
	}
	draw_tileset(game, player_y, player_x);
	if (game->map[player_y * game->map_width + player_x + 1] == 'C')
	{
		game->map[player_y * game->map_width + player_x + 1] = '0';
		handle_collect(game);
	}
	game->player.player_x++;
	handle_score(game);
	return (0);
}
