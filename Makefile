NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

LIBFT_DIR = 42_libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = 42_gnl
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)
INCLUDES = -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(SRC_DIR) -I/usr/include

# Añadir minilibx para Linux
MLX = -lmlx_Linux -lXext -lX11 -lm -lz

LIBS = $(LIBFT) $(MLX)

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/init_map.c $(SRC_DIR)/map_checker.c $(SRC_DIR)/map_memory.c $(SRC_DIR)/has_valid_exit.c \
			$(SRC_DIR)/map_checker_utils.c $(SRC_DIR)/init_window.c $(SRC_DIR)/player_position.c $(SRC_DIR)/images_draw.c \
			$(SRC_DIR)/move_player.c $(SRC_DIR)/collectibles.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(GNL_OBJS) $(LIBS)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(GNL_OBJS)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

norm:
	norminette $(SRCS) $(LIBFT_DIR) $(GNL_DIR)

.PHONY: all clean fclean re
