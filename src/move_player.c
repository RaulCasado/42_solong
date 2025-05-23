/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:12:48 by racasado          #+#    #+#             */
/*   Updated: 2025/01/14 13:17:04 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, void *param)
{
	t_game		*game;
	t_position	player_pos;

	game = (t_game *)param;
	player_position(game->map, &player_pos.x, &player_pos.y);
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 119 || keycode == 65362)
		player_move(game, player_pos, (t_position){0, -1});
	else if (keycode == 115 || keycode == 65364)
		player_move(game, player_pos, (t_position){0, 1});
	else if (keycode == 97 || keycode == 65361)
		player_move(game, player_pos, (t_position){-1, 0});
	else if (keycode == 100 || keycode == 65363)
		player_move(game, player_pos, (t_position){1, 0});
	draw_map(game, game->img, game->map);
	return (0);
}

void	player_move(t_game *game, t_position pos, t_position delta)
{
	char	next_cell;

	next_cell = game->map[pos.y + delta.y][pos.x + delta.x];
	if (next_cell == '1')
		return ;
	if (next_cell == 'C')
		game->collectable_count--;
	if (next_cell == 'E')
	{
		if (game->collectable_count == 0)
		{
			ft_putstr_fd("Congratulations! You won!\n", 1);
			close_window(game);
		}
	}
	if (game->original_map[pos.y][pos.x] != 'E')
		game->map[pos.y][pos.x] = '0';
	else
		game->map[pos.y][pos.x] = 'E';
	game->map[pos.y + delta.y][pos.x + delta.x] = 'P';
	game->move_count++;
	ft_putstr_fd("Move count: ", 1);
	ft_putnbr_fd(game->move_count, 1);
	ft_putchar_fd('\n', 1);
}
