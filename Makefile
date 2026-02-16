# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 17:28:13 by ncrivell          #+#    #+#              #
#    Updated: 2025/04/10 18:11:06 by ncrivell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

CC = gcc

# Chemin de las bibliotecas
LIBFTDIR = ./libft
MINILIBXDIR = ./minilibx-linux
LIBFT = $(LIBFTDIR)/libft.a
MINILIBX = $(MINILIBXDIR)/libmlx.a

# Flogos de la compilacion
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIBFTDIR) -I$(MINILIBXDIR)

# Flogos tambien, mais de liaison
LDFLAGS = -L$(LIBFTDIR) -lft -L$(MINILIBXDIR) -lmlx -lXext -lX11 -lm

# Codes couleur
BLUE = \033[34m
GREEN = \033[32m
RESET = \033[0m

SRC =	src/main/main.c \
		src/enemies/enemy.c  \
		src/enemies/utils_enemy.c \
		src/hooks/hooks_exit.c \
		src/hooks/hooks_collisions.c \
		src/hooks/hooks_mouv.c \
		src/structures/struct_init.c \
		get_next_line/gnl.c \
		src/texture/textures.c \
		src/texture/print_textures.c \
		src/maps/map.c \
		src/maps/check_map.c \
		src/maps/map_utils2.c \
		src/maps/map_utils.c

SRC_BONUS =	src_bonus/main_bonus/main_bonus.c \
			src_bonus/main_bonus/count_moves_bonus.c \
			src_bonus/enemies_bonus/enemy_bonus.c  \
			src_bonus/enemies_bonus/utils_enemy_bonus.c \
			src_bonus/enemies_bonus/alternate_bonus.c \
			src_bonus/hooks_bonus/hooks_exit_bonus.c \
			src_bonus/hooks_bonus/hooks_collisions_bonus.c \
			src_bonus/hooks_bonus/hooks_mouv_bonus.c \
			src_bonus/structures_bonus/struct_init_bonus.c \
			get_next_line/gnl.c \
			src_bonus/texture_bonus/textures_bonus.c \
			src_bonus/texture_bonus/print_textures_bonus.c \
			src_bonus/maps_bonus/map_bonus.c \
			src_bonus/maps_bonus/check_map_bonus.c \
			src_bonus/maps_bonus/map_utils2_bonus.c \
			src_bonus/maps_bonus/map_utils_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)


all: $(LIBFT) $(MINILIBX) $(NAME)

bonus: $(LIBFT) $(MINILIBX) $(BONUS_NAME)
#compilacion des los bibliotecas
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME) 2>&1 || (echo "$(RED)Compilation error!$(RESET)" && exit 1)
	@echo "$(GREEN)--------------------------------------------------$(RESET)"
	@echo "$(GREEN)The program has successfully compiled! Now Enjoy !$(RESET)"
	@echo "$(GREEN)--------------------------------------------------$(RESET)"


$(BONUS_NAME): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LDFLAGS) -o $(BONUS_NAME) 2>&1 || (echo "$(RED)Compilation error!$(RESET)" && exit 1)
	@echo "$(GREEN)--------------------------------------------------------$(RESET)"
	@echo "$(GREEN)The program bonus has successfully compiled! Now Enjoy !$(RESET)"
	@echo "$(GREEN)--------------------------------------------------------$(RESET)"

# Règle pour libft
$(LIBFT):
	@echo "$(BLUE)~~~~~~~~Compiling the famous libft...~~~~~~~~$(RESET)"
	@$(MAKE) -C $(LIBFTDIR) --no-print-directory || (echo "$(RED)/!\ Error compiling libft! /!\$(RESET)" && exit 1)

# Règle pour minilibx
$(MINILIBX):
	@echo "$(BLUE)~~~~~~~~Compiling now the miiiiiinilibx...~~~~~~~~$(RESET)"
	@$(MAKE) -C $(MINILIBXDIR) --no-print-directory 1>/dev/null || (echo "$(RED)Error compiling minilibx!$(RESET)" && exit 1)

%.o: %.c
	@echo "$(BLUE)compiling$(RESET) : $<"
	@$(CC) $(CFLAGS) -c $< -o $@ 2>&1 || (echo "$(RED)/!\ Error compiling /!\ $<$(RESET)" && exit 1)

clean:
	@echo "$(BLUE)~~~~~~~~Cleaning object files...~~~~~~~~$(RESET)"
	@rm -f $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFTDIR) clean --no-print-directory > /dev/null
	@$(MAKE) -C $(MINILIBXDIR) clean --no-print-directory > /dev/null

fclean: clean
	@echo "$(BLUE)~~~~~~~~Cleaning executable...~~~~~~~~$(RESET)"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean --no-print-directory > /dev/null
	@echo "$(GREEN)---------------------------$(RESET)"
	@echo "$(GREEN)Project completely cleaned!$(RESET)"
	@echo "$(GREEN)---------------------------$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
