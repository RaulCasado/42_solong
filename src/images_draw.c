/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raul <raul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:47:51 by raul              #+#    #+#             */
/*   Updated: 2024/12/30 12:54:58 by raul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_images	*load_images(t_game *game)
{
	t_images	*images;

	images = malloc(sizeof(t_images));
	if (!images)
		return (NULL);
	images->background = mlx_xpm_file_to_image(game->mlx,
			"textures/background.xpm", &game->img_width, &game->img_height);
	images->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->img_width, &game->img_height);
	images->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->img_width, &game->img_height);
	images->collectable = mlx_xpm_file_to_image(game->mlx,
			"textures/collectable.xpm", &game->img_width, &game->img_height);
	images->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->img_width, &game->img_height);
	if (!images->background || !images->wall || !images->exit
		|| !images->collectable || !images->player)
	{
		free(images);
		return (NULL);
	}
	return (images);
}

void	draw_map(t_game *game, t_images *images, char **map)
{
	int i;
    int j;
	int x;
    int y;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, images->wall, x,
					y);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, images->exit, x,
					y);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					images->collectable, x, y);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, images->player, x,
					y);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					images->background, x, y);
			j++;
		}
		i++;
	}
}
