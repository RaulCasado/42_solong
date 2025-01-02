/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raul <raul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:41:27 by racasado          #+#    #+#             */
/*   Updated: 2025/01/02 10:50:33 by raul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64

# include "../42_gnl/get_next_line.h"
# include "../42_libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

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
	char	**original_map;

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
	int		x;
	int		y;
}			t_position;

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

#endif