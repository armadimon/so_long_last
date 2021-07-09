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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	if (ft_strlen(big) < len)
		len = ft_strlen(big);
	while (i < len)
	{
		j = 0;
		while ((little[j] == big[i + j]) && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_map_list(t_game *game, t_list *map_buffer, int fd)
{
	t_list	*new;
	char	*line;
	int		valid;
	int	i;

	i = 0;
	valid = get_next_line(fd, &line);
	if (valid == -1)
		return (0);
	while (valid)
	{
		new = ft_lstnew(ft_strdup(line));
		ft_lstadd_back(&map_buffer, new);
		free(line);
		valid = get_next_line(fd, &line);
		i++;
	}
	if (valid == -1)
		return (0);
	new = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(&map_buffer, new);
	free(line);
	game->map_height = i;
	return (1);
}

t_list	*read_map(t_game *game, t_list *map_buffer, char *argv)
{
	int	fd;

	if (ft_strnstr(argv, ".ber", 4) == 0)
		return (0);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	if (get_map_list(game, map_buffer, argv) < 0)
		return (0);
	close(fd);
	return (map_buffer);
}

int	game_init(t_game *game, t_list *map_buffer, char *argv)
{
	map_buffer = read_map(game, map_buffer, argv);
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

