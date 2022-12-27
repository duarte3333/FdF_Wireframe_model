NAME = fdf

CC = cc

CFLAGS = -O3 -Wall -Wextra -Werror -fsanitize=address -g

SRCS = main.c \
	  get_next_line.c \
	  read_map.c \
	  draw_grid.c \
	  color.c \
	  keys_managment.c \
	  transformations.c \
	  menu.c \
	  screen.c \
	  map_to_point.c \
	  rotations.c

OBJS	= ${SRCS:.c=.o}

LIB_MINILIBX = -Lminilibx -lmlx -lXext -lX11 -lm -lz 
LIB_LIBFT	= Libft/libft.a

MINILIBX = minilibx/
LIBFT = Libft/

all: $(NAME) lib

$(NAME): $(OBJS) lib
	$(CC) $(CFLAGS) $(OBJS) $(LIB_MINILIBX) $(LIB_LIBFT) -o $(NAME)

lib:
	make -C $(MINILIBX)
	make -C $(LIBFT)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	make clean -C ${MINILIBX}
	make fclean -C ${LIBFT}

re: fclean all