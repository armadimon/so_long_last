#include "game.h"

int	handle_score(t_game *game)
{
	game->score++;
	mlx_string_put(game->mlx, game->win,
		game->map_width * TILE_SIZE + 110, 20, 0x000000, game->str_score);
	if (game->str_score[0] != '0')
		free(game->str_score);
	game->str_score = ft_itoa(game->score);
	mlx_string_put(game->mlx, game->win,
		game->map_width * TILE_SIZE + 110, 20, 0xFFFFFF, game->str_score);
	return (0);
}

int	handle_collect(t_game *game)
{
	game->map_data.cnt_C--;
	mlx_string_put(game->mlx, game->win,
		game->map_width * TILE_SIZE + 110, 40, 0x000000, game->map_data.str_C);
	if (game->map_data.str_C[0] != '0')
		free(game->map_data.str_C);
	game->map_data.str_C = ft_itoa(game->map_data.cnt_C);
	mlx_string_put(game->mlx, game->win,
		game->map_width * TILE_SIZE + 110, 40, 0xFFFFFF, game->map_data.str_C);
	return (0);
}

int	draw_str(t_game *game)
{
	mlx_string_put(game->mlx, game->win,
		game->map_width * TILE_SIZE + 10, 20, 0xFFFFFF, "Score   :");
	mlx_string_put(game->mlx, game->win,
		game->map_width * TILE_SIZE + 110, 20, 0xFFFFFF, game->str_score);
	mlx_string_put(game->mlx, game->win,
		game->map_width * TILE_SIZE + 10, 40, 0xFFFFFF, "Collect :");
	game->map_data.str_C = ft_itoa(game->map_data.cnt_C);
	mlx_string_put(game->mlx, game->win,
		game->map_width * TILE_SIZE + 110, 40, 0xFFFFFF, game->map_data.str_C);
	return (0);
}
