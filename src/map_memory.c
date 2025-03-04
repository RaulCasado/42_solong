/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:41:31 by racasado          #+#    #+#             */
/*   Updated: 2025/03/04 13:56:08 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_map(char **map)
{
	int	i;

	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

void	free_images(t_game *game, t_images *images)
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

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->original_map)
		free_map(game->original_map);
	if (game->img)
		free_images(game, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

void	free_game_error(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
	free(game);
}
