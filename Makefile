SRCS=	file_mgmt.c parsing_ft.c util_str.c number_mgmt.c print_nbr.c main.c

OBJS=	${SRCS:.c=.o}

CC= 	gcc

CFLAGS=	-Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${OBJS}
		gcc ${OBJS}

clean:	
		rm -rf *.o

fclean: clean
		rm -rf a.out

re:	fclean all
		
.PHONY:     all clean fclean re
