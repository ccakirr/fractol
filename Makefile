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
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR = my_libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), main.c parser.c utils.c render.c events.c handlers.c exit_prog.c)

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(MLX_LIB):
	@echo "$(YELLOW)Compiling MLX library...$(RESET)"
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)✓ MLX library ready!$(RESET)"


$(PRINTF):
	@echo "$(YELLOW)Compiling ft_printf...$(RESET)"
	@make -C $(PRINTF_DIR) > /dev/null 2>&1
	@echo "$(GREEN)✓ ft_printf ready!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(GREEN)✓ libft ready!$(RESET)"

$(NAME): $(MLX_LIB) $(PRINTF) $(LIBFT) $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created!$(RESET)"

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(PRINTF_DIR) clean > /dev/null 2>&1
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean > /dev/null 2>&1
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re