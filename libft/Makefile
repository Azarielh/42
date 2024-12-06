CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_bzero.c \
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_memset.c \
		ft_memcpy.c\
		ft_calloc.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putstr_fd.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strrchr.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_strnstr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_atoi.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstmap_bonus.c\
			ft_lstsize_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
# Create a pattern rule to compile
 
%.o: %.c libft.h Makefile
	@echo 
	cc $(CFLAGS) -I . $< -c -o $@


# Create lib
${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus: 
	@echo "\n"
	$(MAKE) --no-print-directory all SRCS="$(SRCS) $(SRCS_BONUS)"  

# Clean it all up
clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f  $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
