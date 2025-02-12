.PHONY: all clean fclean re

# General 
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

#___________ SRCS _____________

# LIBFT
LIBFT_DIR = libft/

# PRINTF
PRINTF_DIR =printf/

SRC = pipex.c 

OBJS = $(SRC:.c=.o)

# Setting up an custom error message
ERROR_MSG = "$(RED)[ERROR] Compilation failed$(RESET)"

all: $(LIBFT) $(PRINTF) $(OBJ) $(NAME)

$(NAME): LIBFT PRINTF $(OBJS)
	@cc $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)
	@echo "$(GREEN)======================= All pipex required library has been compiled =======================$(RESET)"

%.o: %.c
	@echo -n "$(BLUE) $@ $(RESET)"
	@cc $(CFLAGS) -I . $< -c -o $@ && echo "$(GREEN)>>> SUCCESS $(RESET)" || { echo "$(ERROR_MSG)"; exit 1; }

LIBFT:
	@echo "$(YELLOW)1/  Building libft..............................................................................$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory || @echo "Issue while attempting compiling libft"

PRINTF:
	@echo "$(YELLOW)2/  Building printf..............................................................................$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR) --no-print-directory || @echo "Issue while attempting compiling printf"

clean:
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory clean
	@cd $(PRINTF_DIR) && $(MAKE) --no-print-directory clean
	@rm -f $(OBJS)

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory fclean
	@cd $(PRINTF_DIR) && $(MAKE) --no-print-directory fclean
	@rm -f $(NAME)

re: fclean all

# __________________ Color codes ___________________________

RESET      = \033[0m
RED        = \033[31m
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
MAGENTA    = \033[35m
CYAN       = \033[36m
WHITE      = \033[37m
BOLD       = \033[1m