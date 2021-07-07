#include "game.h"

static void	enemy_move_LR(t_game *game, int enemy_cnt)
{
	int	enemy_x;
	int	enemy_y;
	int	index;

	index = game->enemy.enemy_xy[enemy_cnt];
	enemy_x = (index % game->map_width);
	enemy_y = (index / game->map_width);
	if (game->player.player_x < enemy_x && game->map[index - 1] == '0'
		&& game->map[index - 1] != 'Z')
	{
		game->map[index - 1] = 'Z';
		game->map[index] = '0';
		draw_tileset(game, enemy_y, enemy_x);
		game->enemy.enemy_xy[enemy_cnt]--;
	}
	else if (game->player.player_x > enemy_x && game->map[index + 1] == '0'
		&& game->map[index + 1] != 'Z')
	{
		game->map[index + 1] = 'Z';
		game->map[index] = '0';
		draw_tileset(game, enemy_y, enemy_x);
		game->enemy.enemy_xy[enemy_cnt]++;
	}
}

static void	enemy_move_UD(t_game *game, int enemy_cnt)
{
	int	enemy_x;
	int	enemy_y;
	int	index;

	index = game->enemy.enemy_xy[enemy_cnt];
	enemy_x = (index % game->map_width);
	enemy_y = (index / game->map_width);
	if (game->player.player_y < enemy_y
		&& game->map[index - game->map_width] == '0'
		&& game->map[index - game->map_width] != 'Z')
	{
		game->map[index - game->map_width] = 'Z';
		game->map[index] = '0';
		draw_tileset(game, enemy_y, enemy_x);
		game->enemy.enemy_xy[enemy_cnt] -= game->map_width;
	}
	else if (game->player.player_y > enemy_y
		&& game->map[index + game->map_width] == '0'
		&& game->map[index + game->map_width] != 'Z')
	{
		game->map[index + game->map_width] = 'Z';
		game->map[index] = '0';
		draw_tileset(game, enemy_y, enemy_x);
		game->enemy.enemy_xy[enemy_cnt] += game->map_width;
	}
}

void	enemy_move(t_game *game)
{
	int	enemy_cnt;
	int	score;

	score = game->score;
	enemy_cnt = 0;
	if (score % 4 == 0)
	{
		while (enemy_cnt < game->enemy.enemy_cnt)
			enemy_move_LR(game, enemy_cnt++);
	}
	if (score % 4 == 2)
	{
		while (enemy_cnt < game->enemy.enemy_cnt)
			enemy_move_UD(game, enemy_cnt++);
	}
}
