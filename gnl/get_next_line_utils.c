/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juahn <juahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:05:26 by juahn             #+#    #+#             */
/*   Updated: 2021/06/05 17:05:27 by juahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*result;
	int		i;

	i = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (0);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	temp;

	i = 0;
	if (!dest || !src)
		return (0);
	temp = ft_strlen(src);
	if (size == 0)
		return (temp);
	while (i < temp && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (temp);
}

static size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	tem_i;

	i = 0;
	tem_i = 0;
	while (dest[i] && i < size)
		i++;
	while (src[tem_i] && (i + tem_i + 1) < size)
	{
		dest[i + tem_i] = src[tem_i];
		tem_i++;
	}
	if (i < size)
		dest[i + tem_i] = '\0';
	return (i + ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
	{
		if (!s1)
			return (ft_strdup(s2));
		else
			return (ft_strdup(s1));
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_len + 1);
	free(s1);
	ft_strlcat(result + s1_len, s2, s2_len + 1);
	return (result);
}
