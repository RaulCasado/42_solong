/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:14:27 by racasado          #+#    #+#             */
/*   Updated: 2025/03/04 13:59:54 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	write_error(char *error, char **map)
{
	write(2, error, ft_strlen(error));
	if (map)
		free_map(map);
	return (0);
}

static int	validate_map(char **map)
{
	if (!map)
		return (write_error("Error: No se pudo cargar el mapa.\n", map));
	if (!is_map_rectangular(map))
		return (write_error("Error: El mapa no es rectangular.\n", map));
	if (!is_map_closed(map))
		return (write_error("Error: El mapa no está cerrado.\n", map));
	if (!is_map_valid_components(map))
		return (write_error("Error: El mapa contiene componentes inválidos.\n",
				map));
	if (!is_valid_path(map))
		return (write_error("Error: El mapa no tiene un camino válido.\n",
				map));
	return (1);
}

static	t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	return (game);
}

static int	handle_errors(char **map, t_game *game, int res)
{
	if (!game)
	{
		write(2, "Error: No se pudo inicializar el juego.\n", 40);
		free_map(map);
		return (EXIT_FAILURE);
	}
	if (!res)
	{
		write(2, "Error: No se pudo inicializar la ventana.\n", 41);
		free_game_error(game);
		free_map(map);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game;
	int		res;

	if (argc != 2)
		return (write(2, "Uso: ./so_long <archivo.ber>\n", 29), EXIT_FAILURE);
	map = read_map_to_array(argv[1]);
	if (!validate_map(map))
		return (EXIT_FAILURE);
	game = init_game();
	res = init_window(game, map);
	return (handle_errors(map, game, res));
}
