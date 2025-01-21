NAME= so_long

SRCDIR = src/
SRC = $(addsuffix .c, so_long render map_parsing map_utils map_checker display_map move_functions)

BONUSDIR = bonus/
BONUSSRC = $(addsuffix .c, render_bonus so_long_bonus map_parsing_bonus map_utils_bonus map_checker_bonus \
		display_map_bonus move_functions_bonus so_long_utils_bonus enemy_animation_bonus)

GNL_SRC = $(addprefix get_next_line/, get_next_line.c)

SRCS = $(addprefix $(SRCDIR), $(SRC))
BSRCS = $(addprefix $(BONUSDIR), $(BONUSSRC))

PRINTFLIB = ft_printf/libftprintf.a
PRINTFDIR = ft_printf
LIBS = -Lminilibx-linux -lmlx -lXext -lX11

OBJ := $(SRCS:%.c=%.o)
BONUS_OBJ := $(BSRCS:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror -g

all: minilibx printf $(NAME)

run: re
	clear && ./so_long maps/map.ber

valgrind: re
	clear && valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./so_long maps/map.ber

bonus: minilibx printf b

b: $(BONUS_OBJ) $(GNL_OBJ)
	$(CC) $(CCFLAGS) $^ $(PRINTFLIB) $(LIBS) -o $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ)
	$(CC) $(CCFLAGS) $^ $(PRINTFLIB) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

printf:
	@echo Compiling ft_printf...
	@make -C $(PRINTFDIR)

minilibx:
	@echo Compiling MiniLibx...
	@make -C minilibx-linux

clean:
	@echo Cleaning object_files...
	@rm -rf $(OBJ) $(GNL_OBJ) $(BONUS_OBJ)
	@make clean -C $(PRINTFDIR)

fclean: clean
	@make clean -C minilibx-linux
	@make fclean -C $(PRINTFDIR)
	@rm -rf $(NAME)

re : fclean all

.PHONY: all run valgrind bonus printf minilibx clean fclean re