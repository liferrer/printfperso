NAME		=	libftprintf.a

HEADER		=	lib

SRCS		=	srcs/ft_printf.c\
				srcs/ft_get_all_infos.c\
				srcs/ft_tools_precision.c\
				srcs/ft_tools_width.c\
				srcs/ft_tools.c\
				srcs/ft_types_handlers.c\
				lib/ft_atoi.c\
				lib/ft_calloc.c\
				lib/ft_itoa.c\
				lib/ft_memcmp.c\
				lib/ft_memset.c\
				lib/ft_strcat.c\
				lib/ft_strchr.c\
				lib/ft_strdup.c\
				lib/ft_strdups.c\
				lib/ft_strfjoin.c\
				lib/ft_strjoinchar.c\
				lib/ft_strlen.c\
				lib/ft_strncat.c\
				lib/ft_strnjoin.c\
				lib/ft_ultoa.c\
				lib/ft_strndup.c\

CC			=	gcc

CFLAGS		=	-Werror -Wextra -Wall

DEL			=	rm -f

OBJS		=	${SRCS:.c=.o}

$(NAME):		${OBJS}
				${CC} ${CFLAGS} -c -I ${HEADER} ${SRCS}
				ar rc ${NAME} ${OBJS}

all:			${NAME}

clean:
				${DEL} ${OBJS} *.o

fclean:			clean
				${DEL} ${NAME}

re:				fclean all

.PHONY: 		all clean fclean re