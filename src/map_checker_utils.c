/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:09:43 by racasado          #+#    #+#             */
/*   Updated: 2024/12/27 12:11:27 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_first_row(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_last_row(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_vertical_borders(char **map, size_t len)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_closed(char **map)
{
	size_t	len;
	int		row_count;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	row_count = 0;
	while (map[row_count])
		row_count++;
	if (!check_first_row(map[0]) || !check_last_row(map[row_count - 1]))
		return (0);
	if (!check_vertical_borders(map, len))
		return (0);
	return (1);
}
