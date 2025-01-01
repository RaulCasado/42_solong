/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:44:10 by racasado          #+#    #+#             */
/*   Updated: 2025/01/01 19:16:28 by racasado         ###   ########.fr       */
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

static char	*allocate_and_copy_line(char *line)
{
	char	*new_line;

	new_line = malloc(ft_strlen(line) + 1);
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, line, ft_strlen(line) + 1);
	return (new_line);
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
		map[i] = allocate_and_copy_line(line);
		free(line);
		if (!map[i])
		{
			while (i-- > 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
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
