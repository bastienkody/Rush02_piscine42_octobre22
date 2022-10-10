SRCS=	main.c file_mgmt.c parsing.c number_mgmt.c comp_nbr.c find_dict_ft.c util_str.c

OBJS=	${SRCS:.c=.o}

EXEC=	rush-02

CC= 	gcc

CFLAGS=	-Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${OBJS}
		gcc -o ${EXEC} ${OBJS}

clean:	
		rm -rf *.o

fclean: clean
		rm -rf ${EXEC}

re:	fclean all
		
.PHONY:     all clean fclean re
