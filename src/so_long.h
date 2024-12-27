/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:41:27 by racasado          #+#    #+#             */
/*   Updated: 2024/12/27 13:38:57 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../42_gnl/get_next_line.h"
# include "../42_libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_game {
    void    *mlx;
    void    *win;
    void    *img;
    int     img_width;
    int     img_height;
} t_game;

char	**read_map_to_array(char *file);
int		is_map_rectangular(char **map);
char	**free_map(char **map);
int		is_map_closed(char **map);
void	show_each_map_letter(char **map);
int		is_map_valid_components(char **map);
int		is_valid_path(char **map);
int    close_window(t_game *game);
int    init_window(t_game *game);

#endif