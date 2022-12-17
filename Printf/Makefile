NAME	= libftprintf.a

SRCS	= ft_numbers.c \
		ft_printf.c \
		ft_text.c 

SRCSF	=  ft_atoi.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_calloc.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_striteri.c \
		ft_bzero.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strdup.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_tolower.c \
		ft_strmapi.c \
		ft_split.c \
		ft_toupper.c 

SRCSD	=$(addprefix Libft/, $(SRCSF))

LIBFT	= Libft/libft.a

OBJS	= ${SRCS:.c=.o}

OBJSD	= ${SRCSF:.c=.o}

CC	= clang

CFLAGS 	= -Wall -Werror -Wextra
RM		= rm -rf

LIBC	= ar rcs

INCS	= ft_printf.h


${NAME}: libft.a
	cp ${LIBFT} .
	mv libft.a $(NAME)
	${CC} ${CFLAGS} -c ${SRCS} ${INCS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

test:	libft.a
	${CC} ${CFLAGS} -c ${SRCS} test.c ${INCS}
	${CC} ${CFLAGS} ${OBJS} test.o -L. ${LIBFT} -o a.out
	./a.out | cat -e
	
norm:
	python3 -m norminette ${SRCS}

clean:
	${RM} ${OBJS} ${OBJSD} 

libft.a:
	cd Libft && ${MAKE} all

lib_fclean:
	cd Libft && ${MAKE} fclean

fclean: clean lib_fclean
	${RM} ${NAME}
	
.PHONY: all, clean, fclean, re