#include "game.h"

void	draw_enemy1(t_game *game, int enemy_cnt)
{
	int	width;
	int	height;

	game->img.img = mlx_xpm_file_to_image(game->mlx,
			"image/enemy.xpm", &width, &height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.img,
		(game->enemy.enemy_xy[enemy_cnt] % game->map_width) * TILE_SIZE,
		(game->enemy.enemy_xy[enemy_cnt] / game->map_width) * TILE_SIZE);
	if (game->img.img)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = 0;
	}
}

void	draw_enemy2(t_game *game, int enemy_cnt)
{
	int	width;
	int	height;

	game->img.img = mlx_xpm_file_to_image(game->mlx,
			"image/enemy_attack.xpm", &width, &height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.img,
		(game->enemy.enemy_xy[enemy_cnt] % game->map_width) * TILE_SIZE,
		(game->enemy.enemy_xy[enemy_cnt] / game->map_width) * TILE_SIZE);
	if (game->img.img)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = 0;
	}
}

void	draw_enemy3(t_game *game, int enemy_cnt)
{
	int	width;
	int	height;

	game->img.img = mlx_xpm_file_to_image(game->mlx,
			"image/enemy_attack2.xpm", &width, &height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.img,
		(game->enemy.enemy_xy[enemy_cnt] % game->map_width) * TILE_SIZE,
		(game->enemy.enemy_xy[enemy_cnt] / game->map_width) * TILE_SIZE);
	if (game->img.img)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = 0;
	}
}

static void	draw_field_all(t_game *game, int i, int j)
{
	draw_tileset(game, i, j);
	if (game->map[(i * game->map_width) + j] == '1')
		draw_obstacle(game, i, j);
	if (game->map[(i * game->map_width) + j] == 'E')
		draw_exit(game, i, j);
	if (game->map[(i * game->map_width) + j] == 'C')
		draw_collectible(game, i, j);
	if (game->map[(i * game->map_width) + j] == 'P')
	{
		game->map[(i * game->map_width) + j] = '0';
		game->player.player_x = j;
		game->player.player_y = i;
	}
	if (game->map[(i * game->map_width) + j] == 'Z')
		get_enemy_xy(game, i, j);
}

void	draw_field(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i <= game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			draw_field_all(game, i, j);
			j++;
		}
		i++;
	}
}
