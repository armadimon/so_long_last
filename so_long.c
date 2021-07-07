#include "so_long.h"

void	reset_data(t_game *game)
{
	game->str_score = "0";
	game->score = 0;
	game->map_data.str_C = "0";
	game->map_data.cnt_C = 0;
	game->map_data.cnt_E = 0;
	game->map_data.cnt_P = 0;
	game->player.pos_left = 0;
	game->enemy.enemy_cnt = 0;
	game->enemy.enemy_xy = 0;
}

t_list	*read_map(t_game *game, t_list *map_buffer, int i, char *argv)
{
	int		fd;
	char	*line;
	t_list	*new;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line))
	{
		new = ft_lstnew(ft_strdup(line));
		ft_lstadd_back(&map_buffer, new);
		free(line);
		i++;
	}
	new = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(&map_buffer, new);
	game->map_height = i;
	free(line);
	close(fd);
	return (map_buffer);
}

int	game_init(t_game *game, t_list *map_buffer, char *argv)
{
	map_buffer = read_map(game, map_buffer, 0, argv);
	if (!map_buffer)
		return (0);
	if (!parse_map(game, map_buffer))
	{
		ft_lstclear(&map_buffer, free);
		return (0);
	}
	ft_lstclear(&map_buffer, free);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_list	*map_buffer;

	if (argc > 2)
		return (0);
	map_buffer = 0;
	reset_data(&game);
	if (!game_init(&game, map_buffer, argv[1]))
	{
		write(2, "Error\n : MAP_ERROR\n", 20);
		return (0);
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
