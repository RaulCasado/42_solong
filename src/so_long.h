/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:41:27 by racasado          #+#    #+#             */
/*   Updated: 2024/12/31 12:18:11 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64

# include "../42_gnl/get_next_line.h"
# include "../42_libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	char	**map;
	int		move_count;
	int		collectable_count;

}			t_game;

typedef struct s_images
{
	void	*background;
	void	*wall;
	void	*exit;
	void	*collectable;
	void	*player;
}			t_images;

char		**read_map_to_array(char *file);
int			is_map_rectangular(char **map);
char		**free_map(char **map);
int			is_map_closed(char **map);
void		show_each_map_letter(char **map);
int			is_map_valid_components(char **map);
int			is_valid_path(char **map);
int			close_window(t_game *game);
int			init_window(t_game *game, char **map);
void		show_each_map_letter(char **map);
t_images	*load_images(t_game *game);
void		draw_map(t_game *game, t_images *images, char **map);
void		player_position(char **map, int *player_x, int *player_y);
char		**duplicate_map(char **map);
int			count_collectibles(char **map);
int			key_hook(int keycode, void *param);
void		player_move(t_game *game, int x, int y, int dx, int dy);
void		free_game(t_game *game);
void		flood_fill(char **map, int x, int y);
int			are_collectibles_blocked_by_exit(char **map);

#endif