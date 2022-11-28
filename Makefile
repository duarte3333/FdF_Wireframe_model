NAME := test

CC := gcc

CFLAGS := -O2 -Wall -Wextra #-Werror

SOURCE := main.c \
	  get_next_line.c

OBJS	= ${SRCS:.c=.o}

LIB_MINILIBX := -Lminilibx -lmlx -lXext -lX11 -lm -lz 
LIB_LIBFT	:= Libft/libft.a

MINILIBX := minilibx/
LIBFT = Libft/

LIB_NAME = fdf.a
LIBC	= ar rcs
${LIB_NAME}: ${OBJS}
	${LIBC} ${LIB_NAME} ${OBJS}

all: ${LIB_NAME}
	make -C $(MINILIBX)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SOURCE) $(LIB_MINILIBX) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		make clean -C $(LIBFT)
		rm -rf $(LIB_NAME)

re: fclean all