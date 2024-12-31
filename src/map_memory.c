/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:41:31 by racasado          #+#    #+#             */
/*   Updated: 2024/12/31 15:10:13 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

void	free_game(t_game *game)
{
	int			i;
	t_images	*images;

	i = 0;
	images = game->img;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->img)
	{
		if (images->background)
			mlx_destroy_image(game->mlx, images->background);
		if (images->wall)
			mlx_destroy_image(game->mlx, images->wall);
		if (images->exit)
			mlx_destroy_image(game->mlx, images->exit);
		if (images->collectable)
			mlx_destroy_image(game->mlx, images->collectable);
		if (images->player)
			mlx_destroy_image(game->mlx, images->player);
		free(images);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}
