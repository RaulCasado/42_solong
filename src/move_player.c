/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:12:48 by racasado          #+#    #+#             */
/*   Updated: 2024/12/31 15:06:41 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int key_hook(int keycode, void *param)
{
	t_game *game = (t_game *)param;
	int player_x = 0;
	int player_y = 0;

	player_position(game->map, &player_x, &player_y);

	if (keycode == 65307)
		close_window(game);

	if (keycode == 119 || keycode == 65362)
		player_move(game, player_x, player_y, 0, -1);
	else if (keycode == 115 || keycode == 65364)
		player_move(game, player_x, player_y, 0, 1);
	else if (keycode == 97 || keycode == 65361)
		player_move(game, player_x, player_y, -1, 0);
	else if (keycode == 100 || keycode == 65363)
		player_move(game, player_x, player_y, 1, 0);

	draw_map(game, game->img, game->map);

	return (0);
}

void player_move(t_game *game, int x, int y, int dx, int dy)
{
	char next_cell = game->map[y + dy][x + dx];

	if (next_cell == '1')
		return;

	if (next_cell == 'C')
		game->collectable_count--;

	if (next_cell == 'E')
	{
		if (game->collectable_count == 0)
			close_window(game);
		else
			return;
	}

	game->map[y][x] = '0';
	game->map[y + dy][x + dx] = 'P';
	game->move_count++;
	ft_putnbr_fd(game->move_count, 1);
	ft_putchar_fd('\n', 1);
}