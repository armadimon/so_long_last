#include "game.h"

static int	draw_enemy_all(t_game *game, int enemy_cnt, int sprite_cnt)
{
	if (sprite_cnt <= 40)
	{
		draw_tileset(game, game->enemy.enemy_xy[enemy_cnt] / game->map_width,
			game->enemy.enemy_xy[enemy_cnt] % game->map_width);
		draw_enemy1(game, enemy_cnt);
	}
	if (40 < sprite_cnt && sprite_cnt <= 80)
	{
		draw_tileset(game, game->enemy.enemy_xy[enemy_cnt] / game->map_width,
			game->enemy.enemy_xy[enemy_cnt] % game->map_width);
		draw_enemy2(game, enemy_cnt);
	}
	if (80 < sprite_cnt && sprite_cnt < 120)
	{
		draw_tileset(game, game->enemy.enemy_xy[enemy_cnt] / game->map_width,
			game->enemy.enemy_xy[enemy_cnt] % game->map_width);
		draw_enemy3(game, enemy_cnt);
	}
	else if (sprite_cnt == 120)
		sprite_cnt = 0;
	return (sprite_cnt);
}

int	draw_enemy(t_game *game, int sprite_cnt)
{
	int	enemy_cnt;

	enemy_cnt = 0;
	while (enemy_cnt < game->enemy.enemy_cnt)
	{
		sprite_cnt = draw_enemy_all(game, enemy_cnt, sprite_cnt);
		enemy_cnt++;
	}
	return (sprite_cnt);
}

void	get_enemy_xy(t_game *game, int i, int j)
{
	int	enemy_cnt;

	enemy_cnt = game->enemy.enemy_cnt_ori;
	if (game->enemy.enemy_xy == 0)
		game->enemy.enemy_xy = (int *)malloc(sizeof(int) * enemy_cnt - 1);
	game->enemy.enemy_xy[enemy_cnt - 1] = i * game->map_width + j;
	game->enemy.enemy_cnt_ori--;
}
