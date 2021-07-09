#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_list	*map_buffer = 0;

	map_buffer = 0;
	if (argc != 2)
	{
		write(2, "Error\n : ARG_ERROR\n", 20);
		exit (0);
	}
	reset_data(&game);
	if (!game_init(&game, map_buffer, argv[1]))
	{
		write(2, "Error\n : MAP_ERROR\n", 20);
		exit (0);
	}
	window_init(&game);
	draw_field(&game);
	draw_str(&game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_key_hook(game.win, user_move, &game);
	mlx_hook(game.win, 17, 0, &key_press_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
