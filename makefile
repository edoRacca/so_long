NAME = so_long

SRC = $(addsuffix .c, so_long win_utils map_parsing map_utils map_checker display_map)
GNL_SRC = $(addprefix get_next_line/, get_next_line.c)

PRINTFLIB = ft_printf/libftprintf.a
PRINTFDIR = ft_printf
LIBS = -Lminilibx-linux -lmlx -lXext -lX11

OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror -g

all: minilibx printf $(NAME)

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
	@rm -f $(OBJ) $(GNL_OBJ)
	@make clean -C $(PRINTFDIR)

fclean: clean
	@make clean -C minilibx-linux
	@make fclean -C $(PRINTFDIR)
	@rm -f $(NAME)

re : fclean all

.PHONY: all run valgrind printf minilibx clean fclean re