/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:44:10 by racasado          #+#    #+#             */
/*   Updated: 2024/12/27 12:13:03 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	count_file_lines(int fd)
{
	size_t	lines_count;
	char	*line;

	lines_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines_count++;
		free(line);
		line = get_next_line(fd);
	}
	return (lines_count);
}

char	**remove_line_jump_end(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (map);
}

static char	**read_lines_to_map(int fd, size_t line_count)
{
	char	**map;
	char	*line;
	int		i;

	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = malloc(ft_strlen(line) + 1);
		if (!map[i])
		{
			free_map(map);
			free(line);
			return (NULL);
		}
		ft_strlcpy(map[i], line, ft_strlen(line) + 1);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

char	**read_map_to_array(char *file)
{
	int		fd;
	size_t	line_count;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line_count = count_file_lines(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = read_lines_to_map(fd, line_count);
	close(fd);
	if (!map)
		return (NULL);
	return (remove_line_jump_end(map));
}
