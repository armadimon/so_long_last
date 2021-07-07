#include "game.h"

void	draw_tileset(t_game *game, int i, int j)
{
	int	width;
	int	height;

	game->img.img = mlx_xpm_file_to_image(game->mlx,
			"image/ground.xpm", &width, &height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.img, j * TILE_SIZE, i * TILE_SIZE);
	if (game->img.img)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = 0;
	}
}

void	draw_obstacle(t_game *game, int i, int j)
{
	int	width;
	int	height;

	game->img.img = mlx_xpm_file_to_image(game->mlx,
			"image/wall.xpm", &width, &height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.img, j * TILE_SIZE, i * TILE_SIZE);
	if (game->img.img)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = 0;
	}
}

void	draw_player(t_game *game)
{
	int	width;
	int	height;

	if (game->player.pos_left == 1)
		game->img.img = mlx_xpm_file_to_image(game->mlx,
				"image/player_L.xpm", &width, &height);
	else
		game->img.img = mlx_xpm_file_to_image(game->mlx,
				"image/player.xpm", &width, &height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img,
		game->player.player_x * TILE_SIZE, game->player.player_y * TILE_SIZE);
	if (game->img.img)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = 0;
	}
}

void	draw_exit(t_game *game, int i, int j)
{
	int	width;
	int	height;

	game->img.img = mlx_xpm_file_to_image(game->mlx,
			"image/exit.xpm", &width, &height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.img, j * TILE_SIZE, i * TILE_SIZE);
	if (game->img.img)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = 0;
	}
}

void	draw_collectible(t_game *game, int i, int j)
{
	int	width;
	int	height;

	game->img.img = mlx_xpm_file_to_image(game->mlx,
			"image/collectible.xpm", &width, &height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.img, j * TILE_SIZE, i * TILE_SIZE);
	if (game->img.img)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = 0;
	}
}
