#include "game.h"

int	check_content(t_game *game, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			game->map_data.cnt_E++;
		if (map[i] == 'C')
			game->map_data.cnt_C++;
		if (map[i] == 'P')
			game->map_data.cnt_P++;
		i++;
	}
	if (game->map_data.cnt_E < 1)
		return (0);
	if (game->map_data.cnt_C < 1)
		return (0);
	if (game->map_data.cnt_P != 1)
		return (0);
	return (1);
}

char	*backup_map(t_game *game, t_list *map_buffer, char *map)
{
	int	i;
	int	j;

	i = 0;
	while (map_buffer)
	{
		j = 0;
		while (map_buffer->content[j])
		{
			map[(i * game->map_width) + j] = map_buffer->content[j];
			if (map[(i * game->map_width) + j] == '0'
				&& ((i * game->map_width) + j) % (ft_rand()) == 11)
			{
				map[(i * game->map_width) + j] = 'Z';
				game->enemy.enemy_cnt++;
			}
			j++;
		}
		map_buffer = map_buffer->next;
		i++;
	}
	map[(i * game->map_width) + j] = '\0';
	return (map);
}

int	parse_map(t_game *game, t_list *map_buffer)
{
	char	*map;

	if (!check_left_right_line(game, map_buffer)
		|| !check_top_bottom_line(map_buffer)
		|| !check_valid(map_buffer))
		return (0);
	map = (char *)malloc(sizeof(char)
			* ((game->map_width + 1) * (game->map_height + 1)) + 1);
	if (!map)
		return (0);
	map = backup_map(game, map_buffer, map);
	if (!check_content(game, map))
		return (0);
	game->map = map;
	game->enemy.enemy_cnt_ori = game->enemy.enemy_cnt;
	return (1);
}
