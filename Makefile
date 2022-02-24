NAME = so_long

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

INC = Mandatory/so_long.h Mandatory/gnl/get_next_line.h

B_INC = Bonus/so_long_bonus.h Bonus/gnl/get_next_line.h

SRC_FILES = so_long.c map_checker.c draw.c play.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c

B_SRC_FILES = so_long_bonus.c map_checker_bonus.c draw_bonus.c \
			play_bonus.c update_bonus.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c

SRC = $(addprefix Mandatory/, $(SRC_FILES))

B_SRC = $(addprefix Bonus/, $(B_SRC_FILES))

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(INC)
	cc $(FLAGS) $(OBJ) -o $(NAME)

.c.o : $(SRC) $(B_SRC) $(INC) $(B_INC)
		cc -c $< -o $(<:.c=.o)

bonus: $(B_OBJ) $(B_INC)
	cc $(FLAGS) $(B_OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
