/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raul <raul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:32:10 by racasado          #+#    #+#             */
/*   Updated: 2024/12/30 14:01:22 by raul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int key_hook(int keycode, void *param)
{
    t_game *game = (t_game *)param; // Convertir void * a t_game *

    int player_x = 0;
    int player_y = 0;

    show_each_map_letter(game->map);  // Usamos game->map, que está en t_game
    player_position(game->map, &player_x, &player_y);
    printf("player_x: %d\n", player_x);
    printf("player_y: %d\n", player_y);
    printf("keycode: %d\n", keycode);

    if (keycode == 65307)
        close_window(game);

    if (keycode == 119 || keycode == 65362)
    {
        if (game->map[player_y - 1][player_x] != '1')
        {
            game->map[player_y][player_x] = '0';
            game->map[player_y - 1][player_x] = 'P';
        }
    }
    else if (keycode == 115 || keycode == 65364)
    {
        if (game->map[player_y + 1][player_x] != '1')
        {
            game->map[player_y][player_x] = '0';
            game->map[player_y + 1][player_x] = 'P';
        }
    }
    else if (keycode == 97 || keycode == 65361)
    {
        if (game->map[player_y][player_x - 1] != '1')
        {
            game->map[player_y][player_x] = '0';
            game->map[player_y][player_x - 1] = 'P';
        }
    }
    else if (keycode == 100 || keycode == 65363)
    {
        if (game->map[player_y][player_x + 1] != '1')
        {
            game->map[player_y][player_x] = '0';
            game->map[player_y][player_x + 1] = 'P';
        }
    }

    return (0);
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

	// Duplicar el mapa y guardarlo en t_game
	game->map = duplicate_map(map);
	if (!game->map)
	{
		write(2, "Error al duplicar el mapa.\n", 26);
		return (0);
	}

	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);

	return (1);
}

