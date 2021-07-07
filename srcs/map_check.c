/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:47:56 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/31 11:48:27 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	check_columns(char const *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_top_bottom_line(t_list *map_buffer)
{
	int		first_line;
	int		last_line;
	t_list	*last;

	if (!map_buffer)
		return (0);
	last = ft_lstlast(map_buffer);
	first_line = check_columns(map_buffer->content);
	last_line = check_columns(last->content);
	if (first_line == last_line)
		return (first_line);
	return (0);
}

int	check_left_right_line(t_game *game, t_list *map_buffer)
{
	int				i;
	int				left;
	int				line_len;
	int				right;

	if (!map_buffer)
		return (0);
	i = 0;
	line_len = ft_strlen(map_buffer->content);
	left = 0;
	right = 0;
	while (map_buffer)
	{
		right = ft_strlen(map_buffer->content);
		if (line_len != right)
			return (0);
		line_len = right;
		if (map_buffer->content[left] != '1'
			|| map_buffer->content[right - 1] != '1')
			return (0);
		map_buffer = map_buffer->next;
		i++;
	}
	game->map_width = line_len;
	return (i);
}

int	check_valid(t_list *map_buffer)
{
	int	i;

	while (map_buffer)
	{
		i = 0;
		while (map_buffer->content[i])
		{
			if (!ft_strchr("10PEC", map_buffer->content[i]))
				return (0);
			i++;
		}
		map_buffer = map_buffer->next;
	}
	return (1);
}
