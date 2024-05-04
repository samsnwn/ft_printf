SRCS = ft_printf.c

HEAD = ft_printf.h
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I./libft

all : libft ${NAME}

libft :
	make -C ./libft

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean : 
	${RM} ${OBJS}

fclean : clean
	make -C ./libft fclean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re libft