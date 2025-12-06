GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
RESET   = \033[0m

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_DIR = my_libs/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

PRINTF_DIR = my_libs/ft_printf
PRINTF = $(PRINTF_DIR)/ft_printf.a

LIBFT_DIR = my_libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_DIR = src/
SRCS = main.c\
parser.c\
utils.c\

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS)  -c $< -o $@

all: $(NAME)

$(MLX_LIB):
	@echo "$(YELLOW)Compiling MLX library...$(RESET)"
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)✓ MLX library ready!$(RESET)"


$(NAME): $(MLX_LIB) $(PRINTF) $(OBJS)
	@if [ ! -f $(NAME) ]; then \
		echo "$(YELLOW)Linking $(NAME)...$(RESET)"; \
		$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(MLX_FLAGS) -o $(NAME); \
		echo "$(GREEN)✓ $(NAME) created!$(RESET)"; \
	else \
		if [ $(shell find $(OBJS) -newer $(NAME) 2>/dev/null | wc -l) -gt 0 ]; then \
			echo "$(YELLOW)Relinking $(NAME)...$(RESET)"; \
			$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(MLX_FLAGS) -o $(NAME); \
			echo "$(GREEN)✓ $(NAME) updated!$(RESET)"; \
		else \
			echo "$(GREEN)✓ $(NAME) is up to date!$(RESET)"; \
		fi \
	fi

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re