# Color codes
RESET      = \033[0m
RED        = \033[31m
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
MAGENTA    = \033[35m
CYAN       = \033[36m
WHITE      = \033[37m
BOLD       = \033[1m

# General info
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = ft_printf.c\
		ft_putstr.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_puthex.c\
		ft_putnbr_deci.c


OBJS = $(SRCS:.c=.o)

# Setting up an custom error message
ERROR_MSG = "$(RED)[ERROR] Compilation failed$(RESET)"

all: $(NAME)

# Check source files
check_sources:
	@for file in $(SRCS); do \
		if [ ! -f $$file ]; then \
			echo "$(RED)[ERROR] Le fichier $$file est manquant ou introuvable. Vérifiez que tous les fichiers source sont présents. $(RESET)"; \
			exit 1; \
		fi; \
	done
	@echo "$(MAGENTA)======================= START COMPILATION =======================$(RESET)"

%.o: %.c
	@echo -n "$(BLUE)$@ $(RESET)"
	@cc $(CFLAGS) -I . $< -c -o $@ && echo "  $(GREEN)>>>>>> SUCCESS $(RESET)" || { echo "$(ERROR_MSG)"; exit 1; }

$(NAME): check_sources ${OBJS} 
	@ar rc $(NAME) $(OBJS)  || { echo "$(ERROR_MSG)"; exit 1; }
	@echo "$(GREEN)======================= All recquired function for printf has been compiled =======================$(RESET)"

clean:
	@rm -f $(OBJS) && echo "$(YELLOW)======================= All object files has been removed =======================$(RESET)"

fclean: clean
	@rm -f  $(NAME) && echo "$(YELLOW)======================= $(NAME) has been removed =======================$(RESET)"
re: fclean all

.PHONY: all clean fclean re