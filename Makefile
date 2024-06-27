SRCS = ft_printf.c utils.c write_letters.c write_numbers.c write_ptr.c main.c

HEAD = ft_printf.h
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
ARCHIVER = ar
ARCHIVER_FLAGS = rc
ARCHIVE_INDEX = ranlib

all : ${NAME}

${NAME} : ${OBJS}
	${ARCHIVER} ${ARCHIVER_FLAGS} ${NAME} ${OBJS}
	${ARCHIVE_INDEX} ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean : 
	${RM} ${OBJS} 

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re