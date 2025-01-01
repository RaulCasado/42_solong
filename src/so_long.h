/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:41:27 by racasado          #+#    #+#             */
/*   Updated: 2025/01/01 20:07:41 by racasado         ###   ########.fr       */
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
	char **original_map;

}			t_game;

typedef struct s_images
{
	void	*background;
	void	*wall;
	void	*exit;
	void	*collectable;
	void	*player;
}			t_images;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

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
void		player_move(t_game *game, t_position pos, t_position delta);
void		free_game(t_game *game);
void		flood_fill(char **map, int x, int y);
int			are_collectibles_blocked_by_exit(char **map);
void	restore_exit_position(t_game *game);
void	restore_exit(t_game *game);
int	did_exit_dissapear(t_game *game);

#endif