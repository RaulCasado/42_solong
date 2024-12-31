/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:32:10 by racasado          #+#    #+#             */
/*   Updated: 2024/12/31 12:19:32 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
}

int	init_window(t_game *game, char **map)
{
	t_images	*images;
	int		map_width, map_height;

	map_width = 0;
	map_height = 0;
	while (map[map_height])
		map_height++;
	while (map[0][map_width])
		map_width++;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);

	game->win = mlx_new_window(game->mlx, map_width * TILE_SIZE, map_height * TILE_SIZE, "so_long");
	if (!game->win)
		return (0);

	images = load_images(game);
	if (!images)
		return (0);

	draw_map(game, images, map);

	game->map = duplicate_map(map);
	if (!game->map)
	{
		write(2, "Error al duplicar el mapa.\n", 26);
		return (0);
	}
    game->img = images;
    game->collectable_count = count_collectibles(map);
    game->move_count = 0;

	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);

	return (1);
}

