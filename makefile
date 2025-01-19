NAME = so_long

SRC = $(addsuffix .c, so_long render map_parsing map_utils map_checker display_map move_functions display_steps_bonus)
GNL_SRC = $(addprefix get_next_line/, get_next_line.c)


PRINTFLIB = ft_printf/libftprintf.a
PRINTFDIR = ft_printf
LIBS = -Lminilibx-linux -lmlx -lXext -lX11

OBJ := $(SRC:%.c=%.o)
BONUS_OBJ := $(BONUS_SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror -g

all: minilibx printf $(NAME)

run: re
	clear && ./so_long maps/map.ber

valgrind: re
	clear && valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./so_long maps/map.ber

$(NAME): $(OBJ) $(GNL_OBJ)
	$(CC) $(CCFLAGS) $^ $(PRINTFLIB) $(LIBS) -o $(NAME)

%.o: %.c
	gcc $(CCFLAGS) -Iincludes -c $< -o $@

printf:
	@echo Compiling ft_printf...
	@make -C $(PRINTFDIR)

minilibx:
	@echo Compiling MiniLibx...
	@make -C minilibx-linux

clean:
	@echo Cleaning object_files...
	@rm -f $(OBJ) $(GNL_OBJ) $(BONUS_OBJ)
	@make clean -C $(PRINTFDIR)

fclean: clean
	@make clean -C minilibx-linux
	@make fclean -C $(PRINTFDIR)
	@rm -rf $(NAME)

re : fclean all

.PHONY: all run valgrind printf minilibx clean fclean re