# COLORS #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

# VARIABLES #

NAME = libftprintf.a

CC = cc

CFLAGS = -Werror -Wextra -Wall

LIBFT = libft.a

LIBFTDIR = libft

SRC = ft_printf.c ft_printf_utils.c ft_format_print.c ft_printf_utils2.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: libft $(NAME)
	@echo "\n$(COLOUR_GREEN)libftprintf.a compiled!$(COLOUR_END)\n"

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

libft:
	make -C $(LIBFTDIR)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@echo "\n$(COLOUR_BLUE)libft.a compiled!$(COLOUR_END)\n"

clean:
	make clean -C $(LIBFTDIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean libft fclean re