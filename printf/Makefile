# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 14:52:45 by codespace         #+#    #+#              #
#    Updated: 2025/01/13 12:56:08 by jlacaze-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET      = \033[0m
RED        = \033[31m
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
MAGENTA    = \033[35m
CYAN       = \033[36m
WHITE      = \033[37m
BOLD       = \033[1m

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c

all: $(NAME)

%.o: %.c printf.h
	@cc $(CFLAGS) -I . $< -c -o $@

$(NAME): $(OBJS)
	@echo "$(BLUE)LIBFT >>>>>>>$(RESET)"
	@$(MAKE) --no-print-directory -C ./libft
	@cp libft/libft.a $(NAME) && echo "$(BLUE)libft.a has been copied into prinf directory as $(NAME)$(RESET)"
	@echo "$(GREEN)$(BOLD)libft$(RESET)$(GREEN) is now implemented in $(NAME)$(GREEN)"
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@$(MAKE) --no-print-directory -C libft clean

fclean: clean
	rm -f $(NAME)	
re: fclean all

.PHONY: all clean fclean re