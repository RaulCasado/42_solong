/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:47:51 by raul              #+#    #+#             */
/*   Updated: 2025/05/06 09:59:13 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images_to_null(t_images *images)
{
	images->background = NULL;
	images->wall = NULL;
	images->exit = NULL;
	images->collectable = NULL;
	images->player = NULL;
}

t_images	*load_images(t_game *game)
{
	t_images	*images;

	images = malloc(sizeof(t_images));
	if (!images)
		return (NULL);
	put_images_to_null(images);
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
		ft_putstr_fd("Error al cargar las texturas.\n", 2);
		free_images(game, images);
		return (NULL);
	}
	return (images);
}

static void	draw_tile(t_game *game, t_images *images, char tile, t_position pos)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, images->wall, pos.x,
			pos.y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, images->exit, pos.x,
			pos.y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, images->collectable,
			pos.x, pos.y);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, images->player, pos.x,
			pos.y);
	else
		mlx_put_image_to_window(game->mlx, game->win, images->background, pos.x,
			pos.y);
}

static void	draw_row(t_game *game, t_images *images, char *row, int i)
{
	int			j;
	t_position	pos;

	j = 0;
	while (row[j])
	{
		pos.x = j * TILE_SIZE;
		pos.y = i * TILE_SIZE;
		draw_tile(game, images, row[j], pos);
		j++;
	}
}

void	draw_map(t_game *game, t_images *images, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		draw_row(game, images, map[i], i);
		i++;
	}
}
