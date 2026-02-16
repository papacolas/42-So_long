# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 16:57:09 by ncrivell          #+#    #+#              #
#    Updated: 2025/04/10 18:06:43 by ncrivell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BLUE = \033[34m
GREEN = \033[32m
RESET = \033[0m

SRC =	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset \
		ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper \
		ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
		ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim \
		ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd \
		ft_putstr_fd ft_putendl_fd ft_putnbr_fd
SRCBONUS = ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus \
			ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus \
			ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus
OBJBONUS = $(SRCBONUS:%=%.o)
OBJ = $(SRC:%=%.o)
FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ): %.o: %.c
	@echo "$(BLUE)compiling$(RESET) : $<"
	@cc $(FLAGS) -c $< -o $@

bonus: $(OBJ) $(OBJBONUS)
	@ar rcs $(NAME) $(OBJ) $(OBJBONUS)

$(OBJBONUS): %.o: %.c
	@echo "$(BLUE)compiling$(RESET) : $<"
	@cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus clean fclean all re
