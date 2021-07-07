/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juahn <juahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:05:02 by juahn             #+#    #+#             */
/*   Updated: 2021/06/05 17:05:03 by juahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_nl(char *backup)
{
	int	index;

	if (!backup)
		return (-1);
	index = 0;
	while (backup[index] != 0)
	{
		if (backup[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

static int	get_line_on_nl(char **backup, char **line, int nl_index)
{
	char	*temp;

	(*backup)[nl_index] = '\0';
	*line = ft_strdup(*backup);
	if ((*backup + nl_index + 1) == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + nl_index + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

static int	get_line(char **backup, char **line, int nl_index)
{
	if (nl_index >= 0)
		return (get_line_on_nl(backup, line, nl_index));
	if (nl_index == -1)
	{
		if (*backup)
		{
			*line = *backup;
			*backup = 0;
			return (0);
		}
		*line = ft_strdup("");
		*backup = 0;
		return (0);
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				nl_index;
	int				size;

	nl_index = -1;
	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while (nl_index == -1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (-1);
		buf[size] = 0;
		backup[fd] = ft_strjoin(backup[fd], buf);
		nl_index = check_nl(backup[fd]);
		if (nl_index >= 0 || size == 0)
			return (get_line(&backup[fd], line, nl_index));
	}
	return (get_line(&backup[fd], line, nl_index));
}
