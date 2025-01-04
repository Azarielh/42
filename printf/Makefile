# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 14:52:45 by codespace         #+#    #+#              #
#    Updated: 2025/01/04 18:35:10 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c

all: $(NAME)

%.o: %.c ft_printf.h
	@cc $(CFLAGS) -I . $< -c -o $@

$(NAME): $(OBJS)
	@echo "Please wait while libft is compiling ..."
	@$(MAKE) -C ./libft
	@echo "libft compilation : SUCCESS."
	@cp libft/libft.a $(NAME) && echo "libft.a copied to $(NAME)"
	@echo "libft is now implemented in $(NAME)"
	@ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)	
re: fclean all

.PHONY: all clean fclean re