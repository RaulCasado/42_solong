/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:32:10 by racasado          #+#    #+#             */
/*   Updated: 2025/01/14 11:51:48 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
}

static int	setup_mlx(t_game *game, int width, int height)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		return (0);
	return (1);
}

static int	initialize_game_resources(t_game *game, char **map)
{
	game->img = load_images(game);
	if (!game->img)
		return (0);
	draw_map(game, game->img, map);
	game->map = map;
	game->collectable_count = count_collectibles(map);
	game->move_count = 0;
	game->original_map = duplicate_map(map);
	if (!game->original_map)
		return (0);
	return (1);
}

int	init_window(t_game *game, char **map)
{
	int	map_width;
	int	map_height;

	map_width = 0;
	map_height = 0;
	while (map[map_height])
		map_height++;
	while (map[0][map_width])
		map_width++;
	if (!setup_mlx(game, map_width * TILE_SIZE, map_height * TILE_SIZE))
		return (0);
	if (!initialize_game_resources(game, map))
		return (0);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	return (1);
}
