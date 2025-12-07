# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 by ccakir                    #+#    #+#              #
#    Updated: 2025/12/07 by ccakir                   ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

# Directories
SRCS_DIR	= srcs
LIBS_DIR	= libs
LIBFT_DIR	= $(LIBS_DIR)/libft
PRINTF_DIR	= $(LIBS_DIR)/ft_printf
MLX_DIR		= $(LIBS_DIR)/minilibx-linux

# Source files
SRCS		= $(SRCS_DIR)/main.c \
			  $(SRCS_DIR)/parser.c \
			  $(SRCS_DIR)/render.c \
			  $(SRCS_DIR)/utils.c \
			  $(SRCS_DIR)/handlers.c \
			  $(SRCS_DIR)/event_listeners.c

OBJS		= $(SRCS:.c=.o)

# Libraries
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a
MLX			= $(MLX_DIR)/libmlx.a

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I$(SRCS_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)
LDFLAGS		= -L$(LIBFT_DIR) -L$(PRINTF_DIR) -L$(MLX_DIR)
LDLIBS		= -lft -lftprintf -lmlx -lXext -lX11 -lm

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MLX) $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "$(GREEN)✓ libft built!$(RESET)"

$(PRINTF):
	@echo "$(GREEN)Building ft_printf...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR) --no-print-directory
	@echo "$(GREEN)✓ ft_printf built!$(RESET)"

$(MLX):
	@echo "$(GREEN)Building minilibx...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory
	@echo "$(GREEN)✓ minilibx built!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
	@echo "$(RED)✓ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)Cleaning executables and libraries...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory
	@echo "$(RED)✓ All cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
