# MANQUE  :
#       SUPPRIMER LIBFT.A DU DOSSIER COURANT
#           "     LIBFT.H DU DOSSIER COURANT

.PHONY: all clean fclean re

# General 
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

#___________ SRCS _____________

# LIBFT
LIBFT_DIR = includes/libft/
LIBFT_A = includes/libft/libft.a

SRC = push_swap.c\
	includes/checking/is_valid_int_list.c\
	includes/checking/has_no_double.c\
	includes/checking/is_signed_int.c\
	includes/checking/is_valid_int.c\
	includes/checking/ft_isdigit2.c\
	includes/tools/ft_strcpy.c\
	includes/tools/ft_strswap.c\
	includes/ft_atol.c\
	includes/parsing/list_to_struct.c\
	includes/sorting/swap/sa.c\
	includes/sorting/swap/sb.c\
	includes/sorting/swap/ss.c\
	includes/sorting/push/pb.c\
	includes/sorting/push/pa.c\


OBJS = $(SRC:.c=.o)

# Setting up an custom error message
ERROR_MSG = "$(RED)[ERROR] Compilation failed$(RESET)"

all: $(LIBFT) $(OBJS) $(NAME)

%.o: %.c
	@echo -n "$(BLUE) $@ $(RESET)"
	@cc $(CFLAGS) -I . $< -c -o $@ && echo "$(GREEN)>>> SUCCESS $(RESET)" || { echo "$(ERROR_MSG)"; exit 1; }

$(NAME): $(OBJS) $(LIBFT_A)
	@cc $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)======================= All push_swap required library has been compiled =======================$(RESET)"

$(LIBFT_A):
	@echo "$(YELLOW)1/  Building libft..............................................................................$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory || @echo "Issue while attempting compiling libft"
	@cp $(LIBFT_DIR)libft.a ./ && cp $(LIBFT_DIR)libft.h ./

clean:
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory clean
	@rm -f $(OBJS)

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) --no-print-directory fclean
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