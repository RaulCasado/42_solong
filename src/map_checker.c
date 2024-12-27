/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:50:53 by racasado          #+#    #+#             */
/*   Updated: 2024/12/27 12:10:10 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	len_line_checker(char **map)
{
	int		i;
	size_t	line_length;

	if (!map || !map[0])
		return (0);
	line_length = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != line_length)
			return (0);
		i++;
	}
	return (1);
}

int	is_map_rectangular(char **map)
{
	if (!map || !map[0])
		return (0);
	if (!len_line_checker(map))
		return (0);
	return (1);
}

static int	count_components(char **map, int *count_c, int *count_e,
		int *count_p)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			if (map[i][j] == 'C')
				(*count_c)++;
			if (map[i][j] == 'E')
				(*count_e)++;
			if (map[i][j] == 'P')
				(*count_p)++;
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_valid_components(char **map)
{
	int	count_c;
	int	count_e;
	int	count_p;

	if (!map || !map[0])
		return (0);
	count_c = 0;
	count_e = 0;
	count_p = 0;
	if (!count_components(map, &count_c, &count_e, &count_p))
		return (0);
	if (count_c < 1 || count_e != 1 || count_p != 1)
		return (0);
	return (1);
}
