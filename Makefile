SRCS = ft_printf.c

HEAD = printf.h
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean : 
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re