/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:43:00 by racasado          #+#    #+#             */
/*   Updated: 2024/12/31 12:18:04 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill_start_from_exit(char **map_copy, char **map)
{
	int x, y;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				flood_fill(map_copy, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	check_unreachable_from_exit(char **map_copy, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map_copy[i], 'C'))
		{
			free_map(map_copy);
			return (0);
		}
		i++;
	}
	free_map(map_copy);
	return (1);
}

int	are_collectibles_blocked_by_exit(char **map)
{
	char	**map_copy;
	int		result;

	map_copy = duplicate_map(map);
	if (!map_copy)
		return (0);
	flood_fill_start_from_exit(map_copy, map);
	result = check_unreachable_from_exit(map_copy, map);
	return (result);
}
