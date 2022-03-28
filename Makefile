NAME = so_long

HEADER = so_long.h

RM = rm -f

CFLAGS = -Werror -Wextra -Wall -Imlx -g 

CC = gcc

LIBFT = libraries/libft/libft.a

MLX = libraries/mlx/libmlx.dylib

SRCS = src/so_long.c src/read_map.c src/draw_map.c src/error_check.c \
	src/initialize_xpm.c src/input.c src/animation.c \
	src/draw_map2.c src/enemy.c src/initialize_alivies.c

OBJS = $(SRCS:%.c=%.o)

all: $(LIBFT) $(MLX) $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT):
	$(MAKE) -C libraries/libft

$(MLX):
	$(MAKE) -C libraries/mlx && test -e libmlx.dylib || ln -sf libraries/mlx/libmlx.dylib libmlx.dylib

$(NAME): $(MLX) $(LIBFT) $(OBJS) 
	$(CC) $^ -o $(NAME)

clean:
	@make clean -C libraries/libft
	@make clean -C libraries/mlx
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -f libmlx.dylib
	@echo Los Deletos

fclean: clean
	@rm -f $(MLX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	
re:	fclean all

.PHONY: all clean fclean re