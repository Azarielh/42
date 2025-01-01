# Makefile for compiling printf using libft

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ../libft
PRINTF_DIR = .
OBJ_DIR = obj

# Source files
SRC = $(PRINTF_DIR)/ft_printf.c
OBJ = $(SRC:$(PRINTF_DIR)/%.c=$(OBJ_DIR)/%.o)

# Library
LIBFT = $(LIBFT_DIR)/libft.a

# Output
NAME = ft_printf

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
    $(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c
    @mkdir -p $(OBJ_DIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
    $(MAKE) -C $(LIBFT_DIR)

clean:
    rm -rf $(OBJ_DIR)
    $(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
    rm -f $(NAME)
    $(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re